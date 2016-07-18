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

#include <QApplication>

using namespace turtlegui;

int main(int argc, char *argv[])
{
    QApplication turtleguiapp(argc, argv); // TODO: probably switch to an own QApplication class?

    MainWindow window;
    window.show();

    int ret = turtleguiapp.exec();
    return ret;
}