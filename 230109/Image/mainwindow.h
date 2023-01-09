#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class ImageManagementForm;
class PatientCareForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    ImageManagementForm *imageManagementForm;
    PatientCareForm *patientCareForm;

private slots:
    void fileLoad();
    void zoomIn();
    void zoomOut();
    void leftRotate();
    void rightRotate();
};

#endif // MAINWINDOW_H
