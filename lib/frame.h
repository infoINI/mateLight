#ifndef mateLight_lib_frame_h
#define mateLight_lib_frame_h

#include "color.h"

namespace mateLight {
  class Frame {
    protected:
      unsigned int displayTime;
      unsigned char columnCount;
      unsigned char rowCount;
      Color* pixel;

    public:
      inline Frame(unsigned char columnCount, unsigned char rowCount);
      inline Frame(const Frame& f);
      virtual inline ~Frame();

      inline void setDisplayTime(unsigned int displayTime);

      inline void reset();
      void resize(unsigned char columnCount, unsigned char rowCount);
  };


  inline void Frame::setDisplayTime(unsigned int displayTime) {
    this->displayTime = displayTime;
  }

  inline void Frame::reset() {
    for(int i=0; pixel && i<columnCount*rowCount;++i) {
      (pixel+i)->reset();
    }
  }
}

#endif
