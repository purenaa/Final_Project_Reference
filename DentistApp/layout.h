#ifndef LAYOUT_H
#define LAYOUT_H


#include <QWidget>

class QGraphicsView;
class QGraphicsScene;
class QPushButton;

class QHoverEvent;
class QEvent;

class MainWindow;

class Layout : public QWidget
{
    Q_OBJECT
public:
    explicit Layout(QWidget *parent = nullptr);

    QGraphicsView *grid1;
    QGraphicsView *grid2;
    QGraphicsView *grid3;
    QGraphicsView *grid4;

    QGraphicsScene *scene1;
    QGraphicsScene *scene2;
    QGraphicsScene *scene3;
    QGraphicsScene *scene4;

    QGraphicsView *grid;
    QGraphicsScene *scene;
    QPushButton *viewQuit;

    QGraphicsView *newView;
    QGraphicsScene *newScene;

    QPointF clickPoint;
    QWidget *widget;




//    NewWindow *newWindow;

    bool g = false;
    bool w = false;




protected:
    void mousePressEvent(QMouseEvent *event) override;              // 왼쪽 마우스를 눌렀을 때 좌표 위치
    void mouseDoubleClickEvent(QMouseEvent *event) override;        // 왼쪽 마우스 더블 클릭
//    void changeEvent(QEvent *event) override;                       // 윈도우 창 변경될 때
//    void resizeEvent(QResizeEvent * event) override;                // 위젯 창 변경될 때


private:
    void gridLayout();
    void DoubleWidget();


signals:
    void sig_layoutInfo(QGraphicsView* grid, QGraphicsScene* scene);
//    void sig_layoutInfo2(QGraphicsView* grid2, QGraphicsScene* scene2);
//    void sig_layoutInfo3(QGraphicsView* grid3, QGraphicsScene* scene3);
//    void sig_layoutInfo4(QGraphicsView* grid4, QGraphicsScene* scene4);


public slots:


};

#endif // LAYOUT_H
