#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class Layout;
class FMX;

class QListWidgetItem;
class QGraphicsView;


class QSqlQuery;
class QSqlTableModel;


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


    void loadImages();

public slots:
    void selectItem(QListWidgetItem*);


private slots:
    void selectGrid(QGraphicsView *gridLayout);




    void on_imageClearPushButton_clicked();

private:
    Ui::MainWindow *ui;

    /* 레이아웃 */
    Layout *customLayout;
    FMX *fmx;

    /* 환자 정보 DB */
    void patientLoad();

    QSqlQuery *patientQuery;
    QSqlTableModel *patientQueryModel;

signals:
    void sig_currentImage(int);
};
#endif // MAINWINDOW_H
