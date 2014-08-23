/*
    Copyright (c) 2014, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "fileclass.h"

#include <QDir>

COPYQ_DECLARE_SCRIPTABLE_CLASS(FileClass)

FileClass::FileClass(const QString &currentPath, QScriptEngine *engine)
    : ScriptableClass(engine)
    , m_currentPath(currentPath)
{
}

QScriptValue FileClass::newInstance(const QString &path)
{
    return ScriptableClass::newInstance( new QFile(QDir(m_currentPath).absoluteFilePath(path)) );
}

const QString &FileClass::getCurrentPath() const
{
    return m_currentPath;
}

void FileClass::setCurrentPath(const QString &path)
{
    m_currentPath = path;
}

QScriptValue FileClass::createInstance(const QScriptContext &context)
{
    QScriptValue arg = context.argument(0);
    return newInstance(arg.toString());
}