//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// const_reference operator[](size_type pos) const;
//       reference operator[](size_type pos);

#include <string>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    typedef std::string S;
    S s("0123456789");
    const S& cs = s;
    ASSERT_SAME_TYPE(decltype( s[0]), typename S::reference);
    ASSERT_SAME_TYPE(decltype(cs[0]), typename S::const_reference);
    LIBCPP_ASSERT_NOEXCEPT(    s[0]);
    LIBCPP_ASSERT_NOEXCEPT(   cs[0]);
    for (S::size_type i = 0; i < cs.size(); ++i)
    {
        assert(s[i] == static_cast<char>('0' + i));
        assert(cs[i] == s[i]);
    }
    assert(cs[cs.size()] == '\0');
    const S s2 = S();
    assert(s2[0] == '\0');
    }
#if TEST_STD_VER >= 11
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    S s("0123456789");
    const S& cs = s;
    ASSERT_SAME_TYPE(decltype( s[0]), typename S::reference);
    ASSERT_SAME_TYPE(decltype(cs[0]), typename S::const_reference);
    LIBCPP_ASSERT_NOEXCEPT(    s[0]);
    LIBCPP_ASSERT_NOEXCEPT(   cs[0]);
    for (S::size_type i = 0; i < cs.size(); ++i)
    {
        assert(s[i] == static_cast<char>('0' + i));
        assert(cs[i] == s[i]);
    }
    assert(cs[cs.size()] == '\0');
    const S s2 = S();
    assert(s2[0] == '\0');
    }
#endif

    return 0;
}
