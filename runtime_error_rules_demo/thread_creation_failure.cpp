/**
 *
 *  @file thread_creation_failure.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for thread creation failure.
 *
 */
#include <chrono>
#include <thread>
#include <vector>

int main()
{
  using namespace std::chrono_literals;

  std::vector<std::thread> threads;
  threads.reserve(1000000);

  try
  {
    for (;;)
    {
      threads.emplace_back([]()
                           { std::this_thread::sleep_for(60s); });
    }
  }
  catch (...)
  {
    for (auto &t : threads)
    {
      if (t.joinable())
        t.detach();
    }
    throw;
  }
}
