/**
 *
 *  @file dependent_typename.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional template error demo for missing typename
 *  before a dependent nested type.
 *
 */
#include <vector>

/**
 *  @brief Intentional error:
 *  missing 'typename' before a dependent nested type.
 */
template <typename T>
void process(const T::value_type &value)
{
  (void)value;
}

int main()
{
  process<std::vector<int>>(42);
  return 0;
}
