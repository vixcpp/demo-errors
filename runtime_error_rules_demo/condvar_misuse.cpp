/**
 *
 *  @file condvar_misuse.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for condition variable misuse.
 *
 */
#include <stdexcept>
#include <system_error>

#ifndef _WIN32
#include <pthread.h>
#endif

int main()
{
#ifndef _WIN32
  pthread_cond_t cond;
  pthread_cond_init(&cond, nullptr);

  pthread_mutex_t mutex;
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_init(&mutex, &attr);

  const int rc = pthread_cond_wait(&cond, &mutex);

  if (rc != 0)
    throw std::system_error(rc, std::generic_category(), "pthread_cond_wait failed");

  pthread_mutex_destroy(&mutex);
  pthread_mutexattr_destroy(&attr);
  pthread_cond_destroy(&cond);
#else
  throw std::runtime_error("condvar_misuse demo is only enabled on POSIX platforms");
#endif

  return 0;
}
