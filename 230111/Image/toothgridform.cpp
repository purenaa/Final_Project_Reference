#include "toothgridform.h"
#include "ui_toothgridform.h"

ToothGridForm::ToothGridForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToothGridForm)
{
    ui->setupUi(this);
}

ToothGridForm::~ToothGridForm()
{
    delete ui;
}
