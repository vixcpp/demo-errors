/**
 *
 *  @file deadlock.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for a deadlock.
 *
 */
#include <chrono>
#include <mutex>
#include <thread>

int main()
{
  using namespace std::chrono_literals;

  std::mutex m1;
  std::mutex m2;

  auto a = [&]()
  {
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(50ms);
    std::lock_guard<std::mutex> lock2(m2);
    (void)lock2;
  };

  auto b = [&]()
  {
    std::lock_guard<std::mutex> lock1(m2);
    std::this_thread::sleep_for(50ms);
    std::lock_guard<std::mutex> lock2(m1);
    (void)lock2;
  };

  std::thread t1(a);
  std::thread t2(b);

  t1.join();
  t2.join();
  return 0;
}
