/**
 *
 *  @file future_already_retrieved.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for future already retrieved.
 *
 */
#include <future>

int main()
{
  std::promise<int> promise;
  auto fut1 = promise.get_future();
  (void)fut1;

  auto fut2 = promise.get_future();
  (void)fut2;

  return 0;
}
