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
// $hash=ce8c52f4eede293b684111bf1700f6af740a2884$
//

#include "libcef_dll/ctocpp/test/translator_test_ref_ptr_library_ctocpp.h"

#include "libcef_dll/ctocpp/test/translator_test_ref_ptr_library_child_child_ctocpp.h"
#include "libcef_dll/ctocpp/test/translator_test_ref_ptr_library_child_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefTranslatorTestRefPtrLibrary> CefTranslatorTestRefPtrLibrary::
    Create(int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_translator_test_ref_ptr_library_create(value);

  // Return type: refptr_same
  return CefTranslatorTestRefPtrLibraryCToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") int CefTranslatorTestRefPtrLibraryCToCpp::GetValue() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefTranslatorTestRefPtrLibraryCToCpp::SetValue(int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_value) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value(_struct, value);
}

// CONSTRUCTOR - Do not edit by hand.

CefTranslatorTestRefPtrLibraryCToCpp::CefTranslatorTestRefPtrLibraryCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefTranslatorTestRefPtrLibraryCToCpp::~CefTranslatorTestRefPtrLibraryCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_translator_test_ref_ptr_library_t*
CefCToCppRefCounted<CefTranslatorTestRefPtrLibraryCToCpp,
                    CefTranslatorTestRefPtrLibrary,
                    cef_translator_test_ref_ptr_library_t>::
    UnwrapDerived(CefWrapperType type, CefTranslatorTestRefPtrLibrary* c) {
  if (type == WT_TRANSLATOR_TEST_REF_PTR_LIBRARY_CHILD) {
    return reinterpret_cast<cef_translator_test_ref_ptr_library_t*>(
        CefTranslatorTestRefPtrLibraryChildCToCpp_Unwrap(
            reinterpret_cast<CefTranslatorTestRefPtrLibraryChild*>(c)));
  }
  if (type == WT_TRANSLATOR_TEST_REF_PTR_LIBRARY_CHILD_CHILD) {
    return reinterpret_cast<cef_translator_test_ref_ptr_library_t*>(
        CefTranslatorTestRefPtrLibraryChildChildCToCpp_Unwrap(
            reinterpret_cast<CefTranslatorTestRefPtrLibraryChildChild*>(c)));
  }
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType
    CefCToCppRefCounted<CefTranslatorTestRefPtrLibraryCToCpp,
                        CefTranslatorTestRefPtrLibrary,
                        cef_translator_test_ref_ptr_library_t>::kWrapperType =
        WT_TRANSLATOR_TEST_REF_PTR_LIBRARY;
