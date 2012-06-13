#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent):BWidget(parent){
	close_button=new QPushButton(tr("close"));
	connect(close_button,SIGNAL(clicked()),SLOT(close()));

	opacity_slider=new QSlider(Qt::Horizontal);
	opacity_slider->setRange(50,100);
	opacity_slider->setValue(1000);
	connect(opacity_slider,SIGNAL(valueChanged(int)),SLOT(SetWindowOpacity(int)));

	QHBoxLayout *main_layout=new QHBoxLayout;
	main_layout->addWidget(opacity_slider);
	main_layout->addWidget(close_button);

	setLayout(main_layout);
	resize(400,300);
}

void MainWindow::SetWindowOpacity(int value){
	qreal opacity=(qreal)value/100.0;
	//this->setWindowOpacity(opacity);
	SetBackgroundOpacity(opacity);
	update();
}
