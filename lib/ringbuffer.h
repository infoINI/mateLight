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
  };

  inline RingBuffer::RingBuffer(Allocator *allocator)
    : allocator(allocator),
      data(allocator->alloc<Frame>(RingBuffer::SIZE)),
      index(0)
  {}
}

#endif
