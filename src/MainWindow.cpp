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

#include "MainWindow.hpp"
#include "Prefs.hpp"

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QDir>

using namespace turtlegui;
namespace turtlegui {

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent) {
    // Init stuff.
    mainMenuBar = new QMenuBar(this);
    fileMenu = new QMenu("&File", this);
    editMenu = new QMenu("&Edit", this);
    utilsMenu = new QMenu("&Utils", this);
    prefsMenu = new QMenu("Prefere&nces", this);
    helpMenu = new QMenu("&Help", this);

    mainMenuBar->addMenu(fileMenu);
    mainMenuBar->addMenu(editMenu);
    mainMenuBar->addMenu(utilsMenu);
    mainMenuBar->addMenu(prefsMenu);
    mainMenuBar->addMenu(helpMenu);

    mainStatusBar = new QStatusBar(this);

    // Default .turtleprefs location.
    guiPrefFile = new PrefsFile(QDir::homePath() + "/turtledoc/gui.turtleprefs");
    this->priv_initGuiFromPrefs();

    this->setStatusBar(mainStatusBar);
    this->setMenuBar(mainMenuBar);
}

MainWindow::~MainWindow() {
    // TODO: ???
    delete mainMenuBar;
    delete fileMenu;
    delete editMenu;
    delete utilsMenu;
    delete prefsMenu;
    delete helpMenu;
}

//////////////////////////////////////////////////////////////////////////////////////

void MainWindow::priv_initGuiFromPrefs() {
    // TODO.
}

}