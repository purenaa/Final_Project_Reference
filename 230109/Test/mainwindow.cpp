#include <QListWidget>
#include <QFileInfo>
#include <QDir>

#include "mainwindow.h"
#include "imageview.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_memoAlbum = new MemoAlbum(ui->tabWidget);
//    ui->tabWidget->addTab(m_memoAlbum, tr("Memo Album"));

    graphicsScene = new QGraphicsScene;
    imageView = new ImageView(this);
    imageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    imageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    imageView->setScene(graphicsScene);
    imageView->grabGesture(Qt::PinchGesture);

    listWidget = new QListWidget(this);
    listWidget->setIconSize(QSize(120, 80));
    listWidget->setResizeMode(QListWidget::Adjust);
    listWidget->setFlow(QListWidget::LeftToRight);
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));

//    setOrientation(Qt::Vertical);
//    addWidget(imageView);
//    addWidget(listWidget);
//    setStretchFactor(0, 3);

//    QList<int> list;
//    list << 520 << 100;
//    setSizes(list);

    reloadImages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reloadImages(){
//    QString imagePath(tr("img/%1.png"));
//    QPixmap* selectImage = new QPixmap(imagePath);
//    ui->imageLabel->setPixmap(*selectImage);

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

void MainWindow::selectItem(QListWidgetItem *item){
    imageView->resetTransform();
    graphicsScene->clear();
    graphicsScene->addPixmap(QPixmap(item->statusTip()).scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::setImage(QString path){
    imageView->resetTransform();
    graphicsScene->clear();
    graphicsScene->addPixmap(QPixmap(path).scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QFileInfo fileInfo(path);
    for(int i=0; i<listWidget->count(); i++){
        if(listWidget->item(i)->statusTip() == fileInfo.fileName()){
            listWidget->setCurrentRow(i);
            break;
        }
    }
}

QString MainWindow::currentImage(){
    return (listWidget->currentRow() >= 0)?listWidget->currentItem()->statusTip():"";
}

void MainWindow::reset(){
    imageView->resetTransform();
}

