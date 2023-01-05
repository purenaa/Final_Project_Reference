#ifndef TRYZOOM_H
#define TRYZOOM_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class tryzoom : public QMainWindow
{
    Q_OBJECT

public:
    tryzoom(QWidget *parent = nullptr);
    ~tryzoom();
    bool loadFile(const QString &);

private slots:
    void open();
    void zoomIn();
    void zoomOut();
    void fitToWindow();
    void normalSize();

private:
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
#endif // TRYZOOM_H
