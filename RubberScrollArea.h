/******************************************************************************************
**  Copyright 2023 Hangzhou Zhicun (Witmem) Technology Co., Ltd.  All rights reserved.   **
**                                                                                       **
**  This program is free software: you can redistribute it and/or modify                 **
**  it under the terms of the GNU General Public License as published by                 **
**  the Free Software Foundation, either version 3 of the License, or                    **
**  (at your option) any later version.                                                  **
**                                                                                       **
**  This program is distributed in the hope that it will be useful,                      **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of                       **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                        **
**  GNU General Public License for more details.                                         **
**                                                                                       **
**  You should have received a copy of the GNU General Public License                    **
**  along with this program.  If not, see http://www.gnu.org/licenses/.                  **
*******************************************************************************************/

#ifndef RUBBERVIEW_H
#define RUBBERVIEW_H

#include <QScrollArea>

#include <QRubberBand>
#include <QMouseEvent>
#include <QCheckBox>


class RubberScrollArea : public QScrollArea
{
    Q_OBJECT
public:
	RubberScrollArea(QWidget* parent = nullptr);
	~RubberScrollArea();


	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);

private:
    QRubberBand* m_pRubberBand = nullptr;
    QPoint m_qOriginWidget;
    bool m_bReChangeRubberRange{ false };

	void moveRubberRange(QMouseEvent* e);
signals:
    void  signalSelectAllcheckbox(bool isChecked);

public:
	QList<QCheckBox*> m_checkList;
};

#endif // RUBBERVIEW_H
