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

#ifndef __Prefs_hpp__
#define __Prefs_hpp__

#include <QString>

namespace turtlegui {

class PrefsFile {
public:
    PrefsFile();
    PrefsFile(QString _filePath);
    ~PrefsFile();

    void setFileName(QString _filePath);

    bool newPrefEntry(const QString &prefId, const QString &val);
    bool newPrefEntry(const QString &prefId);
    bool writePrefVal(const QString &prefId, const QString &newVal);
    QString fetchPrefVal(const QString &prefId);

protected:
    QString filePath;

private:
    bool priv_newPrefEntry(const QString &prefId, const QString &val);
};

}

#endif // __Prefs_hpp__