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

// <new>

// Test the feature test macros defined by <new>

/*  Constant                                Value
    __cpp_lib_destroying_delete             201806L [C++20]
    __cpp_lib_hardware_interference_size    201703L [C++17]
    __cpp_lib_launder                       201606L [C++17]
*/

#include <new>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_destroying_delete
#   error "__cpp_lib_destroying_delete should not be defined before c++20"
# endif

# ifdef __cpp_lib_hardware_interference_size
#   error "__cpp_lib_hardware_interference_size should not be defined before c++17"
# endif

# ifdef __cpp_lib_launder
#   error "__cpp_lib_launder should not be defined before c++17"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_destroying_delete
#   error "__cpp_lib_destroying_delete should not be defined before c++20"
# endif

# ifdef __cpp_lib_hardware_interference_size
#   error "__cpp_lib_hardware_interference_size should not be defined before c++17"
# endif

# ifdef __cpp_lib_launder
#   error "__cpp_lib_launder should not be defined before c++17"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_destroying_delete
#   error "__cpp_lib_destroying_delete should not be defined before c++20"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_hardware_interference_size
#     error "__cpp_lib_hardware_interference_size should be defined in c++17"
#   endif
#   if __cpp_lib_hardware_interference_size != 201703L
#     error "__cpp_lib_hardware_interference_size should have the value 201703L in c++17"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_hardware_interference_size
#     error "__cpp_lib_hardware_interference_size should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_launder
#   error "__cpp_lib_launder should be defined in c++17"
# endif
# if __cpp_lib_launder != 201606L
#   error "__cpp_lib_launder should have the value 201606L in c++17"
# endif

#elif TEST_STD_VER == 20

# if TEST_STD_VER > 17 && defined(__cpp_impl_destroying_delete) && __cpp_impl_destroying_delete >= 201806L
#   ifndef __cpp_lib_destroying_delete
#     error "__cpp_lib_destroying_delete should be defined in c++20"
#   endif
#   if __cpp_lib_destroying_delete != 201806L
#     error "__cpp_lib_destroying_delete should have the value 201806L in c++20"
#   endif
# else
#   ifdef __cpp_lib_destroying_delete
#     error "__cpp_lib_destroying_delete should not be defined when TEST_STD_VER > 17 && defined(__cpp_impl_destroying_delete) && __cpp_impl_destroying_delete >= 201806L is not defined!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_hardware_interference_size
#     error "__cpp_lib_hardware_interference_size should be defined in c++20"
#   endif
#   if __cpp_lib_hardware_interference_size != 201703L
#     error "__cpp_lib_hardware_interference_size should have the value 201703L in c++20"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_hardware_interference_size
#     error "__cpp_lib_hardware_interference_size should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_launder
#   error "__cpp_lib_launder should be defined in c++20"
# endif
# if __cpp_lib_launder != 201606L
#   error "__cpp_lib_launder should have the value 201606L in c++20"
# endif

#endif // TEST_STD_VER == 20

int main(int, char**) { return 0; }
