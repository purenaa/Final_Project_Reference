#include "widget.h"
#include "view.h"

#include <QDebug>
#include <QGraphicsView>
#include <QComboBox>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsColorizeEffect>
#include <QPainter>
#include <QPainterPath>

#include <QPointF>
#include <QGraphicsScene>
#include <QDialog>

#include <QMoveEvent>
#include <QPushButton>
#include <QGraphicsSceneEvent>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 500);

    grid1 = new QGraphicsView(this);
    grid1->setGeometry(100, 100, 200, 200);
    scene1 = new QGraphicsScene;
    grid1->setScene(scene1);
    scene1->setBackgroundBrush(Qt::black);

    grid2 = new QGraphicsView(this);
    grid2->setGeometry(400, 100, 200, 200);
    scene2 = new QGraphicsScene;
    grid2->setScene(scene2);
    scene2->setBackgroundBrush(Qt::black);


    QPushButton * viewQuit = new QPushButton("X", this);
    //viewQuit->setStyleSheet("color: white");
    viewQuit->setStyleSheet("background:rgb(255, 255, 255)");

//    /* grid1(graphicsView) 의 좌표값 */
//    int x1 = grid1->pos().x();                 // grid1의 topLeft의 x 좌표값
//    int y1 = grid1->pos().y();                 // grid1의 topLeft의 y 좌표값
//    int width1 = x1 + grid1->width();          // grid1의 topLeft의 x좌표값에서 grid의 폭만큼 이동한 x의 좌표값
//    int height1 = y1 + grid1->height();        // grid1의 topLeft의 y 좌표값에서 grid의 높이만큼 이동한 y의 좌표값

//    /* grid2(graphicsView) 의 좌표값 */
//    int x2 = grid2->pos().x();
//    int y2 = grid2->pos().y();
//    int width2 = x2 + grid2->width();
//    int height2 = y2 + grid2->height();

//    qDebug("grid1의 TopLeft : (%d, %d)", x1, y1);
//    qDebug("grid1의 TopRight : (%d, %d)", width1, y1);
//    qDebug("grid1의 ButtomLeft : (%d, %d)", x1, height1);
//    qDebug("grid1의 ButtomRight : (%d, %d)\n", width1, height1);

//    qDebug("grid2의 TopLeft : (%d, %d)", x2, y2);
//    qDebug("grid2의 TopRight : (%d, %d)", width2, y2);
//    qDebug("grid2의 ButtomLeft : (%d, %d)", x2, height2);
//    qDebug("grid2의 ButtomRight : (%d, %d)\n", width2, height2);


    //setMouseTracking(true);             // mouseMoveEvent에서 마우스를 클릭하지 않고 이동해도 좌표값이 나타나게 해줌.

//    this->grid1->setStyleSheet("border: 10px solid blue");
    //grid1->setEnabled(false);
//    grid2->setEnabled(false);
}


Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Pressed" << event->pos();

    if(event->button() == Qt::LeftButton) {
        clickPoint = event->pos();
        c = true;
        if(c == true) {
            if((clickPoint.x() >= 100 && clickPoint.x() <= 300) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//                grid1->setEnabled(true);
                this->grid1->setStyleSheet("border: 5px solid red");

//                grid2->setEnabled(true);
                this->grid2->setStyleSheet("border: 0px");
                qDebug("scene1 clicked 1");
            }
            else if((clickPoint.x() >= 400 && clickPoint.x() <= 600) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//                grid2->setEnabled(true);
                this->grid2->setStyleSheet("border: 5px solid blue");

//                grid1->setEnabled(true);
                this->grid1->setStyleSheet("border: 0px");
                qDebug("scene2 clicked 2");
            }
        }
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    //qDebug() << "Mouse mouseReleaseEvent" << event->pos();

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mouse mouseMoveEvent" << "\n" << event->pos();

//    c = true;

//    if(c == true){
//        clickPoint = event->pos();
//        if((clickPoint.x() >= 100 && clickPoint.x() <= 300) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//            this->grid1->setStyleSheet("border: 5px solid red");

//            this->grid2->setStyleSheet("border: 0px");
//        }

//        else if((clickPoint.x() >= 400 && clickPoint.x() <= 600) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//            this->grid2->setStyleSheet("border: 5px solid blue");

//            this->grid1->setStyleSheet("border: 0px");
//        }
//    }




//        qDebug() << QString::number(event->pos().x());
//        qDebug() << QString::number(event->pos().y());

//    if(!(clickPoint.x() >= 100 && clickPoint.x() <= 300) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//        grid1->setEnabled(false);
//    }
}


