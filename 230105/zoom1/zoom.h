#ifndef ZOOM_H
#define ZOOM_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class zoom; }

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class zoom : public QMainWindow
{
    Q_OBJECT

public:
    zoom(QWidget *parent = nullptr);
    ~zoom();
    bool loadFile(const QString &);

private slots:
    void open();
    void zoomIn();
    void zoomOut();
    void fitToWindow();
    void normalSize();

    void on_openPushButton_clicked();

private:
    Ui::zoom *ui;

    void setImage(const QImage &newImage);
    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor = 1;

    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
};
#endif // ZOOM_H
