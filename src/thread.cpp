#include "thread.h"

Thread::Thread() : status_(THREAD_STOPPED) { }

Thread::~Thread() {
  while (status_ == THREAD_PENDING);
  if (status_ == THREAD_RUNNING)
    pthread_detach(thread_);
}

/* static */
void* Thread::entry(void *pthis) {
  Thread *obj = static_cast<Thread *>(pthis);
  obj->run();
  return NULL;
}

int Thread::start() {
  if (status_ != THREAD_STOPPED)
    return 1;

  status_ = THREAD_PENDING;
  int ret = pthread_create(&thread_, NULL, &Thread::entry, this);

  if (ret == 0)
    status_ = THREAD_RUNNING;
  else
    status_ = THREAD_STOPPED;
  return ret;
}

int Thread::join() {
  status_ = THREAD_PENDING;
  int ret = pthread_join(thread_, NULL);
  status_ = THREAD_STOPPED;
  return ret;
}

