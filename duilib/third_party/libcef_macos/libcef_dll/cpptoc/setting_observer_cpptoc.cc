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
// $hash=ae802e6d7e717dc4366ce996af631dfbb5494f8e$
//

#include "libcef_dll/cpptoc/setting_observer_cpptoc.h"

#include "libcef_dll/shutdown_checker.h"

#if CEF_API_ADDED(13401)

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK
setting_observer_on_setting_changed(struct _cef_setting_observer_t* self,
                                    const cef_string_t* requesting_url,
                                    const cef_string_t* top_level_url,
                                    cef_content_setting_types_t content_type) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Unverified params: requesting_url, top_level_url

  // Execute
  CefSettingObserverCppToC::Get(self)->OnSettingChanged(
      CefString(requesting_url), CefString(top_level_url), content_type);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefSettingObserverCppToC::CefSettingObserverCppToC() {
  GetStruct()->on_setting_changed = setting_observer_on_setting_changed;
}

// DESTRUCTOR - Do not edit by hand.

CefSettingObserverCppToC::~CefSettingObserverCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefSettingObserver> CefCppToCRefCounted<
    CefSettingObserverCppToC,
    CefSettingObserver,
    cef_setting_observer_t>::UnwrapDerived(CefWrapperType type,
                                           cef_setting_observer_t* s) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefSettingObserverCppToC,
                                   CefSettingObserver,
                                   cef_setting_observer_t>::kWrapperType =
    WT_SETTING_OBSERVER;

#endif  // CEF_API_ADDED(13401)
