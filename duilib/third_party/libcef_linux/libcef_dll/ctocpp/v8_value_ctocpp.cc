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
// $hash=decf8396e598094b097017107f966f438cb08408$
//

#include "libcef_dll/ctocpp/v8_value_ctocpp.h"

#include "libcef_dll/cpptoc/base_ref_counted_cpptoc.h"
#include "libcef_dll/cpptoc/v8_accessor_cpptoc.h"
#include "libcef_dll/cpptoc/v8_array_buffer_release_callback_cpptoc.h"
#include "libcef_dll/cpptoc/v8_handler_cpptoc.h"
#include "libcef_dll/cpptoc/v8_interceptor_cpptoc.h"
#include "libcef_dll/ctocpp/v8_context_ctocpp.h"
#include "libcef_dll/ctocpp/v8_exception_ctocpp.h"
#include "libcef_dll/transfer_util.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") CefRefPtr<CefV8Value> CefV8Value::CreateUndefined() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_undefined();

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefV8Value> CefV8Value::CreateNull() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_null();

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateBool(bool value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_bool(value);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateInt(int32_t value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_int(value);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateUInt(uint32_t value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_uint(value);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateDouble(double value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_double(value);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateDate(CefBaseTime date) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_date(date);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateString(const CefString& value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: value

  // Execute
  auto* _retval = cef_v8_value_create_string(value.GetStruct());

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateObject(
    CefRefPtr<CefV8Accessor> accessor,
    CefRefPtr<CefV8Interceptor> interceptor) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: accessor, interceptor

  // Execute
  auto* _retval =
      cef_v8_value_create_object(CefV8AccessorCppToC_Wrap(accessor),
                                 CefV8InterceptorCppToC_Wrap(interceptor));

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateArray(int length) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_array(length);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateArrayBuffer(
    void* buffer,
    size_t length,
    CefRefPtr<CefV8ArrayBufferReleaseCallback> release_callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: release_callback; type: refptr_diff
  DCHECK(release_callback.get());
  if (!release_callback.get()) {
    return nullptr;
  }
  // Unverified params: buffer

  // Execute
  auto* _retval = cef_v8_value_create_array_buffer(
      buffer, length,
      CefV8ArrayBufferReleaseCallbackCppToC_Wrap(release_callback));

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateArrayBufferWithCopy(void* buffer,
                                                            size_t length) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: buffer

  // Execute
  auto* _retval = cef_v8_value_create_array_buffer_with_copy(buffer, length);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8Value::CreateFunction(
    const CefString& name,
    CefRefPtr<CefV8Handler> handler) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return nullptr;
  }
  // Verify param: handler; type: refptr_diff
  DCHECK(handler.get());
  if (!handler.get()) {
    return nullptr;
  }

  // Execute
  auto* _retval = cef_v8_value_create_function(
      name.GetStruct(), CefV8HandlerCppToC_Wrap(handler));

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefV8Value> CefV8Value::CreatePromise() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_v8_value_create_promise();

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsValid() {
  auto* _struct = GetStruct();
  if (!_struct->is_valid) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsUndefined() {
  auto* _struct = GetStruct();
  if (!_struct->is_undefined) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_undefined(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsNull() {
  auto* _struct = GetStruct();
  if (!_struct->is_null) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_null(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsBool() {
  auto* _struct = GetStruct();
  if (!_struct->is_bool) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_bool(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsInt() {
  auto* _struct = GetStruct();
  if (!_struct->is_int) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_int(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsUInt() {
  auto* _struct = GetStruct();
  if (!_struct->is_uint) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_uint(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsDouble() {
  auto* _struct = GetStruct();
  if (!_struct->is_double) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_double(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsDate() {
  auto* _struct = GetStruct();
  if (!_struct->is_date) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_date(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsString() {
  auto* _struct = GetStruct();
  if (!_struct->is_string) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_string(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsObject() {
  auto* _struct = GetStruct();
  if (!_struct->is_object) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_object(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsArray() {
  auto* _struct = GetStruct();
  if (!_struct->is_array) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_array(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsArrayBuffer() {
  auto* _struct = GetStruct();
  if (!_struct->is_array_buffer) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_array_buffer(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsFunction() {
  auto* _struct = GetStruct();
  if (!_struct->is_function) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_function(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsPromise() {
  auto* _struct = GetStruct();
  if (!_struct->is_promise) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_promise(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::IsSame(CefRefPtr<CefV8Value> that) {
  auto* _struct = GetStruct();
  if (!_struct->is_same) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: that; type: refptr_same
  DCHECK(that.get());
  if (!that.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->is_same(_struct, CefV8ValueCToCpp_Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::GetBoolValue() {
  auto* _struct = GetStruct();
  if (!_struct->get_bool_value) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_bool_value(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") int32_t CefV8ValueCToCpp::GetIntValue() {
  auto* _struct = GetStruct();
  if (!_struct->get_int_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int32_t _retval = _struct->get_int_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") uint32_t CefV8ValueCToCpp::GetUIntValue() {
  auto* _struct = GetStruct();
  if (!_struct->get_uint_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  uint32_t _retval = _struct->get_uint_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") double CefV8ValueCToCpp::GetDoubleValue() {
  auto* _struct = GetStruct();
  if (!_struct->get_double_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  double _retval = _struct->get_double_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") CefBaseTime CefV8ValueCToCpp::GetDateValue() {
  auto* _struct = GetStruct();
  if (!_struct->get_date_value) {
    return CefBaseTime();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_basetime_t _retval = _struct->get_date_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") CefString CefV8ValueCToCpp::GetStringValue() {
  auto* _struct = GetStruct();
  if (!_struct->get_string_value) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_string_value(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::IsUserCreated() {
  auto* _struct = GetStruct();
  if (!_struct->is_user_created) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_user_created(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::HasException() {
  auto* _struct = GetStruct();
  if (!_struct->has_exception) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->has_exception(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Exception> CefV8ValueCToCpp::GetException() {
  auto* _struct = GetStruct();
  if (!_struct->get_exception) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_exception(_struct);

  // Return type: refptr_same
  return CefV8ExceptionCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::ClearException() {
  auto* _struct = GetStruct();
  if (!_struct->clear_exception) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->clear_exception(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::WillRethrowExceptions() {
  auto* _struct = GetStruct();
  if (!_struct->will_rethrow_exceptions) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->will_rethrow_exceptions(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::SetRethrowExceptions(bool rethrow) {
  auto* _struct = GetStruct();
  if (!_struct->set_rethrow_exceptions) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->set_rethrow_exceptions(_struct, rethrow);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::HasValue(const CefString& key) {
  auto* _struct = GetStruct();
  if (!_struct->has_value_bykey) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: key

  // Execute
  int _retval = _struct->has_value_bykey(_struct, key.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::HasValue(int index) {
  auto* _struct = GetStruct();
  if (!_struct->has_value_byindex) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0) {
    return false;
  }

  // Execute
  int _retval = _struct->has_value_byindex(_struct, index);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::DeleteValue(const CefString& key) {
  auto* _struct = GetStruct();
  if (!_struct->delete_value_bykey) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: key

  // Execute
  int _retval = _struct->delete_value_bykey(_struct, key.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::DeleteValue(int index) {
  auto* _struct = GetStruct();
  if (!_struct->delete_value_byindex) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0) {
    return false;
  }

  // Execute
  int _retval = _struct->delete_value_byindex(_struct, index);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8ValueCToCpp::GetValue(const CefString& key) {
  auto* _struct = GetStruct();
  if (!_struct->get_value_bykey) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: key

  // Execute
  auto* _retval = _struct->get_value_bykey(_struct, key.GetStruct());

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8ValueCToCpp::GetValue(int index) {
  auto* _struct = GetStruct();
  if (!_struct->get_value_byindex) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0) {
    return nullptr;
  }

  // Execute
  auto* _retval = _struct->get_value_byindex(_struct, index);

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::SetValue(const CefString& key,
                                CefRefPtr<CefV8Value> value,
                                PropertyAttribute attribute) {
  auto* _struct = GetStruct();
  if (!_struct->set_value_bykey) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }
  // Unverified params: key

  // Execute
  int _retval = _struct->set_value_bykey(
      _struct, key.GetStruct(), CefV8ValueCToCpp_Unwrap(value), attribute);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::SetValue(int index, CefRefPtr<CefV8Value> value) {
  auto* _struct = GetStruct();
  if (!_struct->set_value_byindex) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0) {
    return false;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_value_byindex(_struct, index,
                                           CefV8ValueCToCpp_Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::SetValue(const CefString& key,
                                PropertyAttribute attribute) {
  auto* _struct = GetStruct();
  if (!_struct->set_value_byaccessor) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: key

  // Execute
  int _retval =
      _struct->set_value_byaccessor(_struct, key.GetStruct(), attribute);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::GetKeys(std::vector<CefString>& keys) {
  auto* _struct = GetStruct();
  if (!_struct->get_keys) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: keys; type: string_vec_byref
  cef_string_list_t keysList = cef_string_list_alloc();
  DCHECK(keysList);
  if (keysList) {
    transfer_string_list_contents(keys, keysList);
  }

  // Execute
  int _retval = _struct->get_keys(_struct, keysList);

  // Restore param:keys; type: string_vec_byref
  if (keysList) {
    keys.clear();
    transfer_string_list_contents(keysList, keys);
    cef_string_list_free(keysList);
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::SetUserData(CefRefPtr<CefBaseRefCounted> user_data) {
  auto* _struct = GetStruct();
  if (!_struct->set_user_data) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: user_data

  // Execute
  int _retval =
      _struct->set_user_data(_struct, CefBaseRefCountedCppToC_Wrap(user_data));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefBaseRefCounted> CefV8ValueCToCpp::GetUserData() {
  auto* _struct = GetStruct();
  if (!_struct->get_user_data) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_user_data(_struct);

  // Return type: refptr_diff
  return CefBaseRefCountedCppToC_Unwrap(_retval);
}

NO_SANITIZE("cfi-icall") int CefV8ValueCToCpp::GetExternallyAllocatedMemory() {
  auto* _struct = GetStruct();
  if (!_struct->get_externally_allocated_memory) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_externally_allocated_memory(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
int CefV8ValueCToCpp::AdjustExternallyAllocatedMemory(int change_in_bytes) {
  auto* _struct = GetStruct();
  if (!_struct->adjust_externally_allocated_memory) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval =
      _struct->adjust_externally_allocated_memory(_struct, change_in_bytes);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefV8ValueCToCpp::GetArrayLength() {
  auto* _struct = GetStruct();
  if (!_struct->get_array_length) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_array_length(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8ArrayBufferReleaseCallback> CefV8ValueCToCpp::
    GetArrayBufferReleaseCallback() {
  auto* _struct = GetStruct();
  if (!_struct->get_array_buffer_release_callback) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_array_buffer_release_callback(_struct);

  // Return type: refptr_diff
  return CefV8ArrayBufferReleaseCallbackCppToC_Unwrap(_retval);
}

NO_SANITIZE("cfi-icall") bool CefV8ValueCToCpp::NeuterArrayBuffer() {
  auto* _struct = GetStruct();
  if (!_struct->neuter_array_buffer) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->neuter_array_buffer(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") size_t CefV8ValueCToCpp::GetArrayBufferByteLength() {
  auto* _struct = GetStruct();
  if (!_struct->get_array_buffer_byte_length) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  size_t _retval = _struct->get_array_buffer_byte_length(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void* CefV8ValueCToCpp::GetArrayBufferData() {
  auto* _struct = GetStruct();
  if (!_struct->get_array_buffer_data) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  void* _retval = _struct->get_array_buffer_data(_struct);

  // Return type: simple_byaddr
  return _retval;
}

NO_SANITIZE("cfi-icall") CefString CefV8ValueCToCpp::GetFunctionName() {
  auto* _struct = GetStruct();
  if (!_struct->get_function_name) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_function_name(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Handler> CefV8ValueCToCpp::GetFunctionHandler() {
  auto* _struct = GetStruct();
  if (!_struct->get_function_handler) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_function_handler(_struct);

  // Return type: refptr_diff
  return CefV8HandlerCppToC_Unwrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8ValueCToCpp::ExecuteFunction(
    CefRefPtr<CefV8Value> object,
    const CefV8ValueList& arguments) {
  auto* _struct = GetStruct();
  if (!_struct->execute_function) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: object

  // Translate param: arguments; type: refptr_vec_same_byref_const
  const size_t argumentsCount = arguments.size();
  cef_v8_value_t** argumentsList = NULL;
  if (argumentsCount > 0) {
    argumentsList = new cef_v8_value_t*[argumentsCount];
    DCHECK(argumentsList);
    if (argumentsList) {
      for (size_t i = 0; i < argumentsCount; ++i) {
        argumentsList[i] = CefV8ValueCToCpp_Unwrap(arguments[i]);
      }
    }
  }

  // Execute
  auto* _retval = _struct->execute_function(
      _struct, CefV8ValueCToCpp_Unwrap(object), argumentsCount, argumentsList);

  // Restore param:arguments; type: refptr_vec_same_byref_const
  if (argumentsList) {
    delete[] argumentsList;
  }

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefV8Value> CefV8ValueCToCpp::ExecuteFunctionWithContext(
    CefRefPtr<CefV8Context> context,
    CefRefPtr<CefV8Value> object,
    const CefV8ValueList& arguments) {
  auto* _struct = GetStruct();
  if (!_struct->execute_function_with_context) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: context; type: refptr_same
  DCHECK(context.get());
  if (!context.get()) {
    return nullptr;
  }
  // Unverified params: object

  // Translate param: arguments; type: refptr_vec_same_byref_const
  const size_t argumentsCount = arguments.size();
  cef_v8_value_t** argumentsList = NULL;
  if (argumentsCount > 0) {
    argumentsList = new cef_v8_value_t*[argumentsCount];
    DCHECK(argumentsList);
    if (argumentsList) {
      for (size_t i = 0; i < argumentsCount; ++i) {
        argumentsList[i] = CefV8ValueCToCpp_Unwrap(arguments[i]);
      }
    }
  }

  // Execute
  auto* _retval = _struct->execute_function_with_context(
      _struct, CefV8ContextCToCpp_Unwrap(context),
      CefV8ValueCToCpp_Unwrap(object), argumentsCount, argumentsList);

  // Restore param:arguments; type: refptr_vec_same_byref_const
  if (argumentsList) {
    delete[] argumentsList;
  }

  // Return type: refptr_same
  return CefV8ValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::ResolvePromise(CefRefPtr<CefV8Value> arg) {
  auto* _struct = GetStruct();
  if (!_struct->resolve_promise) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: arg

  // Execute
  int _retval = _struct->resolve_promise(_struct, CefV8ValueCToCpp_Unwrap(arg));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8ValueCToCpp::RejectPromise(const CefString& errorMsg) {
  auto* _struct = GetStruct();
  if (!_struct->reject_promise) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: errorMsg; type: string_byref_const
  DCHECK(!errorMsg.empty());
  if (errorMsg.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->reject_promise(_struct, errorMsg.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefV8ValueCToCpp::CefV8ValueCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefV8ValueCToCpp::~CefV8ValueCToCpp() {}

template <>
cef_v8_value_t*
CefCToCppRefCounted<CefV8ValueCToCpp, CefV8Value, cef_v8_value_t>::
    UnwrapDerived(CefWrapperType type, CefV8Value* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefV8ValueCToCpp,
                                   CefV8Value,
                                   cef_v8_value_t>::kWrapperType = WT_V8_VALUE;
