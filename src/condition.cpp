#include "condition.h"

Condition::Condition() {
  pthread_cond_init(&condition_, NULL);
}

Condition::~Condition() {
  pthread_cond_destroy(&condition_);
}

int Condition::wait() {
  return pthread_cond_wait(&condition_, &mutex_);
}

int Condition::signal() {
  return pthread_cond_signal(&condition_);
}

