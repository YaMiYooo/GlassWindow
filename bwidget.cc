#include "bwidget.h"
#include <QPainter>

BWidget::BWidget(QWidget *parent):QWidget(parent){
	background_opacity=1.0;

	background_pix=new QPixmap;
	background_pix->load("./images/bg.jpg");

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
}

void BWidget::paintEvent(QPaintEvent *event){
	QWidget::paintEvent(event);

	QRect sz=geometry();
	QPixmap *p=new QPixmap;
	*p=background_pix->scaled(sz.width(),sz.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

	QPainter painter(this);
	painter.setOpacity(background_opacity);
	painter.drawPixmap(0,0,*p);
	painter.end();
	delete p;
}

void BWidget::SetBackgroundOpacity(qreal opacity){
	background_opacity=opacity;
}

void BWidget::mousePressEvent(QMouseEvent *event){
	QWidget::mousePressEvent(event);

	old_point=event->globalPos();
}

void BWidget::mouseMoveEvent(QMouseEvent *event){
	QWidget::mouseMoveEvent(event);

	if(event->buttons()==Qt::LeftButton){
		QPoint new_point=event->globalPos();
		QPoint distance=mapToParent(new_point-old_point);
		this->move(distance);
		old_point=new_point;
	}
}
