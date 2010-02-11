#include "mutex.h"

Mutex::Mutex() {
  pthread_mutex_init(&mutex_, NULL);
}

Mutex::~Mutex() {
  pthread_mutex_destroy(&mutex_);
}

int Mutex::lock() {
  return pthread_mutex_lock(&mutex_);
}

int Mutex::unlock() {
  return pthread_mutex_unlock(&mutex_);
}

int Mutex::trylock() {
  return pthread_mutex_trylock(&mutex_);
}

