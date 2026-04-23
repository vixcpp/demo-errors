/**
 *
 *  @file data_race.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for a data race.
 *
 */
#include <iostream>
#include <thread>

int main()
{
  int counter = 0;

  auto work = [&]()
  {
    for (int i = 0; i < 100000; ++i)
      ++counter;
  };

  std::thread t1(work);
  std::thread t2(work);

  t1.join();
  t2.join();

  std::cout << "counter = " << counter << "\n";
  return 0;
}
