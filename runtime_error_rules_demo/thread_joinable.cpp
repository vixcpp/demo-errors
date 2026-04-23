/**
 *
 *  @file thread_joinable.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for a joinable std::thread
 *  destroyed without join() or detach().
 *
 */
#include <string>
#include <thread>

int main()
{
  std::string text = "Hello";

  auto appendA = [&]()
  {
    text += "A";
  };

  auto appendB = [&]()
  {
    text += "B";
  };

  std::thread t1(appendA);
  std::thread t2(appendB);

  t1.join();
  return 0;
}
