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
// $hash=8e25f22188b5e74771b20ba94254adb157c84916$
//

#include "libcef_dll/cpptoc/preference_observer_cpptoc.h"

#include "libcef_dll/shutdown_checker.h"

#if CEF_API_ADDED(13401)

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK preference_observer_on_preference_changed(
    struct _cef_preference_observer_t* self,
    const cef_string_t* name) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: name; type: string_byref_const
  DCHECK(name);
  if (!name) {
    return;
  }

  // Execute
  CefPreferenceObserverCppToC::Get(self)->OnPreferenceChanged(CefString(name));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefPreferenceObserverCppToC::CefPreferenceObserverCppToC() {
  GetStruct()->on_preference_changed =
      preference_observer_on_preference_changed;
}

// DESTRUCTOR - Do not edit by hand.

CefPreferenceObserverCppToC::~CefPreferenceObserverCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefPreferenceObserver> CefCppToCRefCounted<
    CefPreferenceObserverCppToC,
    CefPreferenceObserver,
    cef_preference_observer_t>::UnwrapDerived(CefWrapperType type,
                                              cef_preference_observer_t* s) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefPreferenceObserverCppToC,
                                   CefPreferenceObserver,
                                   cef_preference_observer_t>::kWrapperType =
    WT_PREFERENCE_OBSERVER;

#endif  // CEF_API_ADDED(13401)
