#include "imagemanagementform.h"
#include "ui_imagemanagementform.h"

#include <QFileDialog>
#include <QGraphicsView>
#include <QPixmap>

#include <QSplitter>
#include <QListWidget>
#include <QDir>
#include <QFileInfo>

#include "imageview.h"

ImageManagementForm::ImageManagementForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageManagementForm)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 150 << 1000;
    ui->splitter2->setSizes(sizes);

    QList<int> listsize;
    listsize << 1000 << 220;
    ui->splitter->setSizes(listsize);

    //connect(ui->imageRoadButton, SIGNAL(clicked()), this, SLOT(reloadImages()));
    connect(ui->imageRoadButton, SIGNAL(clicked()), this, SLOT(fileLoad()));
    connect(ui->zoomInToolButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->zoomOutToolButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui->leftRotateToolButton, SIGNAL(clicked()), this, SLOT(leftRotate()));
    connect(ui->rightRotateToolButton, SIGNAL(clicked()), this, SLOT(rightRotate()));

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));



//    graphicsScene = new QGraphicsScene(this);
//    imageView = new ImageView(ui->listWidget);
////    imageView->setScene(graphicsScene);

//    ui->listWidget->setIconSize(QSize(100, 100));
//    ui->listWidget->setFlow(QListWidget::LeftToRight);

//    reloadImages();


    graphicsScene = new QGraphicsScene;
    imageView = new ImageView();
//    imageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    imageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    imageView->setScene(graphicsScene);
//    imageView->grabGesture(Qt::PinchGesture);

    listWidget = new QListWidget(ui->listWidget);
    listWidget->setIconSize(QSize(100, 100));
    listWidget->setResizeMode(QListWidget::Adjust);
    listWidget->setFlow(QListWidget::LeftToRight);
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));

    reloadImages();
}

ImageManagementForm::~ImageManagementForm()
{
    delete ui;
}

void ImageManagementForm::reloadImages(){
    QDir dir(".");
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";
    QFileInfoList fileInfoList = dir.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot);
    graphicsScene->clear();

    listWidget->clear();
    for(int i=0; i<fileInfoList.count(); i++){
        QListWidgetItem* item = new QListWidgetItem(QIcon(fileInfoList.at(i).fileName()), NULL, listWidget);
        item->setStatusTip(fileInfoList.at(i).fileName());
        listWidget->addItem(item);
    };
}

void ImageManagementForm::selectItem(QListWidgetItem *item){
    imageView->resetTransform();
    graphicsScene->clear();
    graphicsScene->addPixmap(QPixmap(item->statusTip()).scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->graphicsView1->setScene(graphicsScene);
}

void ImageManagementForm::setImage(QString path){
    imageView->resetTransform();
    graphicsScene->clear();
    graphicsScene->addPixmap(QPixmap(path).scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QFileInfo fileInfo(path);
    for(int i=0; i< ui->listWidget->count(); i++){
        if(ui->listWidget->item(i)->statusTip() == fileInfo.fileName()){
            ui->listWidget->setCurrentRow(i);
            break;
        }
    }
}

QString ImageManagementForm::currentImage(){
    return (ui->listWidget->currentRow() >= 0)? ui->listWidget->currentItem()->statusTip():"";
}

void ImageManagementForm::reset(){
    imageView->resetTransform();
}


//--------------------------------------------------------------------------------------

void ImageManagementForm::fileLoad()
{
    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");

    QImage *imgSize = new QImage(filePath);
    QPixmap buf = QPixmap::fromImage(*imgSize);
    buf = buf.scaled(imgSize->width(), imgSize->height());

    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(buf);
    ui->graphicsView1->setScene(scene);

    //ui->graphicsView2->setScene(scene);
}

void ImageManagementForm::zoomIn()
{
    ui->graphicsView1->scale(1.25,1.25);
}

void ImageManagementForm::zoomOut()
{
    ui->graphicsView1->scale(0.8, 0.8);
}

void ImageManagementForm::leftRotate()
{
    ui->graphicsView1->rotate(90);
}

void ImageManagementForm::rightRotate()
{
    ui->graphicsView1->rotate(-90);
}

