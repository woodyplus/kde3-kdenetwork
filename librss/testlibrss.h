#ifndef TESTLIBRSS_H
#define TESTLIBRSS_H

#include <qobject.h>

#include "loader.h"
#include "document.h"
#include "global.h"

using RSS::Loader;
using RSS::Document;
using RSS::Status;

class Tester : public QObject
{
	Q_OBJECT
	public:
		void test();

	private slots:
		void slotLoadingComplete( Loader *loader, Document doc, Status status );
};

#endif
