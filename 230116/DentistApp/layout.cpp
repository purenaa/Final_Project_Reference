#include "layout.h"

#include <QGridLayout>
#include <QGraphicsView>

#include <QPixmap>
#include <QMouseEvent>
#include <QMessageBox>


Layout::Layout(QWidget *parent)
    : QWidget{parent}
{
    gridLayout();

//    grid1->setStyleSheet("border: 2px solid yellow");




//    QPushButton{
//        color: rgb(58, 134, 255);
//        background-color: white;
//        border: 2px solid rgb(58, 134, 255);
//    }




//    scene1 = new QGraphicsScene;
//    scene2 = new QGraphicsScene;
//    scene3 = new QGraphicsScene;
//    scene4 = new QGraphicsScene;

//    scene1->setBackgroundBrush(Qt::white);
//    scene2->setBackgroundBrush(Qt::white);
//    scene3->setBackgroundBrush(Qt::white);
//    scene4->setBackgroundBrush(Qt::white);

//    grid1->setScene(scene1);
//    grid2->setScene(scene2);
//    grid3->setScene(scene3);
//    grid4->setScene(scene4);
}

/* 2 X 2 Grid */
void Layout::gridLayout()
{
    grid1 = new QGraphicsView;
    grid2 = new QGraphicsView;
    grid3 = new QGraphicsView;
    grid4 = new QGraphicsView;

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(grid1);
    lay1->addSpacing(5);
    lay1->addWidget(grid2);

    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addWidget(grid3);
    lay2->addSpacing(5);
    lay2->addWidget(grid4);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(lay1);
    layout->addSpacing(5);
    layout->addLayout(lay2);
}

//void FramelessResize::DragResize(QEvent *ev)
//{
////    QHoverEvent* e = (QHoverEvent*)ev;
////    QMargins offset;
////    if(_pressDirection & LEFT)
////        offset.setLeft((e->oldPos() - e->pos()).x());
////    if(_pressDirection & RIGHT)
////        offset.setRight((e->pos() - e->oldPos() ).x());
////    if(_pressDirection & TOP)
////        offset.setTop((e->oldPos() - e->pos()).y());
////    if(_pressDirection & BOTTOM)
////        offset.setBottom((e->pos() - e->oldPos() ).y());

////    emit OffsetGeometry(offset);
//}




