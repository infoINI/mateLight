#ifndef mateLight_lib_frame_h
#define mateLight_lib_frame_h

#include <cstdint>
#include <cstring>
#include <exception>

#include "allocator.h"
#include "color.h"

namespace mateLight {
  class Frame {
    protected:
      Allocator* allocator;
      unsigned int displayTime;
      unsigned char columnCount;
      unsigned char rowCount;
      Allocator::Ptr<Color> pixel;

    public:
      inline Frame(Allocator* allocator, std::uint8_t columnCount, std::uint8_t rowCount, std::uint32_t displayTime);
      inline Frame(const Frame& f);

      inline void setDisplayTime(std::uint32_t displayTime);

      inline Allocator::Ptr<Color> getPixel() const;

      inline void reset();
      void resize(std::uint8_t columnCount, std::uint8_t rowCount);
  };

  inline Frame::Frame(Allocator* allocator, std::uint8_t columnCount, std::uint8_t rowCount, std::uint32_t displayTime)
    : allocator(allocator),
      columnCount(columnCount),
      rowCount(rowCount),
      displayTime(displayTime)
  {
    if(!allocator) {
      throw std::runtime_error("invalid allocator");
    }

    pixel = allocator->alloc<Color>(columnCount * rowCount);
  }

  inline Frame::Frame(const Frame& f) 
    : allocator(f.allocator),
      displayTime(f.displayTime),
      columnCount(f.columnCount),
      rowCount(f.rowCount)
  {
    if(!allocator) {
      throw std::runtime_error("invalid allocator");
    }

    pixel = allocator->alloc<Color>(columnCount * rowCount);
    std::memcpy(pixel.get(), f.pixel.get(), columnCount * rowCount * sizeof(Color));
  }      

  inline void Frame::setDisplayTime(std::uint32_t displayTime) {
    this->displayTime = displayTime;
  }

  inline void Frame::reset() {
    for(int i=0; pixel && i<columnCount*rowCount;++i) {
      pixel[i].reset();
    }
  }
}

#endif
