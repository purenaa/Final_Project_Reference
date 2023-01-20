#include "view.h"
#include "qgraphicsview.h"

#include <QWidget>

View::View(QWidget *parent)
    : QWidget{parent}
{
    newView = new QGraphicsView(this);
    newScene = new QGraphicsScene;
    newScene->setBackgroundBrush(Qt::black);
    newView->setScene(newScene);
}
