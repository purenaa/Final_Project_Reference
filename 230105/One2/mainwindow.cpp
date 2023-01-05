#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QScrollArea>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), scrollArea(new QScrollArea)
{
    ui->setupUi(this);

    ui->imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);      // 사용자가 원하는 크기로 이미지 크기를 조정(가로, 세로)
    ui->imageLabel->setScaledContents(true);

    //scrollArea->setAlignment(QPalette::Dark);
    //scrollArea->setWidget(ui->imageLabel);
    //scrollArea->setVisible(false);
    //setCentralWidget(scrollArea);

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* 이미지크기에 맞게 로드 */
void MainWindow::on_imageLoad_clicked()
{
    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Open File", "", "Image Files (*.png *.jpg *.bmp)");

    QPixmap* selectImage = new QPixmap(filePath);
    ui->imageLabel->setPixmap(*selectImage);

    scaleFactor = 1.0;
    //scrollArea->setVisible(true);
    ui->actionFitToWindow->setEnabled(true);

    if(!ui->actionFitToWindow->isChecked())
        ui->imageLabel->adjustSize();

}

void MainWindow::on_actionZoomIn_triggered()
{
    scaleImage(1.25);
}

void MainWindow::on_actionZoomOut_triggered()
{
    scaleImage(0.8);
}

void MainWindow::normalSize()
//! [11] //! [12]
{
    ui->imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void MainWindow::on_actionFitToWindow_triggered()
{
//    bool fitToWindow = ui->actionFitToWindow->isChecked();
//    scrollArea->setWidgetResizable(fitToWindow);
//    if (!fitToWindow)
        normalSize();
//    updateActions();
}

void MainWindow::scaleImage(double factor)
{
    scaleFactor *= factor;
    ui->imageLabel->resize(scaleFactor * ui->imageLabel->pixmap(Qt::ReturnByValue).size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);
}

void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}



