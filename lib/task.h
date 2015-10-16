#ifndef mateLight_lib_task_h
#define mateLight_lib_task_h

#include <cstdint>
#include <cstdlib>
#include <functional>

namespace mateLigiht {
  class Task {
    public:
      // can't foward declare :-(
      struct Data {
        typedef std::function<void(void*)> deleter_t;

        struct Keep {
          inline void operator()(void*);
        };

        struct Delete {
          inline void operator()(void* p);
        };

        struct Free {
          inline void operator()(void* p);
        };

        void* data;
        deleter_t deleter;

        inline Data(void* data, deleter_t deleter = Data::Delete());
      };

    protected:
      std::string command;
      Data data;

    public:
      inline Task(const std::string& command, void* data, Data::deleter_t deleter);
  };

  inline Task::Task(const std::string& command, void* data, Task::Data::deleter_t deleter)
    : command(command),
      data(data, deleter)
  {}

  inline Task::Data::Data(void* data, Task::Data::deleter_t deleter)
    : data(data),
      deleter(deleter)
  {}

  inline void Task::Data::Delete::operator()(void* p) {
    delete (char*)p;
  }
}

#endif
