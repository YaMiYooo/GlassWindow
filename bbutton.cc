#include "bbutton.h"
#include <QPainter>
#include <QLabel>

BButton::BButton(QWidget *parent):QPushButton(parent){
	Init();
}

BButton::BButton(QString text,QWidget *parent):QPushButton(parent){
	setText(text);
	Init();
}

BButton::~BButton(){
	if(normal_pix)
		delete normal_pix;
	if(hover_pix)
		delete hover_pix;
	if(focus_pix)
		delete focus_pix;
	if(bg_pix)
		delete bg_pix;
}

void BButton::Init(){
	normal_pix=new QPixmap;
	normal_pix->load("./images/button.png");

	hover_pix=new QPixmap;
	hover_pix->load("./images/buttonHover.png");

	focus_pix=new QPixmap;
	focus_pix->load("./images/buttonFocus.png");

	bg_pix=new QPixmap;

	this->setStyleSheet(""
			"QPushButton{"
			"background:transparent;"
			"color:#000000;"
			"font-weight:bold;"
			"border:none;"
			"}"
			""
			"QPushButton:hover,"
			"QPushButton:focus{"
			"color:red;"
			"}"
			"");
}

void BButton::paintEvent(QPaintEvent *event){
	QPushButton::paintEvent(event);

	QPainter painter(this);
	painter.drawPixmap(0,0,*bg_pix);
	painter.end();
}

void BButton::enterEvent(QEvent *event){
	QPushButton::enterEvent(event);

	*bg_pix=hover_pix->scaled(window_rect.width(),window_rect.height(),
			Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
}

void BButton::leaveEvent(QEvent *event){
	QPushButton::leaveEvent(event);

	*bg_pix=normal_pix->scaled(window_rect.width(),window_rect.height(),
			Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
}

void BButton::mousePressEvent(QMouseEvent *event){
	QPushButton::mousePressEvent(event);

	*bg_pix=focus_pix->scaled(window_rect.width(),window_rect.height(),
			Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
}

void BButton::mouseReleaseEvent(QMouseEvent *event){
	QPushButton::mouseReleaseEvent(event);

	*bg_pix=normal_pix->scaled(window_rect.width(),window_rect.height(),
			Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
}

void BButton::resizeEvent(QResizeEvent *event){
	QPushButton::resizeEvent(event);

	window_rect=geometry();
	*bg_pix=normal_pix->scaled(window_rect.width(),window_rect.height(),
			Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
}
