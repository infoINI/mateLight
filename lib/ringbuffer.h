#ifndef mateLight_lib_ringbuffer_h
#define mateLight_lib_ringbuffer_h

#include <cstdint>

#include "allocator.h"
#include "frame.h"

namespace mateLight {
  class RingBuffer {
    public:
      static const std::size_t SIZE;

    protected:
      Allocator* allocator;
      Allocator::Ptr<Frame> data;
      std::size_t index;

    public:
      inline RingBuffer(Allocator* allocator);
      virtual inline ~RingBuffer();

      inline Frame* getFramePtr(std::size_t idx);

      Frame* getNextFrame();

    protected:
      inline std::size_t next() const;
      inline std::size_t prev() const;
  };

  inline RingBuffer::RingBuffer(Allocator *allocator)
    : allocator(allocator),
      data(allocator->alloc<Frame>(RingBuffer::SIZE)),
      index(0)
  {}

  inline Frame* RingBuffer::getFramePtr(std::size_t idx) {
    return data.getPtrOf(idx);
  }

  inline std::size_t RingBuffer::next() const {
    return (index == (RingBuffer::SIZE - 1)) ? 0 : index+1;
  }

  inline std::size_t RingBuffer::prev() const {
    return (index == 0) ? RingBuffer::SIZE - 1 : index - 1;
  }

  inline RingBuffer::~RingBuffer() {
    if(data && allocator) {
      allocator->free(data);
      data = Allocator::Ptr<Frame>();
    }
  }
}

#endif
