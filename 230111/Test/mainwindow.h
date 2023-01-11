#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ImageView;
class QGraphicsScene;
class QListWidget;
class QListWidgetItem;

class MemoAlbum;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MemoAlbum *m_memoAlbum;
    QString currentImage();         // 현재 이미지

private:
    Ui::MainWindow *ui;

    ImageView *imageView;
    QGraphicsScene *graphicsScene;
    QListWidget* listWidget;

public slots:
    void reset();
    void reloadImages();
    void selectItem(QListWidgetItem*);
    void setImage(QString);
};
#endif // MAINWINDOW_H
