/**
 *
 *  @file detached_lifetime.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for detached thread lifetime issues.
 *
 */
#include <chrono>
#include <iostream>
#include <thread>

int main()
{
  using namespace std::chrono_literals;

  int value = 42;

  std::thread([&]()
              {
    std::this_thread::sleep_for(100ms);
    std::cout << "value = " << value << "\n"; })
      .detach();

  std::this_thread::sleep_for(10ms);
  return 0;
}
