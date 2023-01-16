#include "widget.h"

#include <QDebug>
#include <QGraphicsView>
#include <QComboBox>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsColorizeEffect>
#include <QPainter>
#include <QPainterPath>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(500, 500);

    grid1 = new QGraphicsView;
    grid2 = new QGraphicsView;

    QHBoxLayout *lay = new QHBoxLayout(this);
    lay->addWidget(grid1);
    lay->addWidget(grid2);


    //    m_shadowEffect = new QGraphicsDropShadowEffect(this);
    //    m_shadowEffect->setColor(QColor(0, 0, 0, 255 * 0.3));
    //    m_shadowEffect->setXOffset(0);
    //    m_shadowEffect->setYOffset(4);
    //    m_shadowEffect->setBlurRadius(12);

    // hide shadow
    //    m_shadowEffect->setEnabled(false);
    //    setGraphicsEffect(m_shadowEffect);


    int shadowsWidth = 5;	// 그림자 영역의 두께, setContentsMargins
    int radius = 1;

    for (int i = 0; i < shadowsWidth; i++) {
        QPainterPath path; // QPainterPath Class를 이용해 곡선을 그릴 수 있게끔 한다.
        path.setFillRule(Qt::WindingFill);
        path.addRoundedRect(shadowsWidth - i, shadowsWidth - i, this->width() - ((shadowsWidth - i) * 2), this->height() - ((shadowsWidth - i) * 2), radius + i, radius + i);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        QColor color(200, 200, 200, 10);	// 적당한 색상 세팅

        m_colorEffect = new QGraphicsColorizeEffect(this);
        m_colorEffect->setColor(QColor(Qt::red));
        m_colorEffect->setEnabled(false);
        setGraphicsEffect(m_colorEffect);

        setMouseTracking(true);
    }
};

Widget::~Widget()
{
}


bool Widget::event(QEvent * e)
{
    switch(e->type())
    {
    //    case QEvent::HoverLeave:
    //        hoverLeave(static_cast<QHoverEvent*>(e));
    //        return true;
    //        break;
    //    case QEvent::HoverMove:
    //        hoverMove(static_cast<QHoverEvent*>(e));
    //        return true;
    //        break;

    case QEnterEvent::HoverEnter:
        enterEvent(static_cast<QEnterEvent*>(e));
        return true;
        break;
    case QEvent::HoverLeave:
        leaveEvent(static_cast<QHoverEvent*>(e));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(e);
}

void Widget::enterEvent(QEnterEvent *e)
{
    QWidget::enterEvent(e);

    m_colorEffect->setEnabled(true);

    //button->setStyleSheet("background:black");
    //grid->setEnabled(true);
    //m_shadowEffect->setEnabled(true);

}

void Widget::leaveEvent(QEvent *e)
{
    QWidget::leaveEvent(e);

    m_colorEffect->setEnabled(false);

    //m_shadowEffect->setEnabled(false);
    //grid->setEnabled(false);

}






//void Widget::hoverLeave(QHoverEvent * event)
//{
//    qDebug("%d", __LINE__);
//    //button->setStyleSheet("frame:yellow");


////    this->setText(QString::number(m_count));
//}

//void Widget::hoverMove(QHoverEvent * event)
//{
////    button->setStyleSheet("background:black");
//    qDebug("%d", __LINE__);
//}

//void Widget::mouseMoveEvent(QMouseEvent *event)
//{
//    //grid->setStyleSheet("border: yellow");

////    qDebug() << QString::number(event->pos().x());
////    qDebug() << QString::number(event->pos().y());
//}







