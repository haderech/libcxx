// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___ITERATOR_CONCEPTS_H
#define _LIBCPP___ITERATOR_CONCEPTS_H

#include <__config>
#include <concepts>
#include <__iterator/iter_move.h>
#include <__iterator/incrementable_traits.h>
#include <__iterator/iterator_traits.h>
#include <__iterator/readable_traits.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCPP_PUSH_MACROS
#include <__undef_macros>

_LIBCPP_BEGIN_NAMESPACE_STD

#if !defined(_LIBCPP_HAS_NO_RANGES)

// clang-format off

// [iterator.concept.readable]
template<class _In>
concept __indirectly_readable_impl =
  requires(const _In __in) {
    typename iter_value_t<_In>;
    typename iter_reference_t<_In>;
    typename iter_rvalue_reference_t<_In>;
    { *__in } -> same_as<iter_reference_t<_In> >;
    { ranges::iter_move(__in) } -> same_as<iter_rvalue_reference_t<_In> >;
  } &&
  common_reference_with<iter_reference_t<_In>&&, iter_value_t<_In>&> &&
  common_reference_with<iter_reference_t<_In>&&, iter_rvalue_reference_t<_In>&&> &&
  common_reference_with<iter_rvalue_reference_t<_In>&&, const iter_value_t<_In>&>;

template<class _In>
concept indirectly_readable = __indirectly_readable_impl<remove_cvref_t<_In> >;

// [iterator.concept.writable]
template<class _Out, class _Tp>
concept indirectly_writable =
  requires(_Out&& __o, _Tp&& __t) {
    *__o = _VSTD::forward<_Tp>(__t);                        // not required to be equality-preserving
    *_VSTD::forward<_Out>(__o) = _VSTD::forward<_Tp>(__t);  // not required to be equality-preserving
    const_cast<const iter_reference_t<_Out>&&>(*__o) = _VSTD::forward<_Tp>(__t);                       // not required to be equality-preserving
    const_cast<const iter_reference_t<_Out>&&>(*_VSTD::forward<_Out>(__o)) = _VSTD::forward<_Tp>(__t); // not required to be equality-preserving
  };

// [iterator.concept.winc]
template<class _Tp>
concept __integer_like = integral<_Tp> && !same_as<_Tp, bool>;

template<class _Tp>
concept __signed_integer_like = signed_integral<_Tp>;

template<class _Ip>
concept weakly_incrementable =
  default_initializable<_Ip> &&
  movable<_Ip> &&
  requires(_Ip __i) {
    typename iter_difference_t<_Ip>;
    requires __signed_integer_like<iter_difference_t<_Ip> >;
    { ++__i } -> same_as<_Ip&>;   // not required to be equality-preserving
    __i++;                        // not required to be equality-preserving
  };

// [iterator.concept.inc]
template<class _Ip>
concept incrementable =
  regular<_Ip> &&
  weakly_incrementable<_Ip> &&
  requires(_Ip __i) {
    { __i++ } -> same_as<_Ip>;
  };

// [iterator.concept.iterator]
template<class _Ip>
concept input_or_output_iterator =
  requires(_Ip __i) {
    { *__i } -> __referenceable;
  } &&
  weakly_incrementable<_Ip>;

// [iterator.concept.sentinel]
template<class _Sp, class _Ip>
concept sentinel_for =
  semiregular<_Sp> &&
  input_or_output_iterator<_Ip> &&
  __weakly_equality_comparable_with<_Sp, _Ip>;

// clang-format on

#endif // !defined(_LIBCPP_HAS_NO_RANGES)

_LIBCPP_END_NAMESPACE_STD

_LIBCPP_POP_MACROS

#endif // _LIBCPP___ITERATOR_CONCEPTS_H