void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        clickPoint = event->pos();

        if((clickPoint.x() >= 100 && clickPoint.x() <= 300) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
            qDebug("Double clicked 11111");
//            QWidget *get = new QWidget;
//            customView = new QGraphicsView;
//            customScene = new QGraphicsScene;
//            customScene->setBackgroundBrush(Qt::black);
//            customView->setScene(customScene);
//            QHBoxLayout *box = new QHBoxLayout(this);
//            box->addWidget(customView);

//            get->setLayout(box);
//            get->show();



            //customView->show();
            customView = new QGraphicsView(this);
            customScene = new QGraphicsScene;
            customScene->setBackgroundBrush(Qt::black);;
            customView->setGeometry(100, 100, 500, 300);
            customView->show();

//            QGraphicsScene *s = new QGraphicsScene;
//            newView->setScene(s);
        }

        if((clickPoint.x() >= 400 && clickPoint.x() <= 600) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
            qDebug("Double clicked 22222");
        }
    qDebug() << "Mouse mouseDoubleClickEvent" << event->pos();
}



void Widget::enterEvent(QEnterEvent *event)
{
    QWidget::enterEvent(event);

//    grid1->setEnabled(true);
//    this->grid1->setStyleSheet("border: 10px solid red");

    //qDebug() << "enterEvent" << event->pos();



//    this->scene1->setBackgroundBrush(Qt::red);
//    this->scene2->setBackgroundBrush(Qt::red);

//    clickPoint = event->pos();
//    if((clickPoint.x() >= 100 && clickPoint.x() <= 300) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//        //this->scene1->setBackgroundBrush(Qt::red);
//        c = true;
//        this->grid1->setStyleSheet("border: 10px solid red");
//        qDebug() << "scene1 hover" << event->pos();
//        c = false;
//    }

//        if(event->button() == Qt::LeftButton) {
//            clickPoint = event->pos();

//            if((clickPoint.x() >= 400 && clickPoint.x() <= 600) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//                this->scene2->setBackgroundBrush(Qt::red);
//                qDebug() << "scene2 hover" << event->pos();
//            }
}


void Widget::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);

    //grid1->setEnabled(true);
    this->grid1->setStyleSheet("border: 0px");
    this->grid2->setStyleSheet("border: 0px");


//    if((clickPoint.x() >= 100 && clickPoint.x() <= 300) && (clickPoint.y() >= 100 && clickPoint.y() <= 300)) {
//        grid1->setEnabled(true);
//        this->grid1->setStyleSheet("border: 0px");
//        qDebug("scene1 clicked 1");
//    }

//    this->grid1->setStyleSheet("border: 0px, solid black");
    //this->scene1->setBackgroundBrush(Qt::yellow);
    //this->scene2->setBackgroundBrush(Qt::yellow);

    //qDebug() << "leaveEvent" << "\n";

}

void Widget::changeEvent(QEvent *event)
{
    //QMainWindow::changeEvent(event);
    QWidget::changeEvent(event);

#ifndef Q_OS_MAC // Ignored on Mac
    if(event->type() == QEvent::WindowStateChange)                  // 윈도우 창 변경 (최소화, 최대화)
    {
        qDebug("window Changed");

//        if(clientModel && clientModel->getOptionsModel()->getMinimizeToTray())
//        {
//            QWindowStateChangeEvent *wsevt = static_cast<QWindowStateChangeEvent*>(event);
//            if(!(wsevt->oldState() & Qt::WindowMinimized) && isMinimized())
//            {
//                QTimer::singleShot(0, this, SLOT(hide()));
//                e->ignore();
//            }
//        }
    }


#endif
}

