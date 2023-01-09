#include "fmxform.h"
#include "ui_fmxform.h"

FMXForm::FMXForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FMXForm)
{
    ui->setupUi(this);
}

FMXForm::~FMXForm()
{
    delete ui;
}
