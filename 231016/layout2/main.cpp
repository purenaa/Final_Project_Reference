#include <QtWidgets>

static QGraphicsProxyWidget *createItem(const QSizeF &minimum = QSizeF(100.0, 100.0),
                                        const QSizeF &preferred = QSizeF(150.0, 100.0),
                                        const QSizeF &maximum = QSizeF(200.0, 100.0),
                                        const QString &name = "0")

//static QGraphicsProxyWidget *createItem(const QSizeF layout =  QSizeF(300.0, 300.0),
//                                        const QString &name = "0")

// QSizeF 클래스 : 부동 소수점 정밀도를 사용하여 2차원 객체의 크기를 정의합니다.
// minimum : 2차원 객체의 최소 크기를 지정
// preferred : 2차원 객체의 기본 크기를 지정
// maximum : 2차원 객체의 최대 크기를 지정

{
    QGraphicsProxyWidget *w = new QGraphicsProxyWidget;
    w->setWidget(new QPushButton(name));
    w->setData(0, name);                // setData : [형식: (key, const &value)]
    w->setMinimumSize(minimum);
    w->setPreferredSize(preferred);
    w->setMaximumSize(maximum);

    w->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    return w;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 480);         // setSceneRect : 사각형 영역 설정 (qreal x, y, w, h)

    /* QSizeF : 2차원 객체의 크기를 정의 */
//    QSizeF minSize(300, 300);                    // 최소 크기 (qreal width, height)
//    QSizeF prefSize(300, 300);                  // 기본 크기 (qreal width, height)
//    QSizeF maxSize(300, 300);                   // 최대 크기 (qreal width, height),

//    QSizeF layout(300.0, 300.0);


    /* createItem(QSizeF &minimum, QSizeF &preferred, QSizeF &maximum, QString &name) */
    QGraphicsProxyWidget *a = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "A");
    QGraphicsProxyWidget *b = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "B");
    QGraphicsProxyWidget *c = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "C");
    QGraphicsProxyWidget *d = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "D");
    QGraphicsProxyWidget *e = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "E");
    QGraphicsProxyWidget *f = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "F");
    QGraphicsProxyWidget *g = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "G");
    QGraphicsProxyWidget *h = createItem(QSizeF(300.0, 300.0), QSizeF(300.0, 300.0),QSizeF(300.0, 300.0), "H");

    /* 위젯을 고정할 수 있는 레이아웃 */
    QGraphicsAnchorLayout *l = new QGraphicsAnchorLayout;
    l->setSpacing(0);                       // [형식: (qreal spacing)]앵커 레이아웃의 기본 수평 간격과 기본 수직 간격을 간격으로 설정합니다.

    QGraphicsWidget *w = new QGraphicsWidget(nullptr, Qt::Window);
    w->setPos(20, 20);      // [형식 : (qreal x, y)],  QGraphicsWidget 안에서 시작 위치 좌표
    w->setGeometry(0, 0, 800, 400);
    w->setLayout(l);         // QGraphicsAnchorLayout의 레이아웃

    // vertical (수직면 기준)
//    l->addAnchor(a, Qt::AnchorTop, l, Qt::AnchorTop);                   // a의 윗 면 = 레이아웃(l)의 윗 면 위치
//    l->addAnchor(b, Qt::AnchorTop, l, Qt::AnchorTop);                   // b의 윗 면 = 레이아웃(l)의 윗 면 위치

//    l->addAnchor(c, Qt::AnchorTop, a, Qt::AnchorBottom);                // c의 맨 윗 면 = a의 바닥면 위치
//    l->addAnchor(c, Qt::AnchorTop, b, Qt::AnchorBottom);                // c의 맨 윗 면 = b의 바닥면 위치
//    l->addAnchor(c, Qt::AnchorBottom, d, Qt::AnchorTop);                // c의 바닥면 = d의 맨 윗 면 위치
//    l->addAnchor(c, Qt::AnchorBottom, e, Qt::AnchorTop);                // c의 바닥면 = e의 윗 면 위치

//    l->addAnchor(d, Qt::AnchorBottom, l, Qt::AnchorBottom);             // d의 바닥면 = 레이아웃(l)의 바닥면 위치
//    l->addAnchor(e, Qt::AnchorBottom, l, Qt::AnchorBottom);             // e의 바닥면 = 레이아웃(l)의 바닥면 위치