//bool Widget::eventFilter(QObject *obj, QEvent *event) {
//  if (event->type() == QEvent::Resize /*&& obj == ui_.dockWidget*/) {
//      QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);
//      qDebug("Dock Resized (New Size) - Width: %d Height: %d",
//             resizeEvent->size().width(),
//             resizeEvent->size().height());
//  }
//  return QWidget::eventFilter(obj, event);
//}

void Widget::resizeEvent(QResizeEvent * event)
{
    qDebug("widget changed");
}



//bool Widget::event(QEvent * e)
//{
//    switch(e->type())
//    {


//    case QEvent::HoverEnter:
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


//bool Widget::event(QEvent * e)
//{
//    switch(e->type())
//    {
//    //    case QEvent::HoverLeave:
//    //        hoverLeave(static_cast<QHoverEvent*>(e));
//    //        return true;
//    //        break;
//    //    case QEvent::HoverMove:
//    //        hoverMove(static_cast<QHoverEvent*>(e));
//    //        return true;
//    //        break;

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

//{
//

//    QPushButton *button = new QPushButton;

//

//    grid1->setEnabled(false);


//    //    m_shadowEffect = new QGraphicsDropShadowEffect(this);
//    //    m_shadowEffect->setColor(QColor(0, 0, 0, 255 * 0.3));
//    //    m_shadowEffect->setXOffset(0);
//    //    m_shadowEffect->setYOffset(4);
//    //    m_shadowEffect->setBlurRadius(12);

//    // hide shadow
//    //    m_shadowEffect->setEnabled(false);
//    //    setGraphicsEffect(m_shadowEffect);


//    int shadowsWidth = 5;	// 그림자 영역의 두께, setContentsMargins
//    int radius = 1;

//    for (int i = 0; i < shadowsWidth; i++) {
//        QPainterPath path; // QPainterPath Class를 이용해 곡선을 그릴 수 있게끔 한다.
//        path.setFillRule(Qt::WindingFill);
//        path.addRoundedRect(shadowsWidth - i, shadowsWidth - i, this->width() - ((shadowsWidth - i) * 2), this->height() - ((shadowsWidth - i) * 2), radius + i, radius + i);

//        QPainter painter(this);
//        painter.setRenderHint(QPainter::Antialiasing, true);
//        QColor color(200, 200, 200, 10);	// 적당한 색상 세팅

//        m_colorEffect = new QGraphicsColorizeEffect(this);
//        m_colorEffect->setColor(QColor(Qt::red));
//        m_colorEffect->setEnabled(false);
//        setGraphicsEffect(m_colorEffect);

//        setMouseTracking(true);
//    }
//};

//void Widget::enterEvent(QEnterEvent *e)
//{
//    QWidget::enterEvent(e);

////    m_colorEffect->setEnabled(true);
//    grid1->setEnabled(true);
//    qDebug("Test");

//}

//void Widget::leaveEvent(QEvent *e)
//{
//    QWidget::leaveEvent(e);

////    m_colorEffect->setEnabled(false);
//}




////void Widget::hoverLeave(QHoverEvent * event)
////{
////    qDebug("%d", __LINE__);
////    //button->setStyleSheet("frame:yellow");


//////    this->setText(QString::number(m_count));
////}

////void Widget::hoverMove(QHoverEvent * event)
////{
//////    button->setStyleSheet("background:black");
////    qDebug("%d", __LINE__);
////}

//void Widget::mouseMoveEvent(QMouseEvent *event)
//{
//    //grid->setStyleSheet("border: yellow");

//    qDebug("x 좌표 : %d", event->pos().x());
//    qDebug("y 좌표 : %d\n", event->pos().y());
//}

//void Widget::mousePressEvent(QMouseEvent *event)
//{
//    qDebug("click Test");

//}








