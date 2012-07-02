#ifndef MAINWINDOW_H
#define MAINWINDOW_H 

#include "bwidget.h"
#include <QDialog>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

class MainWindow:public BWidget{ Q_OBJECT 
	public:
		MainWindow(QWidget *parent=0);
	private slots:
		void SetWindowOpacity(int value);
		void PopupDialogSlot();
	private:
		BButton *close_button;
		BButton *dialog_button;
		QSlider *opacity_slider;
		QLabel *alpha_label;
};

#endif