//    l->addAnchor(c, Qt::AnchorTop, f, Qt::AnchorTop);                   // c의 윗 면 = f의 윗 면 위치
//    /* AnchorVerticalCenter : 레이아웃 항목의 위쪽과 아래쪽 사이에 있는 "가상" 측면 */
//    l->addAnchor(c, Qt::AnchorVerticalCenter, f, Qt::AnchorBottom);     // c의 중심 = f의 윗 면 위치
//    l->addAnchor(f, Qt::AnchorBottom, g, Qt::AnchorTop);                // f의 바닥면 = g의 윗 면 위치
//    l->addAnchor(c, Qt::AnchorBottom, g, Qt::AnchorBottom);             // c의 바닥면 = g의 바닥면 위치


//    // horizontal (수평 기준)
//    l->addAnchor(l, Qt::AnchorLeft, a, Qt::AnchorLeft);                 // 레이아웃(l)의 왼쪽 면 = a의 왼쪽 면 위치
//    l->addAnchor(l, Qt::AnchorLeft, d, Qt::AnchorLeft);                 // 레이아웃(l)의 왼쪽 면 = d의 왼쪽 면 위치
//    l->addAnchor(a, Qt::AnchorRight, b, Qt::AnchorLeft);                // a의 오른쪽 면 = b의 왼쪽 면 위치

//    l->addAnchor(a, Qt::AnchorRight, c, Qt::AnchorLeft);                // a의 오른쪽 면 = c의 왼쪽 면 위치
//    l->addAnchor(c, Qt::AnchorRight, e, Qt::AnchorLeft);                // c의 오른쪽 면 = e의 왼쪽 면 위치

//    l->addAnchor(b, Qt::AnchorRight, l, Qt::AnchorRight);               // b의 오른쪽 면 = 레이아웃(l)의 오른쪽 면 위치
//    l->addAnchor(e, Qt::AnchorRight, l, Qt::AnchorRight);               // e의 오른쪽 면 = 레이아웃(l)의 오른족 면 위치
//    l->addAnchor(d, Qt::AnchorRight, e, Qt::AnchorLeft);                // d의 오른쪽 면 = e의 왼쪽 면 위치

//    l->addAnchor(l, Qt::AnchorLeft, f, Qt::AnchorLeft);                 // 레이아웃(l)의 왼쪽 면 = f의 왼쪽 면
//    l->addAnchor(l, Qt::AnchorLeft, g, Qt::AnchorLeft);                 // 레이아웃(l)의 왼쪽 면 = g의 왼쪽 면
//    l->addAnchor(f, Qt::AnchorRight, g, Qt::AnchorRight);               // f의 오른쪽 면 = g의 으론쪽 면


    // 연습 layOut
    /* 수직 */
    l->addAnchor(a, Qt::AnchorTop, l, Qt::AnchorTop);
    l->addAnchor(b, Qt::AnchorTop, l, Qt::AnchorTop);
    l->addAnchor(c, Qt::AnchorTop, l, Qt::AnchorTop);
    l->addAnchor(d, Qt::AnchorTop, l, Qt::AnchorTop);

    l->addAnchor(e, Qt::AnchorBottom, l, Qt::AnchorBottom);
    l->addAnchor(f, Qt::AnchorBottom, l, Qt::AnchorBottom);
    l->addAnchor(g, Qt::AnchorBottom, l, Qt::AnchorBottom);
    l->addAnchor(h, Qt::AnchorBottom, l, Qt::AnchorBottom);


    /* 수평 */
    l->addAnchor(l, Qt::AnchorLeft, a, Qt::AnchorLeft);
    l->addAnchor(a, Qt::AnchorRight, b, Qt::AnchorLeft);
    l->addAnchor(b, Qt::AnchorRight, c, Qt::AnchorLeft);
    l->addAnchor(c, Qt::AnchorRight, d, Qt::AnchorLeft);

    l->addAnchor(l, Qt::AnchorLeft, e, Qt::AnchorLeft);
    l->addAnchor(e, Qt::AnchorRight, f, Qt::AnchorLeft);
    l->addAnchor(f, Qt::AnchorRight, g, Qt::AnchorLeft);
    l->addAnchor(g, Qt::AnchorRight, h, Qt::AnchorLeft);

    scene.addItem(w);
    scene.setBackgroundBrush(Qt::black);
    QGraphicsView view(&scene);

    view.show();

    return app.exec();
}
