#ifndef LAYOUT_H
#define LAYOUT_H

#include <QGraphicsLayoutItem>
#include <QGraphicsItem>
#include <QPixmap>

class Layout : public QGraphicsLayoutItem, public QGraphicsItem
{
    Q_OBJECT

public:
    Layout(QGraphicsItem *parent = nullptr);
    ~Layout();

    // QGraphicsLayoutItem에서 상속됨
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // QGraphicsItem에서 상속됨
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPixmap m_pix;
};
#endif // LAYOUT_H
