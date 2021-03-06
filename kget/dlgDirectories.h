/***************************************************************************
*                               dlgDirectories.h
*                             -------------------
*
*    Revision     : $Id: dlgDirectories.h 476275 2005-11-01 01:30:58Z thiago $
*    begin        : Tue Jan 29 2002
*    copyright    : (C) 2002 by Patrick Charbonnier
*                 : Based On Caitoo v.0.7.3 (c) 1998 - 2000, Matej Koss
*    email        : pch@freeshell.org
*
****************************************************************************/

/***************************************************************************
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 ***************************************************************************/


#ifndef _DLGDIRECTORIES_H
#define _DLGDIRECTORIES_H

#include "dlgdirectoriesbase.h"

class DlgDirectories : public DlgDirectoriesBase
{

Q_OBJECT

public:

    DlgDirectories(QWidget * parent);
    ~DlgDirectories() {}
    void applyData();
    void setData();

signals:
    void configChanged();

protected slots:
    void selectEntry(QListViewItem * item);
    void addEntry();
    void deleteEntry();
    void changeEntry();

    void upEntry();
    void downEntry();
    void slotDirectoryChanged( );
protected:
    void updateUpDown();

};

#endif                          // _DLGDIRECTORIES_H
