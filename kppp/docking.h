/*
 *              kPPP: A pppd Front End for the KDE project
 *
 * $Id: docking.h 212185 2003-03-07 22:11:39Z waba $
 *
 *              Copyright (C) 1997 Bernd Johannes Wuebben
 *                      wuebben@math.cornell.edu
 *
 * This file was contributed by Harri Porten <porten@tu-harburg.de>
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */


#ifndef _DOCKING_H_
#define _DOCKING_H_

#include <qpixmap.h>
#include <ksystemtray.h>

class PPPStats;

class DockWidget : public KSystemTray {
  Q_OBJECT
public:
  DockWidget(QWidget * parent, const char *name, PPPStats *st);
  ~DockWidget();

protected:
  void paintEvent(QPaintEvent *e);
  void showEvent(QShowEvent *) { }

private slots:
  void toggle_window_state();
  void mousePressEvent(QMouseEvent *e);

public slots:
  void paintIcon(int);
  void take_stats();
  void stop_stats();

public:
  static DockWidget *dock_widget;

private:
  int toggleID;
  PPPStats *stats;

  KPopupMenu *popup_m;

  QPixmap dock_none_pixmap;
  QPixmap dock_left_pixmap;
  QPixmap dock_right_pixmap;
  QPixmap dock_both_pixmap;
};

#endif
