#ifndef IMAGEMANAGEMENTFORM_H
#define IMAGEMANAGEMENTFORM_H

#include <QWidget>
#include <QGraphicsItem>

class ImageView;
class QGraphicsScene;
class QListWidget;
class QListWidgetItem;

namespace Ui {
class ImageManagementForm;
}

class ImageManagementForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImageManagementForm(QWidget *parent = nullptr);
    ~ImageManagementForm();
    QString currentImage();

private:
    Ui::ImageManagementForm *ui;

    ImageManagementForm *memoAlbum;

    ImageView *imageView;
    QGraphicsScene *graphicsScene;
    QListWidget* listWidget;

private slots:
    void fileLoad();
    void zoomIn();
    void zoomOut();
    void leftRotate();
    void rightRotate();

    void reset();
    void reloadImages();
    void selectItem(QListWidgetItem*);
    void setImage(QString);
};

#endif // IMAGEMANAGEMENTFORM_H
