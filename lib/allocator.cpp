#include "allocator.h"

namespace mateLight {
  Allocator::Allocator(std::size_t size, std::uint8_t alignment)
    : size(size),
      alignment(alignment),
      data(new std::uint8_t[size]),
      idCounter(0)
  {}
}
