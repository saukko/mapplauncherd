/* * This file is part of calc application *
 *
 * Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * Contact: Abhijit Apte <abhijit.apte@nokia.com>
 *
 * This software, including documentation, is protected by copyright
 * controlled by Nokia Corporation. All rights are reserved. Copying,
 * including reproducing, storing, adapting or translating, any or all of
 * this material requires the prior written consent of Nokia Corporation.
 * This material also contains confidential information which may not be
 * disclosed to others without the prior written consent of Nokia.
 */

#ifndef CALCULATIONLINEWIDGETITEMVIEW_H
#define CALCULATIONLINEWIDGETITEMVIEW_H

#include <MWidgetView>
#include <MLocale>
#include <MCalendar>

#include "calculationlinewidgetmodel.h"
#include "calculationlinewidgetstyle.h"


class CalculationLineWidgetViewPrivate;
class CalculationLineWidget;

class QGraphicsSceneResizeEvent;

/*!
 * \class CalculationLineWidgetView
 * \brief CalculationLineWidgetView implements a view for the calculationlinewidget widget
 *
 * CalculationLineWidgetView draws a fixed background and icon and text
 * on top of it. Pressing he bell button will set/reset the calculationlinewidget.
 */
class M_EXPORT CalculationLineWidgetView : public MWidgetView
{
	Q_OBJECT
	M_VIEW(CalculationLineWidgetModel, CalculationLineWidgetStyle)
	friend class CalculationLineWidgetViewPrivate;

public:
	/*!
	 * \brief Constructor
	 * \param controller Pointer to the calculationlinewidget's controller
	 */
	CalculationLineWidgetView(CalculationLineWidget *controller);

	virtual ~CalculationLineWidgetView();

	virtual void resizeEvent(QGraphicsSceneResizeEvent * event);

	virtual QRectF boundingRect () const;
	virtual void updateSize();
	virtual QPainterPath shape() const;
	virtual void resize(qreal w, qreal h);

 protected:
	//! \reimp
	//virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF & constraint = QSizeF()) const;
	virtual void drawBackground(QPainter* painter, const QStyleOptionGraphicsItem* option) const;

	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	void setSelected(bool selected);

	virtual void applyStyle();
	virtual void setupModel();
	//! \reimp_end

 protected slots:
	virtual void updateData(const QList<const char*>& modifications);

 signals:
	/*!
	 * \brief Signals that the clock has been released
	 */
	void clicked(void);

 private:
	
	Q_DISABLE_COPY(CalculationLineWidgetView)

	CalculationLineWidgetViewPrivate *d_ptr;

	void organizeCalculationLineWidgetLayout();

};

#endif