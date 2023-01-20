#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QHoverEvent>
#include <QEvent>
#include <QDebug>
#include <QGraphicsView>

class QGraphicsView;
class QGraphicsDropShadowEffect;
class QGraphicsColorizeEffect;
class QGraphicsScene;

class View;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QGraphicsView *grid1;
    QGraphicsView *grid2;
    QPushButton *button;

    QGraphicsScene *scene1;
    QGraphicsScene *scene2;

    QPointF clickPoint;
    bool c = false;

    QGraphicsView *customView;
    QGraphicsScene *customScene;


    QGraphicsDropShadowEffect *m_shadowEffect;
    QGraphicsColorizeEffect *m_colorEffect;
    QPainter *m_pal;

protected:
//    bool event(QEvent * e) override;

//    void hoverLeave(QHoverEvent * event);
//    void hoverMove(QHoverEvent * event);



////    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

//    void enterEvent(QEnterEvent *event);
//    void leaveEvent(QEvent *e);
////    void mousePressEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void changeEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent * event) override;
    //bool eventFilter(QObject *obj, QEvent *event) override;

//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);



private:
    int m_count;
};
#endif // WIDGET_H
