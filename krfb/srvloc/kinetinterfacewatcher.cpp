/*
 *  Watches Inet interfaces
 *  Copyright (C) 2002 Tim Jansen <tim@tjansen.de>
 *
 *  $Id: kinetinterfacewatcher.cpp 197800 2003-01-06 13:53:10Z mlaurent $
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA 02111-1307, USA.
 */

#include "kinetinterfacewatcher.h"
#include "kinetinterfacewatcher.moc"

class KInetInterfaceWatcherPrivate {
public:
	QString interface;
	int minInterval; // not used yet, but my be when a daemon watches


	KInetInterfaceWatcherPrivate(const QString &iface,
				     int minIntv) :
		interface(iface),
		minInterval(minIntv) {
	}
};

/*
   * or all network interfaces.
   * @param interface the name of the interface to watch (e.g.'eth0')
   *                  or QString::null to watch all interfaces
   * @param minInterval the minimum interval between two checks in
   *                    seconds. Be careful not to check too often, to
   *                    avoid unneccessary wasting of CPU time
   */
KInetInterfaceWatcher::KInetInterfaceWatcher(const QString &interface,
					     int minInterval) {
	d = new KInetInterfaceWatcherPrivate(interface, minInterval);
}

QString KInetInterfaceWatcher::interface() const {
	return d->interface;
}

KInetInterfaceWatcher::~KInetInterfaceWatcher() {
	delete d;
}

