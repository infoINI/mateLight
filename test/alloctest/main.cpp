#include <iostream>
#include <exception>

#include "../../lib/allocator.h"

int main() {
  std::cout << "Allocator Test" << std::endl;

  try {
    mateLight::Allocator allocator(16384, 64);
    mateLight::Allocator::Ptr<int> p = allocator.alloc<int>(64);

    for(int i=0; i<64; ++i) {
      p[i] = i;
    }

    std::cout << "i=[";
    for(int i=0; i<64; ++i) {
      if(i)
        std::cout << " ";

      std::cout << p[i];
    }
    std::cout << "]" << std::endl;
  }
  catch (std::runtime_error& e) {
    std::cerr << "runtime_error: " << e.what() << std::endl;
  }

  return 0;
}
