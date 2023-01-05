#include "zoom.h"
#include "ui_zoom.h"

#include <QFileDialog>
#include <QImage>
#include <QGraphicsScene>

Zoom::Zoom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zoom)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 2000 << 500;
    ui->splitter->setSizes(sizes);
}

Zoom::~Zoom()
{
    delete ui;
}


void Zoom::on_openPushButton_clicked()
{
    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");
    QString fileName = filePath.section("/", -1);
    QImage *img = new QImage(filePath);

//    QSize imageSize = img->size();
//    img->scaled(imageSize);

    QPixmap buf = QPixmap::fromImage(*img);
    buf = buf.scaled(ui->imageView->width(), ui->imageView->height());

    QGraphicsScene* scene = new QGraphicsScene;

    ui->imageView->setScene(scene);
    scene->addPixmap(buf);
}


void Zoom::on_zoomInPushButton_clicked()
{

}

