#include "ringbuffer.h"

namespace mateLight {
  const std::size_t RingBuffer::SIZE = 5;

  Frame* RingBuffer::getNextFrame() {
    //networkClient->addTask(Task(networkClient::TASK_GET_FRAME, getFramePtr(index), Task::Data::Keep()));

    index = next();
    return getFramePtr(index);
  }
}
