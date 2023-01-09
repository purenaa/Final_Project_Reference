#include "imagemanagementform.h"
#include "ui_imagemanagementform.h"

ImageManagementForm::ImageManagementForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageManagementForm)
{
    ui->setupUi(this);

        QList<int> sizes;
        sizes << 150 << 1000;
        ui->splitter->setSizes(sizes);
}

ImageManagementForm::~ImageManagementForm()
{
    delete ui;
}
