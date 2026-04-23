/**
 *
 *  @file no_type_named.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional template error demo for missing nested type.
 *
 */
#include <vector>

/**
 *  @brief Intentional error:
 *  the chosen template argument does not provide the nested type.
 */
template <typename T>
struct ValueReader
{
  using type = typename T::value_type;
};

int main()
{
  ValueReader<int>::type value = 42;
  (void)value;
  return 0;
}
