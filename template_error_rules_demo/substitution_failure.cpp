/**
 *
 *  @file substitution_failure.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional template error demo for substitution failure.
 *
 */

/**
 *  @brief Only works for types that provide a nested value_type.
 */
template <typename T>
auto use_value_type(const T &) -> typename T::value_type
{
  return {};
}

/**
 *  @brief Intentional error:
 *  substitution fails because int has no nested value_type.
 */
int main()
{
  auto x = use_value_type(42);
  (void)x;
  return 0;
}
