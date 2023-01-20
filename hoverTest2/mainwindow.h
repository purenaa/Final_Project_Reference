#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    bool eventFilter(QObject* watched, QEvent* event) override;


private:
    Ui::MainWindow *ui;
    QGraphicsView* view1_;
    QGraphicsView* view2_;
    QGraphicsView* selectedView_;
};

#endif // MAINWINDOW_H
