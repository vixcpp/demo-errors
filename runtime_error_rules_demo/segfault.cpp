/**
 *
 *  @file segfault.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.  All rights reserved.
 *  https://github.com/vixcpp/vix
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 *
 *  @brief Intentional runtime error demo for segmentation fault.
 *
 */
int main()
{
  int *ptr = nullptr;
  *ptr = 42;
  return 0;
}
