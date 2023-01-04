#include "widget.h"
#include "ui_widget.h"

#include <QMenu>
#include <QList>
#include <QMouseEvent>
//#include <QPixmap>
//#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 1000 << 1000;
    ui->splitter->setSizes(sizes);

    QString imagePath(tr("CAT"));         //이미지 경로
    QPixmap* selectImage = new QPixmap(imagePath);
    ui->imageLabel->setPixmap(*selectImage);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createActions()
{
    zoomInAct = (tr("Zoom &In (25%)"), this, &ImageViewer::zoomIn);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);
    zoomInAct->setEnabled(false);
}

void Widget::scaleImage(double factor)
//! [23] //! [24]
{
    scaleFactor *= factor;
    ui->imageLabel->resize(scaleFactor * ui->imageLabel->pixmap(Qt::ReturnByValue).size());

//    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
//    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void Widget::on_pushButton_zoomIn_clicked()
{
    scaleImage(1.25);
}




//// function for mouse move events
//void Widget::mouseMoveEvent (QMouseEvent* event) {
//    static int curY = 0, prevY = 0;         // 현재 Y 좌표 위치, 이전 Y 좌표 위치
//    if (event->buttons()) {
//        curY = event->pos().y(); // current position of Y
//    }
//    else((curY - prevY) > 0 ); // call zoom in function
//    prevY = curY;
//}
