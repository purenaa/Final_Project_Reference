#include "buttonform.h"
#include "ui_buttonform.h"

#include <QFileDialog>
#include <QGraphicsScene>

ButtonForm::ButtonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonForm)
{
    ui->setupUi(this);
}

ButtonForm::~ButtonForm()
{
    delete ui;
}
