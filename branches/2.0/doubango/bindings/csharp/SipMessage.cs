/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace org.doubango.tinyWRAP {

using System;
using System.Runtime.InteropServices;

public class SipMessage : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal SipMessage(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(SipMessage obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~SipMessage() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          tinyWRAPPINVOKE.delete_SipMessage(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public byte[] getSipContent() {
    uint clen = this.getSipContentLength();
    if(clen>0){        
        IntPtr ptr = Marshal.AllocHGlobal((int)clen);
        this.getSipContent(ptr, clen);
        byte[] bytes = new byte[clen];
        Marshal.Copy(ptr, bytes, 0, bytes.Length);
        Marshal.FreeHGlobal(ptr);
        return bytes;
    }
    return null;
  }

  public SipMessage() : this(tinyWRAPPINVOKE.new_SipMessage(), true) {
  }

  public bool isResponse() {
    bool ret = tinyWRAPPINVOKE.SipMessage_isResponse(swigCPtr);
    return ret;
  }

  public tsip_request_type_t getRequestType() {
    tsip_request_type_t ret = (tsip_request_type_t)tinyWRAPPINVOKE.SipMessage_getRequestType(swigCPtr);
    return ret;
  }

  public short getResponseCode() {
    short ret = tinyWRAPPINVOKE.SipMessage_getResponseCode(swigCPtr);
    return ret;
  }

  public string getSipHeaderValue(string name, uint index) {
    string ret = tinyWRAPPINVOKE.SipMessage_getSipHeaderValue__SWIG_0(swigCPtr, name, index);
    return ret;
  }

  public string getSipHeaderValue(string name) {
    string ret = tinyWRAPPINVOKE.SipMessage_getSipHeaderValue__SWIG_1(swigCPtr, name);
    return ret;
  }

  public string getSipHeaderParamValue(string name, string param, uint index) {
    string ret = tinyWRAPPINVOKE.SipMessage_getSipHeaderParamValue__SWIG_0(swigCPtr, name, param, index);
    return ret;
  }

  public string getSipHeaderParamValue(string name, string param) {
    string ret = tinyWRAPPINVOKE.SipMessage_getSipHeaderParamValue__SWIG_1(swigCPtr, name, param);
    return ret;
  }

  public uint getSipContentLength() {
    uint ret = tinyWRAPPINVOKE.SipMessage_getSipContentLength(swigCPtr);
    return ret;
  }

  public uint getSipContent(IntPtr output, uint maxsize) {
    uint ret = tinyWRAPPINVOKE.SipMessage_getSipContent(swigCPtr, output, maxsize);
    return ret;
  }

  public SdpMessage getSdpMessage() {
    IntPtr cPtr = tinyWRAPPINVOKE.SipMessage_getSdpMessage(swigCPtr);
    SdpMessage ret = (cPtr == IntPtr.Zero) ? null : new SdpMessage(cPtr, false);
    return ret;
  }

}

}
