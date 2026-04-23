/**
 *
 *  @file promise_already_satisfied.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for promise already satisfied.
 *
 */
#include <future>
#include <iostream>

int main()
{
  std::promise<int> promise;
  auto fut = promise.get_future();

  promise.set_value(10);
  promise.set_value(20);

  std::cout << fut.get() << "\n";
  return 0;
}
