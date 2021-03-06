#include "bwidget.h"
#include <QPainter>
#include <QBitmap>
#include <QPalette>

BWidget::BWidget(QWidget *parent):QWidget(parent){
	Init();
}

BWidget::BWidget(WindowType type,QWidget *parent):QWidget(parent){
	Init(type);
}

BWidget::~BWidget(){
	if(background_pix)
		delete background_pix;
	if(min_button)
		delete min_button;
	if(max_button)
		delete max_button;
	if(close_button)
		delete close_button;
	if(corner_buttons)
		delete corner_buttons;
}

void BWidget::Init(WindowType type){
	background_opacity=1.0;
	color=Qt::transparent;
	title="bwidget";

	background_pix=new QPixmap;
	background_pix->load("./images/bg.png");

	QString button_style=(""
			"QPushButton{"
			"background:none;"
			"color:white;"
			"border:none;"
			"}"
			""
			"QPushButton:hover{"
			"color:white;"
			"}"
			""
			"QPushButton:focus{"
			"color:red;"
			"}"
			"");

	min_button=new BButton(tr("v"));
	min_button->setFixedSize(24,24);
	connect(min_button,SIGNAL(clicked()),SLOT(showMinimized()));
	max_button=new BButton(tr("^"));
	max_button->setFixedSize(24,24);
	connect(max_button,SIGNAL(clicked()),SLOT(MaxOrNormalSlot()));
	close_button=new BButton(tr("X"));
	close_button->setFixedSize(24,24);
	connect(close_button,SIGNAL(clicked()),SLOT(close()));

	QHBoxLayout *title_buttons_layout=new QHBoxLayout;
	title_buttons_layout->addWidget(min_button);
	title_buttons_layout->addWidget(max_button);
	title_buttons_layout->addWidget(close_button);

	corner_buttons=new QWidget(this);
	corner_buttons->setLayout(title_buttons_layout);
	switch(type){
		case Normal:
			corner_buttons->resize(90,35);
			break;
		case Dialog:
			max_button->hide();
			corner_buttons->resize(60,35);
			break;
		case Popup:
			min_button->hide();
			max_button->hide();
			corner_buttons->resize(30,35);
			break;
		case Frame:
			min_button->hide();
			max_button->hide();
			close_button->hide();
			corner_buttons->resize(5,35);
			break;
		default:
			qDebug()<<"unknown window type"<<endl;
			break;
	}

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
}

void BWidget::paintEvent(QPaintEvent *event){
	QWidget::paintEvent(event);

	QPixmap *p=new QPixmap;
	*p=background_pix->scaled(window_rect.width(),window_rect.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

	QPainter painter(this);
	/* 画背景 */
	painter.setOpacity(background_opacity);
	painter.drawPixmap(0,0,*p);
	painter.fillRect(0,0,window_rect.width(),window_rect.height(),color);
	/* 画标题 */
	painter.setFont(QFont("",-1,75));
	painter.drawText(5,25,title);
	painter.end();
	setMask(p->mask());
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

	if(event->buttons()==Qt::LeftButton && !this->isMaximized()){
		QPoint new_point=event->globalPos();
		QPoint distance=mapToParent(new_point-old_point);
		this->move(distance);
		old_point=new_point;
	}
}

void BWidget::resizeEvent(QResizeEvent *event){
	QWidget::resizeEvent(event);

	window_rect=geometry();

	int width=corner_buttons->width();
	corner_buttons->move(window_rect.width()-width-5,2);
}

void BWidget::MaxOrNormalSlot(){
	if(isMaximized())
		showNormal();
	else
		showMaximized();
}

void BWidget::SetBackgroundColor(QColor color){
	this->color=color;
}

void BWidget::SetColorOpacity(int alpha){
	if(alpha<0 || alpha>255)
		return ;
	color.setAlpha(alpha);
}

QColor BWidget::GetColor(){
	return color;
}

int BWidget::GetColorAlpha(){
	return color.alpha();
}

void BWidget::SetWindowTitle(QString title_string){
	title=title_string;
}
