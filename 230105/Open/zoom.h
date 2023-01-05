#ifndef ZOOM_H
#define ZOOM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Zoom; }
QT_END_NAMESPACE

class Zoom : public QMainWindow
{
    Q_OBJECT

public:
    Zoom(QWidget *parent = nullptr);
    ~Zoom();

private slots:
    void on_openPushButton_clicked();
    void on_zoomInPushButton_clicked();

private:
    Ui::Zoom *ui;

};
#endif // ZOOM_H
