#ifndef BWIDGET_H
#define BWIDGET_H 

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QMouseEvent>

class BWidget:public QWidget{ Q_OBJECT
	public:
		BWidget(QWidget *parent=0);
		virtual void SetBackgroundOpacity(qreal opacity);
	protected:
		void paintEvent(QPaintEvent *event);
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
	private:
		QPixmap *background_pix;

		qreal background_opacity;
		QPoint old_point;
};

#endif
