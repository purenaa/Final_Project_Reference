#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

class QGraphicsView;
class QGraphicsScene;

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    QGraphicsView *newView;
    QGraphicsScene *newScene;

signals:

};

#endif // VIEW_H
