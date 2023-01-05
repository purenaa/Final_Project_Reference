#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ButtonForm;
class QScrollArea;
class QScrollBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_imageLoad_clicked();
    void on_actionFitToWindow_triggered();

    void normalSize();

private:
    Ui::MainWindow *ui;
    ButtonForm *Button;
    QScrollArea *scrollArea;

    double scaleFactor = 1;

    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);


};
#endif // MAINWINDOW_H
