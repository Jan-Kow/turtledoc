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


/*
TODO: Would be nice if someone could take the
    if (!checkFile.exists())
stuff into an own inline function. Currently to busy to do this.
*/

#include "Prefs.hpp"

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

using namespace turtlegui;
namespace turtlegui {

PrefsFile::PrefsFile() { }

PrefsFile::PrefsFile(QString _filePath) : filePath(_filePath) { }

PrefsFile::~PrefsFile() { }

void PrefsFile::setFileName(QString _filePath) {
    this->filePath = _filePath;
}

bool PrefsFile::newPrefEntry(const QString &prefId, const QString &val) {
    return this->priv_newPrefEntry(prefId, val);
}

bool PrefsFile::newPrefEntry(const QString &prefId) {
    return this->priv_newPrefEntry(prefId, "NULL");
}

bool PrefsFile::writePrefVal(const QString &prefId, const QString &newVal) {
    if (filePath == NULL)
        return false;

    QString cnt;
    QFileInfo checkFile(filePath);
    if (!checkFile.exists()) {
        return false;
    } else {
        QString oldVal = this->fetchPrefVal(prefId);
        QFile f(filePath);
        if (f.open( QIODevice::ReadWrite )) {
            QTextStream rd(&f);
            cnt = rd.readAll();
        }
        f.resize(0); //truncate
        f.close();

        QString oldL(prefId + " " + oldVal);
        QString newL(prefId + " " + newVal);
        cnt.replace(oldL, newL);

        if (f.open( QIODevice::ReadWrite )) {
            QTextStream wr(&f);
            wr << cnt;
            return true;
        }
    }
}

QString PrefsFile::fetchPrefVal(const QString &prefId) {
    if (filePath == NULL)
        return NULL;

    QFileInfo checkFile(filePath);
    if (!checkFile.exists()) {
        return NULL;
    } else {
        QFile f(filePath);
        if (f.open( QIODevice::ReadOnly )) {
            QTextStream rd(&f);
            while (!rd.atEnd()) {
                QString l= rd.readLine();
                QString id(prefId + " ");
                int idpos = l.indexOf(id);
                if (idpos >= 0) {
                    QString res = l.mid(idpos + id.length());
                    return res;
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////

bool PrefsFile::priv_newPrefEntry(const QString &prefId, const QString &val) {
    if (filePath == NULL)
        return false;

    QFileInfo checkFile(filePath);
    if (!checkFile.exists()) {
        return false;
    } else {
        QFile f(filePath);
        QString appendLine(prefId + " " + val);
        if (f.open( QIODevice::Append )) {
            QTextStream wr(&f);
            wr << "\n" << appendLine;
            return true;
        }
    }
}

}
