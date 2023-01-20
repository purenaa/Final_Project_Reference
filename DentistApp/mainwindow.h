#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class Layout;
class FMX;

class QListWidgetItem;
class QGraphicsView;
class QGraphicsScene;

class QSqlQuery;
class QSqlTableModel;
class QGraphicsPixmapItem;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void styleColor();                  // ui 색상 조절
    void customLayoutLocation();        // customLayout의 graphicsView 위치 좌표값


    void loadImages();

    void toggleMaximized();


    void DoubleWidget();



protected:
    void changeEvent(QEvent *event) override;                       // 윈도우 창 변경될 때
    void resizeEvent(QResizeEvent *event) override;                 // 위젯 창 변경될 때



public slots:
    void selectItem(QListWidgetItem*);


private slots:
    void on_imageClearPushButton_clicked();



private:
    Ui::MainWindow *ui;

    /* 레이아웃 */
    Layout *customLayout;
    FMX *fmx;

    QGraphicsView *newView;
    QGraphicsScene *newScene;
    QSize size;

    /* 주석처리 가능 */
    QGraphicsScene *newScene1;
    QGraphicsScene *newScene2;
    QGraphicsScene *newScene3;
    QGraphicsScene *newScene4;


    int cnt = 0;


//    /* 좌표 측정 */
//    int x1;
//    int y1;
//    int width1;
//    int height1;


    /* 환자 정보 DB */
    void patientLoad();

    QSqlQuery *patientQuery;
    QSqlTableModel *patientQueryModel;



    QHash<QGraphicsPixmapItem*, QString> itemHash;


    QHash<int, QList<QString>> hashItem;
    QList<QString> listItem;

    QMap<QString, MainWindow*> mainList;



signals:
    void sig_currentImage(int);

    //void sig_test(QString);
};
#endif // MAINWINDOW_H
