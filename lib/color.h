#ifndef mateLight_lib_color_h
#define mateLight_lib_color_h

namespace mateLight {
  struct Color {
    inline Color() {
      r = g = b = 0;
    }

    inline void reset() {
      r = g = b = 0;
    }

    unsigned char r;
    unsigned char g;
    unsigned char b;
  };
}

#endif
