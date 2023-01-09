#include "imagemanagementform.h"
#include "ui_imagemanagementform.h"

#include "gridform.h"
#include "fmxform.h"
#include "toothgridform.h"


ImageManagementForm::ImageManagementForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageManagementForm)
{
    ui->setupUi(this);

        gridForm = new GridForm(this);
        gridForm->setWindowTitle(tr("2 X 2 Grid"));
        connect(gridForm, SIGNAL(destroyed()), gridForm, SLOT(deleteLater()));

        fmxForm = new FMXForm(this);
        connect(fmxForm, SIGNAL(destroyed()), fmxForm, SLOT(deleteLater()));
        fmxForm->setWindowTitle(tr("14 FMX Layout"));

        toothGridForm = new ToothGridForm(this);
        connect(toothGridForm, SIGNAL(destroyed()), toothGridForm, SLOT(deleteLater()));
        toothGridForm->setWindowTitle(tr("Tooth Grid"));

        QMdiSubWindow *cw = ui->mdiArea1->addSubWindow(gridForm);
        ui->mdiArea1->addSubWindow(fmxForm);
        ui->mdiArea1->addSubWindow(toothGridForm);
        ui->mdiArea1->setActiveSubWindow(cw);
}

ImageManagementForm::~ImageManagementForm()
{
    delete ui;
}
