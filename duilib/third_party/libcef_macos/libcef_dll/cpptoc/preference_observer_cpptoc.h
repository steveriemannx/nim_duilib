// Copyright (c) 2025 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=a5541d0ff744576e10d9407ecd82de955319a630$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_PREFERENCE_OBSERVER_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_PREFERENCE_OBSERVER_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_preference_capi.h"
#include "include/cef_preference.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

#if CEF_API_ADDED(13401)

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class CefPreferenceObserverCppToC
    : public CefCppToCRefCounted<CefPreferenceObserverCppToC,
                                 CefPreferenceObserver,
                                 cef_preference_observer_t> {
 public:
  CefPreferenceObserverCppToC();
  virtual ~CefPreferenceObserverCppToC();
};

constexpr auto CefPreferenceObserverCppToC_Wrap =
    CefPreferenceObserverCppToC::Wrap;
constexpr auto CefPreferenceObserverCppToC_Unwrap =
    CefPreferenceObserverCppToC::Unwrap;

#endif  // CEF_API_ADDED(13401)

#endif  // CEF_LIBCEF_DLL_CPPTOC_PREFERENCE_OBSERVER_CPPTOC_H_
