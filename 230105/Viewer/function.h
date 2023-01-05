#ifndef FUNCTION_H
#define FUNCTION_H

#include <QWidget>

#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Function; }
QT_END_NAMESPACE

class Function : public QWidget
{
    Q_OBJECT

public:
    Function(QWidget *parent = nullptr);
    ~Function();

private:
    Ui::Function *ui;

private slots:
    void fileLoad();
    void zoomIn();
    void zoomOut();
    void leftRotate();
    void rightRotate();

    void on_sizePushButton_clicked(QPixmap buf);

signals:
    void sig_imgSize(QPixmap);
};
#endif // FUNCTION_H
