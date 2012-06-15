#ifndef BBUTTON_H
#define BBUTTON_H 

#include <QPushButton>
#include <QPixmap>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QEvent>
#include <QResizeEvent>

class BButton:public QPushButton{ Q_OBJECT
	public:
		explicit BButton(QWidget *parent=0);
		explicit BButton(QString text,QWidget *parent=0);
		~BButton();
	protected:
		void Init();
		void enterEvent(QEvent *event);
		void leaveEvent(QEvent *event);
		void mousePressEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		void resizeEvent(QResizeEvent *event);
		void paintEvent(QPaintEvent *event);
	private:
		QPixmap *normal_pix;
		QPixmap *hover_pix;
		QPixmap *focus_pix;
		QPixmap *bg_pix;

		QRect window_rect;
};

#endif
