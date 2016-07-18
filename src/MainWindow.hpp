// This file is part of TurtleDoc.
// Copyright (c) 2016 Jan Kowalewicz.
//
// @GPL_LICENSE_HEAD_START
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// @GPL_LICENSE_HEAD_END

#ifndef __MainWindow_hpp__
#define __MainWindow_hpp__

#include "Prefs.hpp"

#include <QMainWindow>
#include <QObject>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>

namespace turtlegui {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget * parent = 0);
    ~MainWindow();

private:
    // The menubar and the menus are currently private, I think thats ok.
    QMenuBar *mainMenuBar;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *utilsMenu;
    QMenu *prefsMenu;
    QMenu *helpMenu;

    QStatusBar *mainStatusBar;

    PrefsFile *guiPrefFile;

    void priv_initGuiFromPrefs();
};

}

#endif // __MainWindow_hpp__