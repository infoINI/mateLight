#ifndef mateLight_lib_allocator_h
#define mateLight_lib_allocator_h

#include <cstdint>
#include <exception>
#include <map>
#include <memory>

namespace mateLight {
  class Allocator {
    public:
      class Info;

      template <typename T>
      class Ptr;

    protected:
      std::size_t size;
      std::uint8_t alignment;
      std::unique_ptr<std::uint8_t[]> data;
      std::size_t idCounter;
      std::map<std::size_t, Info> addressMap;

    public:
      Allocator(std::size_t size, std::uint8_t alignment = 32);

      template <typename T>
      Ptr<T> alloc(std::size_t count = 1);

      template <typename T>
      void free(Ptr<T> p);

      template <typename T>
      T* getPtr(std::size_t id, std::size_t idx = 0);
  };

  class Allocator::Info {
      friend class Allocator;
    protected:
      std::uint8_t* ptr;
      std::size_t elementSize;
      std::size_t elementCount;

    public:
      inline Info();
      inline Info(std::uint8_t* ptr, std::size_t elementSize, std::size_t elementCount = 1);
      inline Info(const Info& info);

      inline std::uint8_t* getPtr() const;
      inline std::size_t getElementSize() const;
      inline std::size_t getElementCount() const;
      inline std::size_t getSize() const;
  };

  template <typename T>
  class Allocator::Ptr {
      friend class Allocator;
    protected:
      Allocator* parent;
      std::size_t id;

    public:
      Ptr();
      Ptr(Allocator* parent, std::size_t id);
      Ptr(const Ptr& ptr);

      T* get() const;
      T* getPtrOf(std::uint32_t idx) const;

      T* operator->();
      T& operator[](std::uint32_t idx);
      const T& operator[](std::uint32_t idx) const;

      operator bool() const;
  };

  template <typename T>
  Allocator::Ptr<T> Allocator::alloc(std::size_t count) {
    std::size_t size = sizeof(T) * count;
    std::uint8_t* pos = data.get();

    for(std::pair<const std::size_t, Info>& p : addressMap) {
      // check size of free memory
      if(p.second.getPtr() - pos > size) {
        std::size_t id = ++idCounter;
        addressMap[id] = Allocator::Info(pos, sizeof(T), count);
        return Allocator::Ptr<T>(this, id);
      }

      // move pointer behind actual element
      pos = p.second.getPtr() + p.second.getSize();

      // move to next aligned pointer address
      pos += (alignment - ((pos - data.get()) % alignment));
    }

    if(this->size - (pos - data.get()) > size) {
      std::size_t id = ++idCounter;
      addressMap[id] = Allocator::Info(pos, sizeof(T), count);
      return Allocator::Ptr<T>(this, id);
    }

    return Allocator::Ptr<T>();
  }

  template <typename T>
  void Allocator::free(Allocator::Ptr<T> p) {
    addressMap.erase(addressMap.find(p.id));
  }

  template <typename T>
  T* Allocator::getPtr(std::size_t id, std::size_t idx) {
    if(addressMap.find(id) == addressMap.end()) {
      throw std::runtime_error("Id not found");
    }

    const Allocator::Info& info = addressMap[id];
    if(idx >= info.getElementCount()) {
      throw std::runtime_error("Index out of bounds");
    }

    T* p = (T*)info.getPtr();
    return (p + idx);
  }

  inline Allocator::Info::Info() 
    : ptr(nullptr),
      elementSize(0),
      elementCount(0)
  {}

  inline Allocator::Info::Info(std::uint8_t* ptr, std::size_t elementSize, std::size_t elementCount)
    : ptr(ptr),
      elementSize(elementSize),
      elementCount(elementCount)
  {}

  inline Allocator::Info::Info(const Allocator::Info& info)
    : ptr(info.ptr),
      elementSize(info.elementSize),
      elementCount(info.elementCount)
  {}

  inline std::uint8_t* Allocator::Info::getPtr() const {
    return ptr;
  }

  inline std::size_t Allocator::Info::getElementSize() const {
    return elementSize;
  }

  inline std::size_t Allocator::Info::getElementCount() const {
    return elementCount;
  }

  inline std::size_t Allocator::Info::getSize() const {
    return elementCount * elementSize;
  }

  template <typename T>
  Allocator::Ptr<T>::Ptr()
    : parent(nullptr),
      id(0)
  {}

  template <typename T>
  Allocator::Ptr<T>::Ptr(Allocator* parent, std::size_t id)
    : parent(parent),
      id(id)
  {}

  template <typename T>
  Allocator::Ptr<T>::Ptr(const Allocator::Ptr<T>& ptr)
    : parent(ptr.parent),
      id(ptr.id)
  {}

  template <typename T>
  T* Allocator::Ptr<T>::get() const {
    T* p = parent->getPtr<T>(id);

    if(!p) {
      throw std::runtime_error("invalid pointer");
    }
  
    return p;  
  }

  template <typename T>
  T* Allocator::Ptr<T>::getPtrOf(std::uint32_t idx) const {
    T* p = parent->getPtr<T>(id, idx);

    if(!p) {
      throw std::runtime_error("invalid pointer");
    }

    return p;
  }

  template <typename T>
  T* Allocator::Ptr<T>::operator->() {
    T* p = parent->getPtr<T>(id);

    if(!p) {
      throw std::runtime_error("invalid pointer");
    }

    return p;
  }

  template <typename T>
  T& Allocator::Ptr<T>::operator[](std::uint32_t idx) {
    T* p = parent->getPtr<T>(id, idx);

    if(!p) {
      throw std::runtime_error("invalid pointer");
    }

    return *p;
  }

  template <typename T>
  const T& Allocator::Ptr<T>::operator[](std::uint32_t idx) const {
    T* p = parent->getPtr<T>(id, idx);

    if(!p) {
      throw std::runtime_error("invalid pointer");
    }

    return *p;
  }

  template <typename T>
  Allocator::Ptr<T>::operator bool() const {
    return parent->getPtr<T>(id);
  }
}

#endif
