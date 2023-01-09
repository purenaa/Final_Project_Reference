#include "viewerlayoutform.h"
#include "ui_viewerlayoutform.h"

ViewerLayoutForm::ViewerLayoutForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewerLayoutForm)
{
    ui->setupUi(this);
}

ViewerLayoutForm::~ViewerLayoutForm()
{
    delete ui;
}
