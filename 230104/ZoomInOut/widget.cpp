#include <QMenuBar>
#include <QApplication>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QMenuBar *menubar = new QMenuBar(this);

    QAction *
}

Widget::~Widget()
{
}

void Widget::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    zoomInAct = viewMenu->addAction(tr("Zoom &In (25%)"), this, &ImageViewer::zoomIn);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);
    zoomInAct->setEnabled(false);

}
