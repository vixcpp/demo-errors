/**
 *
 *  @file future_broken_promise.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for a broken promise.
 *
 */
#include <future>
#include <iostream>

int main()
{
  std::future<int> fut;

  {
    std::promise<int> promise;
    fut = promise.get_future();
  }

  std::cout << fut.get() << "\n";
  return 0;
}
