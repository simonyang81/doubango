/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class CallSession extends InviteSession {
  private long swigCPtr;

  protected CallSession(long cPtr, boolean cMemoryOwn) {
    super(tinyWRAPJNI.CallSession_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(CallSession obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPJNI.delete_CallSession(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public CallSession(SipStack pStack) {
    this(tinyWRAPJNI.new_CallSession(SipStack.getCPtr(pStack), pStack), true);
  }

  public boolean callAudio(String remoteUriString, ActionConfig config) {
    return tinyWRAPJNI.CallSession_callAudio__SWIG_0(swigCPtr, this, remoteUriString, ActionConfig.getCPtr(config), config);
  }

  public boolean callAudio(String remoteUriString) {
    return tinyWRAPJNI.CallSession_callAudio__SWIG_1(swigCPtr, this, remoteUriString);
  }

  public boolean callAudio(SipUri remoteUri, ActionConfig config) {
    return tinyWRAPJNI.CallSession_callAudio__SWIG_2(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri, ActionConfig.getCPtr(config), config);
  }

  public boolean callAudio(SipUri remoteUri) {
    return tinyWRAPJNI.CallSession_callAudio__SWIG_3(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri);
  }

  public boolean callAudioVideo(String remoteUriString, ActionConfig config) {
    return tinyWRAPJNI.CallSession_callAudioVideo__SWIG_0(swigCPtr, this, remoteUriString, ActionConfig.getCPtr(config), config);
  }

  public boolean callAudioVideo(String remoteUriString) {
    return tinyWRAPJNI.CallSession_callAudioVideo__SWIG_1(swigCPtr, this, remoteUriString);
  }

  public boolean callAudioVideo(SipUri remoteUri, ActionConfig config) {
    return tinyWRAPJNI.CallSession_callAudioVideo__SWIG_2(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri, ActionConfig.getCPtr(config), config);
  }

  public boolean callAudioVideo(SipUri remoteUri) {
    return tinyWRAPJNI.CallSession_callAudioVideo__SWIG_3(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri);
  }

  public boolean callVideo(String remoteUriString, ActionConfig config) {
    return tinyWRAPJNI.CallSession_callVideo__SWIG_0(swigCPtr, this, remoteUriString, ActionConfig.getCPtr(config), config);
  }

  public boolean callVideo(String remoteUriString) {
    return tinyWRAPJNI.CallSession_callVideo__SWIG_1(swigCPtr, this, remoteUriString);
  }

  public boolean callVideo(SipUri remoteUri, ActionConfig config) {
    return tinyWRAPJNI.CallSession_callVideo__SWIG_2(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri, ActionConfig.getCPtr(config), config);
  }

  public boolean callVideo(SipUri remoteUri) {
    return tinyWRAPJNI.CallSession_callVideo__SWIG_3(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri);
  }

  public boolean call(String remoteUriString, twrap_media_type_t media, ActionConfig config) {
    return tinyWRAPJNI.CallSession_call__SWIG_0(swigCPtr, this, remoteUriString, media.swigValue(), ActionConfig.getCPtr(config), config);
  }

  public boolean call(String remoteUriString, twrap_media_type_t media) {
    return tinyWRAPJNI.CallSession_call__SWIG_1(swigCPtr, this, remoteUriString, media.swigValue());
  }

  public boolean call(SipUri remoteUri, twrap_media_type_t media, ActionConfig config) {
    return tinyWRAPJNI.CallSession_call__SWIG_2(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri, media.swigValue(), ActionConfig.getCPtr(config), config);
  }

  public boolean call(SipUri remoteUri, twrap_media_type_t media) {
    return tinyWRAPJNI.CallSession_call__SWIG_3(swigCPtr, this, SipUri.getCPtr(remoteUri), remoteUri, media.swigValue());
  }

  public boolean setSessionTimer(long timeout, String refresher) {
    return tinyWRAPJNI.CallSession_setSessionTimer(swigCPtr, this, timeout, refresher);
  }

  public boolean set100rel(boolean enabled) {
    return tinyWRAPJNI.CallSession_set100rel(swigCPtr, this, enabled);
  }

  public boolean setRtcp(boolean enabled) {
    return tinyWRAPJNI.CallSession_setRtcp(swigCPtr, this, enabled);
  }

  public boolean setRtcpMux(boolean enabled) {
    return tinyWRAPJNI.CallSession_setRtcpMux(swigCPtr, this, enabled);
  }

  public boolean setICE(boolean enabled) {
    return tinyWRAPJNI.CallSession_setICE(swigCPtr, this, enabled);
  }

  public boolean setQoS(tmedia_qos_stype_t type, tmedia_qos_strength_t strength) {
    return tinyWRAPJNI.CallSession_setQoS(swigCPtr, this, type.swigValue(), strength.swigValue());
  }

  public boolean hold(ActionConfig config) {
    return tinyWRAPJNI.CallSession_hold__SWIG_0(swigCPtr, this, ActionConfig.getCPtr(config), config);
  }

  public boolean hold() {
    return tinyWRAPJNI.CallSession_hold__SWIG_1(swigCPtr, this);
  }

  public boolean resume(ActionConfig config) {
    return tinyWRAPJNI.CallSession_resume__SWIG_0(swigCPtr, this, ActionConfig.getCPtr(config), config);
  }

  public boolean resume() {
    return tinyWRAPJNI.CallSession_resume__SWIG_1(swigCPtr, this);
  }

  public boolean transfer(String referToUriString, ActionConfig config) {
    return tinyWRAPJNI.CallSession_transfer__SWIG_0(swigCPtr, this, referToUriString, ActionConfig.getCPtr(config), config);
  }

  public boolean transfer(String referToUriString) {
    return tinyWRAPJNI.CallSession_transfer__SWIG_1(swigCPtr, this, referToUriString);
  }

  public boolean acceptTransfer(ActionConfig config) {
    return tinyWRAPJNI.CallSession_acceptTransfer__SWIG_0(swigCPtr, this, ActionConfig.getCPtr(config), config);
  }

  public boolean acceptTransfer() {
    return tinyWRAPJNI.CallSession_acceptTransfer__SWIG_1(swigCPtr, this);
  }

  public boolean rejectTransfer(ActionConfig config) {
    return tinyWRAPJNI.CallSession_rejectTransfer__SWIG_0(swigCPtr, this, ActionConfig.getCPtr(config), config);
  }

  public boolean rejectTransfer() {
    return tinyWRAPJNI.CallSession_rejectTransfer__SWIG_1(swigCPtr, this);
  }

  public boolean sendDTMF(int number) {
    return tinyWRAPJNI.CallSession_sendDTMF(swigCPtr, this, number);
  }

  public long getSessionTransferId() {
    return tinyWRAPJNI.CallSession_getSessionTransferId(swigCPtr, this);
  }

  public boolean sendT140Data(tmedia_t140_data_type_t data_type, java.nio.ByteBuffer data_ptr, long data_size) {
    return tinyWRAPJNI.CallSession_sendT140Data__SWIG_0(swigCPtr, this, data_type.swigValue(), data_ptr, data_size);
  }

  public boolean sendT140Data(tmedia_t140_data_type_t data_type, java.nio.ByteBuffer data_ptr) {
    return tinyWRAPJNI.CallSession_sendT140Data__SWIG_1(swigCPtr, this, data_type.swigValue(), data_ptr);
  }

  public boolean sendT140Data(tmedia_t140_data_type_t data_type) {
    return tinyWRAPJNI.CallSession_sendT140Data__SWIG_2(swigCPtr, this, data_type.swigValue());
  }

  public boolean setT140Callback(T140Callback pT140Callback) {
    return tinyWRAPJNI.CallSession_setT140Callback(swigCPtr, this, T140Callback.getCPtr(pT140Callback), pT140Callback);
  }

}
