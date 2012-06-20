#include "mainwindow.h"
#include <QApplication>

int main(int argc,char **argv){
	QApplication app(argc,argv);

	BWidget *window=new BWidget();
	window->resize(400,300);
//	MainWindow *window=new MainWindow;
	window->show();

	return app.exec();
}
