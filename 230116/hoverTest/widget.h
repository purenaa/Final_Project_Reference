#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QHoverEvent>
#include <QEvent>
#include <QDebug>

class QGraphicsView;
class QGraphicsDropShadowEffect;
class QGraphicsColorizeEffect;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QGraphicsView *grid1;
    QGraphicsView *grid2;
    QPushButton *button;

    QGraphicsDropShadowEffect *m_shadowEffect;
    QGraphicsColorizeEffect *m_colorEffect;
    QPainter *m_pal;

protected:
    bool event(QEvent * e);

//    void hoverLeave(QHoverEvent * event);
//    void hoverMove(QHoverEvent * event);

//    void mouseMoveEvent(QMouseEvent *event);
////    void enterEvent(QEvent *event);
////    void leaveEvent(QEvent *event);

    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *e);



private:
    int m_count;
};
#endif // WIDGET_H
