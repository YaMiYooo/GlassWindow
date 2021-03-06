#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent):BWidget(parent){
	close_button=new BButton(tr("close"));
	connect(close_button,SIGNAL(clicked()),SLOT(close()));

	dialog_button=new BButton(tr("dialog"));
	connect(dialog_button,SIGNAL(clicked()),SLOT(PopupDialogSlot()));

	opacity_slider=new QSlider(Qt::Horizontal);
	opacity_slider->setRange(0,100);
	opacity_slider->setValue(100);
	connect(opacity_slider,SIGNAL(valueChanged(int)),SLOT(SetWindowOpacity(int)));

	alpha_label=new QLabel(tr("100"));

	QHBoxLayout *main_layout=new QHBoxLayout;
	main_layout->addWidget(opacity_slider);
	main_layout->addWidget(alpha_label);
	main_layout->addWidget(close_button);
	main_layout->addWidget(dialog_button);

	setLayout(main_layout);
	SetWindowTitle("this is the glass window for ley");
	resize(400,300);
}

void MainWindow::SetWindowOpacity(int value){
	qreal opacity=(qreal)value/100.0;
	//SetBackgroundOpacity(opacity);
	alpha_label->setText(QString::number(this->GetColorAlpha()));
	update();
}

void MainWindow::PopupDialogSlot(){
	BWidget *dialog=new BWidget(BWidget::Dialog);
	dialog->resize(400,300);
	dialog->show();
}
