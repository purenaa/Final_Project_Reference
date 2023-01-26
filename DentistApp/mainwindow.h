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
class QStackedWidget;
class Maxlayout;
class LoginForm;


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
    void loadImages();                  // 이미지 로드

    bool d = false;
//    bool s = false;


    bool r = false;
    bool y = false;

    bool c = false;

    /* 로그인 창 */
    QStackedWidget *loginStack;


protected:
    void changeEvent(QEvent *event) override;                       // 윈도우 창 변경될 때
    void resizeEvent(QResizeEvent *event) override;                 // 위젯 창 변경될 때


public slots:
    void selectItem(QListWidgetItem*);
    void previousScreen();              // 이전 화면 (layout클래스 화면으로 돌아감)
    void loginButton(QString, QString);


private slots:
    void on_layoutClearPushButton_clicked();
    void on_zoomInToolButton_clicked();
    void on_zoomOutToolButton_clicked();
    void on_leftRotateToolButton_clicked();
    void on_rightRotateToolButton_clicked();


    void layoutSizeChanged(QGraphicsView *grid);
    void DoubleWidget(QGraphicsView *grid);

    void on_imageSizeClearPushButton_clicked();

    void on_verticalFlipToolButton_clicked();

private:
    Ui::MainWindow *ui;

    /* 레이아웃 */
    Layout *customLayout;
    FMX *fmx;
    Maxlayout *myMaxlayout;
    LoginForm *login;

    /* 이중 창 */
    QStackedWidget *stackWidget;


    int cnt = 0;

    /* 환자 정보 DB */
    void patientLoad();

    QSqlQuery *patientQuery;
    QSqlTableModel *patientQueryModel;

    QHash<QGraphicsPixmapItem*, QString> itemHash;


signals:
};
#endif // MAINWINDOW_H
