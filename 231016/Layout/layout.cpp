#include "layout.h"

#include <QGradient>            // QGradientStops를 사용하기 위한 헤더
#include <QPainter>

Layout::Layout(QGraphicsItem *parent)
    : QGraphicsLayoutItem(), QGraphicsItem(parent),
      m_pix(QPixmap(QLatin1String(":/images/block.png")))
{
    setGraphicsItem(this);      // QGraphicsLayout의 자동 다시 보호 기능 (포인터 위치 등)
}

Layout::~Layout()
{
}

void Layout::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QRectF frame(QPointF(0, 0), geometry().size());         // QRectF : 평면에서의 직사각형
    const QSize pmSize = m_pix.size();                      // QSize : 2차원 객체의 크기를 정의
    QGradientStops stops;                                   // QGradientStops : 그라데이션 하기 위함 [형식: QList<QGradientStop>]

    /* 배경을 직선으로 그린다. (그라데이션으로) */
    // QLinearGradient : QBrush와 함께 사용하여 선형 그라데이션 브러쉬를 지정
    QLinearGradient gradient(frame.topLeft(), frame.topLeft() + QPointF(200,200));
    stops << QGradientStop(0.0, QColor(60, 60, 60));        // QGradientStop : [형식: <qreal, Qcolor>]

    /* stops << QGradientStop(((frame.height() + h)/2 )/frame.height(), QColor(157, 195,  55)); */
    stops << QGradientStop(1.0, QColor(215, 215, 215));
    gradient.setStops(stops);
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(frame, 10.0, 10.0);            // drawRoundedRect : 직사각형, x, y

    /* Pixmap 주위에 직선을 그립니다(그라디언트 포함) */
    QPointF pixpos = frame.center() - (QPointF(pmSize.width(), pmSize.height()) / 2);
    QRectF innerFrame(pixpos, pmSize);
    innerFrame.adjust(-4, -4, 4, 4);                        // dx1, dy1, dx2, dy2
    gradient.setStart(innerFrame.topLeft());
    gradient.setFinalStop(innerFrame.bottomRight());
    stops.clear();
    stops << QGradientStop(0.0,QColor(215, 255, 200));
    stops << QGradientStop(0.5,QColor(202, 176, 54));
    stops << QGradientStop(1.0,QColor(0, 0, 0));
    gradient.setStops(stops);
    painter->setBrush(QBrush(gradient));
    painter->drawRoundedRect(innerFrame, 10.0, 10.0);
    painter->drawPixmap(pixpos, m_pix);
}

/* 사각형 경계선 */
QRectF Layout::boundingRect() const
{
    return QRectF(QPoint(0, 0), geometry().size());
}

void Layout::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();        // 위치 변경을 위한 업데이트
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF Layout::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch(which) {
    case Qt::MinimumSize:           //그래픽 레이아웃 최소 크기를 지정하는 데 사용됩니다.
    case Qt::PreferredSize:         // 그래픽 레이아웃 항목의 기본 크기를 지정하는 데 사용됩니다.
        // 주변에 프레임이 두 개 있는 픽스맵보다 작은 크기는 허용하지 마십시오.
        return m_pix.size() + QSize(12, 12);
    case Qt::MaximumSize:           //그래픽 레이아웃 최대 크기를 지정하는 데 사용됩니다.
        return QSizeF(1000, 1000);
    default:
        break;
    }
    return constraint;
}



