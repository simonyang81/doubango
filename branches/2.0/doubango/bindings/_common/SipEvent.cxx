/*
* Copyright (C) 2010-2011 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
#include "SipEvent.h"
#include "SipSession.h"
#include "SipMessage.h"

#include "SipStack.h"

/* ======================== SipEvent ========================*/
SipEvent::SipEvent(const tsip_event_t *_sipevent)
{
	this->sipevent = _sipevent;
	if(_sipevent){
		this->sipmessage = new SipMessage(_sipevent->sipmessage);
	}
	else{
		this->sipmessage = tsk_null;
	}
}

SipEvent::~SipEvent()
{
	if(this->sipmessage){
		delete this->sipmessage;
	}
}

short SipEvent::getCode() const
{
	return this->sipevent->code;
}

const char* SipEvent::getPhrase() const
{
	return this->sipevent->phrase;
}

const SipSession* SipEvent::getBaseSession() const
{
	const void* userdata = tsip_ssession_get_userdata(this->sipevent->ss);
	if(userdata){
		return dyn_cast<const SipSession*>((const SipSession*)userdata);
	}
	return tsk_null;
}

const SipMessage* SipEvent::getSipMessage() const
{
	return this->sipmessage;
}

SipStack* SipEvent::getStack()const
{
	const tsip_stack_handle_t* stack_handle = tsip_ssession_get_stack(sipevent->ss);
	const void* userdata;
	if(stack_handle && (userdata = tsip_stack_get_userdata(stack_handle))){
		return dyn_cast<SipStack*>((SipStack*)userdata);
	}
	return tsk_null;
}


/* ======================== DialogEvent ========================*/
DialogEvent::DialogEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent){ }

DialogEvent::~DialogEvent(){ }


/* ======================== DialogEvent ========================*/
StackEvent::StackEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent){ }

StackEvent::~StackEvent(){ }


/* ======================== InviteEvent ========================*/
InviteEvent::InviteEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent)
{
}

InviteEvent::~InviteEvent()
{
}

tsip_invite_event_type_t InviteEvent::getType() const
{
	return TSIP_INVITE_EVENT(this->sipevent)->type;
}

twrap_media_type_t InviteEvent::getMediaType() const
{
	// Ignore Mixed session (both audio/video and MSRP) as specified by GSMA RCS.
	if(this->sipevent && this->sipevent->ss){
		tmedia_type_t type = tsip_ssession_get_mediatype(this->sipevent->ss);
		if(type & tmedia_msrp){
			return twrap_media_msrp;
		}
		else{
			twrap_media_type_t ret = twrap_media_none;
			if(type & tmedia_audio) ret = (twrap_media_type_t)(ret | twrap_media_audio);
			if(type & tmedia_video) ret = (twrap_media_type_t)(ret | twrap_media_video);
			if(type & tmedia_t140) ret = (twrap_media_type_t)(ret | twrap_media_t140);
			return ret;
		}
	}
	return twrap_media_none;
}

const InviteSession* InviteEvent::getSession() const
{
	return dyn_cast<const InviteSession*>(this->getBaseSession());
}

CallSession* InviteEvent::takeCallSessionOwnership() const
{
	// TODO: Factor all takeSessionOwnership() functions
	if(this->sipevent && this->sipevent->ss && !tsip_ssession_have_ownership(this->sipevent->ss)){
		SipStack* stack = this->getStack();
		if(stack){
			/* The constructor will call take_ownerhip() */
			return new CallSession(stack, this->sipevent->ss);
		}
	}
	return tsk_null;
}

MsrpSession* InviteEvent::takeMsrpSessionOwnership() const
{
	// TODO: Factor all takeSessionOwnership() functions
	if(this->sipevent && this->sipevent->ss && !tsip_ssession_have_ownership(this->sipevent->ss)){
		SipStack* stack = this->getStack();
		if(stack){
			/* The constructor will call take_ownerhip() */
			return new MsrpSession(stack, this->sipevent->ss);
		}
	}
	return tsk_null;
}

/* ======================== MessagingEvent ========================*/
MessagingEvent::MessagingEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent)
{
}

MessagingEvent::~MessagingEvent()
{
}

tsip_message_event_type_t MessagingEvent::getType() const
{
	return TSIP_MESSAGE_EVENT(this->sipevent)->type;
}

