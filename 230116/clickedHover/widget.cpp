#include "widget.h"

#include <QPainter>
#include <QEvent>
#include <QEnterEvent>
#include <QPainterPath>
#include <QPainter>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // frameless를 위해 선언
        //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

        // 그림자 영역 부분을 그리기 위한 마진을 준다. 아래 그림자두께 변수와 같은 값
        this->setContentsMargins(20, 20, 20, 20);
        this->setAttribute(Qt::WA_TranslucentBackground);
        //this->setModal(true);
        this->installEventFilter(this);

//        // Dialog가 focus in/out 됐을 경우를 구분하기 위해 signal/slot connect.
        connect(qApp, &QguiApplication::applicationStateChanged, this, [&]() {
            switch(state) {
            case Qt::Application::ApplicationActive:
                alpha = 150;	// 멤버변수. 적당한 값을 세팅하자.
                break;
            case Qt::Application::ApplicationInactive:
                alpha = 100;	// inactive 됐을 때 더 연해져야 해서 active 보다 더 적게 세팅
                break;
            default:
                break;
            }
        });

//    button->setContentsMargins(20, 20, 20, 20);
//    button->setAttribute(Qt::WA_TranslucentBackground);
//    button->installEventFilter(this);
}

Widget::~Widget()
{
}

//bool Widget::event(QEvent * e)
//{
//    switch(e->type())
//    {
//    case QEnterEvent::HoverEnter:
//        enterEvent(static_cast<QEnterEvent*>(e));
//        return true;
//        break;
//    case QEvent::HoverLeave:
//        leaveEvent(static_cast<QHoverEvent*>(e));
//        return true;
//        break;
//    default:
//        break;
//    }
//    return QWidget::event(e);
//}


//void Widget::enterEvent(QEnterEvent *e)
//{
//    QWidget::enterEvent(e);
//}

//void Widget::leaveEvent(QEvent *e)
//{
//    QWidget::leaveEvent(e);
//}


// eventFilter를 재정의, paintEvent를 재정의해도 무방하다.
bool Widget::eventFilter(QObject* obj, QEvent* event) {
  if (event->type() == QEvent::Paint) {
    int shadowsWidth = 5;	// 그림자 영역의 두께, setContentsMargins
    int radius = 1;		// Dialog Window의 border radius 값이라고 생각하면 된다.
                    // 원하는 radius 값을 넣어주면 된다.


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
//    QColor color(200, 200, 200, 10);	// 적당한 색상 세팅
    QColor color(Qt::yellow);

    // 그림자 영역을 넓혀가며 그림자를 그린다. 넓혀질수록 alpha값을 조절하여 gradient 처리를 한다.
    for (int i = 0; i < shadowsWidth; i++) {
      QPainterPath path; // QPainterPath Class를 이용해 곡선을 그릴 수 있게끔 한다.
      path.setFillRule(Qt::WindingFill);
      path.addRoundedRect(shadowsWidth - i, shadowsWidth - i, this->width() - ((shadowsWidth - i) * 2), this->height() - ((shadowsWidth - i) * 2), radius + i, radius + i);

      // application의 state가 변경될 때 마다 paintEvent가 다시 호출되므로, 그때마다 적정한 alpha값으로 세팅한다.
      color.setAlpha(alpha - qSqrt(i) * 50);
      painter.setPen(color);
      painter.drawPath(path);
    }
  }
  return QWidget::eventFilter(obj, event);
}

