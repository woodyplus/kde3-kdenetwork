/*
    kopetemessagefilter.cpp - Kopete Message Filtering

    Copyright (c) 2004      by Richard Smith         <kde@metafoo.co.uk>
    Kopete    (c) 2002-2004 by the Kopete developers <kopete-devel@kde.org>

    *************************************************************************
    *                                                                       *
    * This library is free software; you can redistribute it and/or         *
    * modify it under the terms of the GNU Lesser General Public            *
    * License as published by the Free Software Foundation; either          *
    * version 2 of the License, or (at your option) any later version.      *
    *                                                                       *
    *************************************************************************
*/

#include "kopetemessagehandler.h"
#include "kopetemessageevent.h"

#include <kstaticdeleter.h>

namespace Kopete
{

class MessageHandler::Private
{
public:
	Private() : next(0) {}
	MessageHandler *next;
};

MessageHandler::MessageHandler()
 : QObject( 0 ), d( new Private )
{
}

MessageHandler::~MessageHandler()
{
	delete d;
}

MessageHandler *MessageHandler::next()
{
	return d->next;
}

void MessageHandler::setNext( MessageHandler *next )
{
	d->next = next;
}

int MessageHandler::capabilities()
{
	return d->next->capabilities();
}

void MessageHandler::handleMessageInternal( MessageEvent *event )
{
	connect( event, SIGNAL( accepted(Kopete::MessageEvent*) ), this, SLOT( messageAccepted(Kopete::MessageEvent*) ) );
	handleMessage( event );
}

void MessageHandler::handleMessage( MessageEvent *event )
{
	messageAccepted( event );
}

void MessageHandler::messageAccepted( MessageEvent *event )
{
	disconnect( event, SIGNAL( accepted(Kopete::MessageEvent*) ), this, SLOT( messageAccepted(Kopete::MessageEvent*) ) );
	d->next->handleMessageInternal( event );
}


class MessageHandlerFactory::Private
{
public:
	static FactoryList &factories();
};

MessageHandlerFactory::FactoryList &MessageHandlerFactory::Private::factories()
{
	static KStaticDeleter<FactoryList> deleter;
	static FactoryList *list = 0;
	if( !list )
		deleter.setObject( list, new FactoryList );
	return *list;
}

MessageHandlerFactory::MessageHandlerFactory()
	: d( new Private )
{
	Private::factories().append(this);
}

MessageHandlerFactory::~MessageHandlerFactory()
{
	Private::factories().remove( this );
	delete d;
}

MessageHandlerFactory::FactoryList MessageHandlerFactory::messageHandlerFactories()
{
	return Private::factories();
}

}

#include "kopetemessagehandler.moc"

// vim: set noet ts=4 sts=4 sw=4:
