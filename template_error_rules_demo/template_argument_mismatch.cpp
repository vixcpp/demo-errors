/**
 *
 *  @file template_argument_mismatch.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional template error demo for template argument mismatch.
 *
 */

/**
 *  @brief A template expecting a type and an integer constant.
 */
template <typename T, int N>
struct Buffer
{
  T data[N];
};

/**
 *  @brief Intentional error:
 *  wrong kind of template argument for the second parameter.
 */
int main()
{
  Buffer<int, double> buffer{};
  (void)buffer;
  return 0;
}
