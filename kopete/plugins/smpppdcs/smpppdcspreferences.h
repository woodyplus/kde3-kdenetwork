/*
    smpppdcspreferences.h
 
    Copyright (c) 2004-2006 by Heiko Schaefer        <heiko@rangun.de>
 
    Kopete    (c) 2002-2006 by the Kopete developers <kopete-devel@kde.org>
 
    *************************************************************************
    *                                                                       *
    * This program is free software; you can redistribute it and/or modify  *
    * it under the terms of the GNU General Public License as published by  *
    * the Free Software Foundation; version 2 of the License.               *
    *                                                                       *
    *************************************************************************
*/

#ifndef SMPPPDCSPREFERENCES_H
#define SMPPPDCSPREFERENCES_H

#include <kcmodule.h>

class QListViewItem;

class SMPPPDCSPrefs;

class AccountPrivMap {
public:
	AccountPrivMap(bool isOn = FALSE, const QString& id = QString::null)
	 : m_on(isOn), m_id(id) {}
	bool m_on;
	QString m_id;
};

/**
 * @brief Module for the configuration of the smpppdcs-plugin
 *
 * @author Heiko Sch&auml;fer <heiko@rangun.de>
 */
class SMPPPDCSPreferences : public KCModule {
    Q_OBJECT

    SMPPPDCSPreferences(const SMPPPDCSPreferences&);
    SMPPPDCSPreferences& operator=(const SMPPPDCSPreferences&);

public:
	typedef QMap<QString, AccountPrivMap> AccountMap;

    /**
     * @brief Creates an <code>SMPPPDCSPreferences</code> instance
     */
    SMPPPDCSPreferences(QWidget * parent = 0, const char * name = 0, const QStringList &args = QStringList());
	
	/**
     * @brief Destroys an <code>SMPPPDCSPreferences</code> instance
     */
    virtual ~SMPPPDCSPreferences();

	virtual void load();
	virtual void save();
	virtual void defaults();
	
protected slots:
	void listClicked(QListViewItem * item);

private slots:
	void slotModified();
	
protected:

	/// The UI class generated by the QT-designer
    SMPPPDCSPrefs * m_ui;
	
	AccountMap m_accountMapOld;
	AccountMap m_accountMapCur;
};

#endif
