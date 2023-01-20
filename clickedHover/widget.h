#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QGraphicsView;
class QGraphicsDropShadowEffect;
class QGraphicsColorizeEffect;
class QPushButton;

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
    bool eventFilter(QObject* obj, QEvent* event);

//    bool event(QEvent * e);

//    void enterEvent(QEnterEvent *event);
//    void leaveEvent(QEvent *e);
};
#endif // WIDGET_H
