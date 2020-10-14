//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// Dereference non-dereferenceable iterator.

// UNSUPPORTED: libcxx-no-debug-mode
// UNSUPPORTED: c++03

#define _LIBCPP_DEBUG 1
#define _LIBCPP_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <unordered_set>
#include <cassert>
#include <functional>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**) {
    typedef int T;
    typedef std::unordered_multiset<T, std::hash<T>, std::equal_to<T>, min_allocator<T>> C;
    C c(1);
    C::local_iterator i = c.end(0);
    (void) *i;
    assert(false);

    return 0;
}