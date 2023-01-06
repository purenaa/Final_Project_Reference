#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsWidget>

class window : public QGraphicsWidget
{
    Q_OBJECT
public:
    window(QGraphicsWidget *parent = nullptr);

signals:

};

#endif // WINDOW_H
