#ifndef BWIDGET_H
#define BWIDGET_H 

#include "bbutton.h"
#include <QBoxLayout>
#include <QtDebug>

class BWidget:public QWidget{ Q_OBJECT
	Q_ENUMS(WindowType)
	public:
		enum WindowType { Normal,Dialog,Popup,Frame };
		explicit BWidget(QWidget *parent=0);
		explicit BWidget(WindowType type,QWidget *parent=0);
		~BWidget();
		virtual void SetBackgroundOpacity(qreal opacity);
		virtual void SetBackgroundColor(QColor color);
		virtual void SetColorOpacity(int alpha);
		void SetWindowTitle(QString title_string);
		QColor GetColor();
		int GetColorAlpha();
	protected:
		void Init(WindowType type=Normal);
		void paintEvent(QPaintEvent *event);
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void resizeEvent(QResizeEvent *event);
	private slots:
		void MaxOrNormalSlot();
	private:
		QPixmap *background_pix;
		QColor color;

		qreal background_opacity;
		QPoint old_point;
		BButton *min_button;
		BButton *max_button;
		BButton *close_button;
		QWidget *corner_buttons;

		QRect window_rect;
		QString title;
};

#endif
