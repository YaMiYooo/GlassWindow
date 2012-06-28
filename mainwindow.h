#ifndef MAINWINDOW_H
#define MAINWINDOW_H 

#include "bwidget.h"
#include <QDialog>
#include <QPushButton>
#include <QSlider>

class MainWindow:public BWidget{ Q_OBJECT 
	public:
		MainWindow(QWidget *parent=0);
	private slots:
		void SetWindowOpacity(int value);
	private:
		QPushButton *close_button;
		QSlider *opacity_slider;
};

#endif
