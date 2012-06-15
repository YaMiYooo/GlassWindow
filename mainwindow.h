#ifndef MAINWINDOW_H
#define MAINWINDOW_H 

#include "bwidget.h"
#include <QSlider>
#include <QLabel>

class MainWindow:public BWidget{ Q_OBJECT 
	public:
		MainWindow(QWidget *parent=0);
	private slots:
		void SetWindowOpacity(int value);
	private:
		BButton *close_button;
		QSlider *opacity_slider;
		QLabel *alpha_label;
};

#endif
