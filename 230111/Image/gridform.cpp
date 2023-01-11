#include "gridform.h"
#include "ui_gridform.h"


GridForm::GridForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GridForm)
{
    ui->setupUi(this);

//    connect(ui->imageRoadButton, SIGNAL(clicked()), this, SLOT(fileLoad()));
//    connect(ui->zoomInToolButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
//    connect(ui->zoomOutToolButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
//    connect(ui->leftToolButton, SIGNAL(clicked()), this, SLOT(leftRotate()));
//    connect(ui->rightToolButton, SIGNAL(clicked()), this, SLOT(rightRotate()));
}

GridForm::~GridForm()
{
    delete ui;
}


