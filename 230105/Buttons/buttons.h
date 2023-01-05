#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Buttons; }
QT_END_NAMESPACE

class Buttons : public QWidget
{
    Q_OBJECT

public:
    Buttons(QWidget *parent = nullptr);
    ~Buttons();

private:
    Ui::Buttons *ui;

};
#endif // BUTTONS_H
