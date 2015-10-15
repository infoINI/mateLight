#include "frame.h"

namespace mateLight {
  void Frame::resize(std::uint8_t columnCount, std::uint8_t rowCount) {
    if(columnCount == 0) {
      throw std::runtime_error("columCount = 0 not allowed");
    }

    if(rowCount == 0) {
      throw std::runtime_error("rowCount = 0 not allowed");
    }

    // only resize if columnCount or rowCount has changed
    if(this->columnCount == columnCount && this->rowCount == rowCount) {
      return;
    }

    Allocator::Ptr<Color> resizedPixel = allocator->alloc<Color>(columnCount * rowCount);
    if(!resizedPixel) {
      throw std::runtime_error("memory allocation failed");
    }

    this->allocator->free(pixel);

    this->columnCount = columnCount;
    this->rowCount = rowCount;
    this->pixel = resizedPixel;
  }
}