const MessagingSession* MessagingEvent::getSession() const
{
	return dyn_cast<const MessagingSession*>(this->getBaseSession());
}

MessagingSession* MessagingEvent::takeSessionOwnership() const
{
	if(this->sipevent && this->sipevent->ss && !tsip_ssession_have_ownership(this->sipevent->ss)){
		SipStack* stack = this->getStack();
		if(stack){
			/* The constructor will call take_ownerhip() */
			return new MessagingSession(stack, this->sipevent->ss);
		}
	}
	return tsk_null;
}



/* ======================== InfoEvent ========================*/
InfoEvent::InfoEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent)
{
}

InfoEvent::~InfoEvent()
{
}

tsip_info_event_type_t InfoEvent::getType() const
{
	return TSIP_INFO_EVENT(this->sipevent)->type;
}

const InfoSession* InfoEvent::getSession() const
{
	return dyn_cast<const InfoSession*>(this->getBaseSession());
}

InfoSession* InfoEvent::takeSessionOwnership() const
{
	if(this->sipevent && this->sipevent->ss && !tsip_ssession_have_ownership(this->sipevent->ss)){
		SipStack* stack = this->getStack();
		if(stack){
			/* The constructor will call take_ownerhip() */
			return new InfoSession(stack, this->sipevent->ss);
		}
	}
	return tsk_null;
}



/* ======================== OptionsEvent ========================*/
OptionsEvent::OptionsEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent)
{
}

OptionsEvent::~OptionsEvent()
{
}

tsip_options_event_type_t OptionsEvent::getType() const
{
	return TSIP_OPTIONS_EVENT(this->sipevent)->type;
}

const OptionsSession* OptionsEvent::getSession() const
{
	return dyn_cast<const OptionsSession*>(this->getBaseSession());
}

OptionsSession* OptionsEvent::takeSessionOwnership() const
{
	if(this->sipevent && this->sipevent->ss && !tsip_ssession_have_ownership(this->sipevent->ss)){
		SipStack* stack = this->getStack();
		if(stack){
			/* The constructor will call take_ownerhip() */
			return new OptionsSession(stack, this->sipevent->ss);
		}
	}
	return tsk_null;
}


/* ======================== PublicationEvent ========================*/
PublicationEvent::PublicationEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent)
{
}

PublicationEvent::~PublicationEvent()
{
}

tsip_publish_event_type_t PublicationEvent::getType() const
{
	return TSIP_PUBLISH_EVENT(this->sipevent)->type;
}

const PublicationSession* PublicationEvent::getSession() const
{
	return dyn_cast<const PublicationSession*>(this->getBaseSession());
}



/* ======================== RegistrationEvent ========================*/
RegistrationEvent::RegistrationEvent(const tsip_event_t *_sipevent)
:SipEvent(_sipevent)
{
}

RegistrationEvent::~RegistrationEvent()
{
}

tsip_register_event_type_t RegistrationEvent::getType() const
{
	return TSIP_REGISTER_EVENT(this->sipevent)->type;
}

const RegistrationSession* RegistrationEvent::getSession() const
{
	return dyn_cast<const RegistrationSession*>(this->getBaseSession());
}

RegistrationSession* RegistrationEvent::takeSessionOwnership() const
{
	// TODO: Factor all takeSessionOwnership() functions
	if(this->sipevent && this->sipevent->ss && !tsip_ssession_have_ownership(this->sipevent->ss)){
		SipStack* stack = this->getStack();
		if(stack){
			/* The constructor will call take_ownerhip() */
			return new RegistrationSession(stack, this->sipevent->ss);
		}
	}
	return tsk_null;
}


/* ======================== SubscriptionEvent ========================*/
SubscriptionEvent::SubscriptionEvent(const tsip_event_t *sipevent)
:SipEvent(sipevent)
{
}

SubscriptionEvent::~SubscriptionEvent()
{
}

tsip_subscribe_event_type_t SubscriptionEvent::getType() const
{
	return TSIP_SUBSCRIBE_EVENT(this->sipevent)->type;
}

const SubscriptionSession* SubscriptionEvent::getSession() const
{
	return dyn_cast<const SubscriptionSession*>(this->getBaseSession());
}