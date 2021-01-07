//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.

// <chrono>

// Test the feature test macros defined by <chrono>

/*  Constant                 Value
    __cpp_lib_chrono         201611L [C++17]
    __cpp_lib_chrono_udls    201304L [C++14]
*/

#include <chrono>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_chrono
#   error "__cpp_lib_chrono should not be defined before c++17"
# endif

# ifdef __cpp_lib_chrono_udls
#   error "__cpp_lib_chrono_udls should not be defined before c++14"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_chrono
#   error "__cpp_lib_chrono should not be defined before c++17"
# endif

# ifndef __cpp_lib_chrono_udls
#   error "__cpp_lib_chrono_udls should be defined in c++14"
# endif
# if __cpp_lib_chrono_udls != 201304L
#   error "__cpp_lib_chrono_udls should have the value 201304L in c++14"
# endif

#elif TEST_STD_VER == 17

# ifndef __cpp_lib_chrono
#   error "__cpp_lib_chrono should be defined in c++17"
# endif
# if __cpp_lib_chrono != 201611L
#   error "__cpp_lib_chrono should have the value 201611L in c++17"
# endif

# ifndef __cpp_lib_chrono_udls
#   error "__cpp_lib_chrono_udls should be defined in c++17"
# endif
# if __cpp_lib_chrono_udls != 201304L
#   error "__cpp_lib_chrono_udls should have the value 201304L in c++17"
# endif

#elif TEST_STD_VER == 20

# ifndef __cpp_lib_chrono
#   error "__cpp_lib_chrono should be defined in c++20"
# endif
# if __cpp_lib_chrono != 201611L
#   error "__cpp_lib_chrono should have the value 201611L in c++20"
# endif

# ifndef __cpp_lib_chrono_udls
#   error "__cpp_lib_chrono_udls should be defined in c++20"
# endif
# if __cpp_lib_chrono_udls != 201304L
#   error "__cpp_lib_chrono_udls should have the value 201304L in c++20"
# endif

#endif // TEST_STD_VER == 20

int main(int, char**) { return 0; }
