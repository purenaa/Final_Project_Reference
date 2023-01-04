#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void createActions();
    void zoomIn();
    void zoomOut();

private:
    QImage image;

    QAction *zoomInAct;
    QAction *zoomOutAct;
};
#endif // WIDGET_H
