#include "zoom.h"
#include "ui_zoom.h"

#include <QApplication>
#include <QImageReader>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QImageWriter>
#include <QColorSpace>
#include <QScrollArea>
#include <QScrollBar>
#include <QStandardPaths>
#include <QStatusBar>
#include <QLabel>
#include <QImage>


zoom::zoom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zoom), imageLabel(new QLabel)
    , scrollArea(new QScrollArea)
{
    ui->setupUi(this);

//    ui->imageView->setBackgroundRole(QPalette::Base);
//    ui->imageView->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    //ui->imageView->setScaledContents(true);

//    scrollArea->setBackgroundRole(QPalette::Dark);
//    scrollArea->setWidget(imageLabel);
//    scrollArea->setVisible(false);
//    setCentralWidget(scrollArea);
}

zoom::~zoom()
{
    delete ui;
}

bool zoom::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
    setImage(newImage);

    setWindowFilePath(fileName);

    const QString description = image.colorSpace().isValid()
        ? image.colorSpace().description() : tr("unknown");
    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4 (%5)")
        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height())
        .arg(image.depth()).arg(description);
    statusBar()->showMessage(message);
    return true;
}

void zoom::setImage(const QImage &newImage)
{
    image = newImage;
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);
    imageLabel->setPixmap(QPixmap::fromImage(image));

    scaleFactor = 1.0;

    scrollArea->setVisible(true);
    updateActions();

    if (!fitToWindowAct->isChecked())
        imageLabel->adjustSize();
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    dialog.setAcceptMode(acceptMode);
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void zoom::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().constFirst())) {}
}

void zoom::zoomIn()
//! [9] //! [10]
{
    scaleImage(1.25);
}

void zoom::zoomOut()
{
    scaleImage(0.8);
}

void zoom::normalSize()
//! [11] //! [12]
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void zoom::fitToWindow()
//! [13] //! [14]
{
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow)
        normalSize();
    updateActions();
}

void zoom::updateActions()
//! [21] //! [22]
{
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
}

void zoom::scaleImage(double factor)
//! [23] //! [24]
{
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap(Qt::ReturnByValue).size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void zoom::adjustScrollBar(QScrollBar *scrollBar, double factor)
//! [25] //! [26]
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void zoom::on_openPushButton_clicked()
{
    QFileDialog dlg;
    QString filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");
    QString fileName = filePath.section("/", -1);
    QImage *img = new QImage(filePath);

    QSize size = img->size();
    img->scaled(size);

    QPixmap buf = QPixmap::fromImage(*img);
    buf = buf.scaled(ui->imageView->width(), ui->imageView->height());

    QGraphicsScene* scene = new QGraphicsScene;

    ui->imageView->setScene(scene);
    scene->addPixmap(buf);

}

