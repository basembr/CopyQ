/*
    Copyright (c) 2018, Lukas Holecek <hluk@email.cz>

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

#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QObject>
#include <QString>

class QWidget;

/**
 * Opens native file dialog (unlike QFileDialog).
 */
class FileDialog : public QObject
{
    Q_OBJECT
public:
    FileDialog(QWidget *parent, const QString &caption, const QString &fileName);

signals:
    void fileSelected(const QString &fileName);

public slots:
    void exec();

private:
    QWidget *m_parent;
    QString m_caption;
    QString m_defaultPath;
};

#endif // FILEDIALOG_H
