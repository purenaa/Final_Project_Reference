#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QMenu;

namespace Ui { class Widget; }


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

//public slots:
//    void zoomIn();
//    void zoomOut();

private slots:
//    void mouseMoveEvent (QMouseEvent * event);

    void on_pushButton_zoomIn_clicked();

private:
    Ui::Widget *ui;

    void createActions();
    void scaleImage(double factor);

    QAction *zoomInAct;
    QAction *zoomOutAct;

    double scaleFactor = 1;

};
#endif // WIDGET_H
