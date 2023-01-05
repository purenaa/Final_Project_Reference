#include "function.h"
#include "ui_function.h"

#include <QFileDialog>

#include <QGraphicsView>
#include <QMouseEvent>

Function::Function(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Function)
{
    ui->setupUi(this);

    setAcceptDrops(true);



    ui->zoomInToolButton->setIconSize(QSize(30,30));
    ui->zoomOutToolButton->setIconSize(QSize(30,30));
    ui->leftRotateToolButton->setIconSize(QSize(30,30));
    ui->rightRotateToolButton->setIconSize(QSize(30,30));

    connect(ui->openPushButton, SIGNAL(clicked()), this, SLOT(fileLoad()));
    connect(ui->zoomInToolButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->zoomOutToolButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui->leftRotateToolButton, SIGNAL(clicked()), this, SLOT(leftRotate()));
    connect(ui->rightRotateToolButton, SIGNAL(clicked()), this, SLOT(rightRotate()));

}

Function::~Function()
{
    delete ui;
}

void Function::fileLoad()
{
    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");

    QImage *imgSize = new QImage(filePath);
    QPixmap buf = QPixmap::fromImage(*imgSize);
    buf = buf.scaled(imgSize->width(), imgSize->height());

    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(buf);
    ui->graphicsView->setScene(scene);

    //ui->graphicsView2->setScene(scene);

}

void Function::zoomIn()
{
    ui->graphicsView->scale(1.25,1.25);
}

void Function::zoomOut()
{
    ui->graphicsView->scale(0.8, 0.8);
}

void Function::leftRotate()
{
    ui->graphicsView->rotate(90);
}

void Function::rightRotate()
{
    ui->graphicsView->rotate(-90);
}

void Function::on_sizePushButton_clicked(QPixmap buf)
{
}

