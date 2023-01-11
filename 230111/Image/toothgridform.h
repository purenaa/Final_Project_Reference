#ifndef TOOTHGRIDFORM_H
#define TOOTHGRIDFORM_H

#include <QWidget>

namespace Ui {
class ToothGridForm;
}

class ToothGridForm : public QWidget
{
    Q_OBJECT

public:
    explicit ToothGridForm(QWidget *parent = nullptr);
    ~ToothGridForm();

private:
    Ui::ToothGridForm *ui;
};

#endif // TOOTHGRIDFORM_H
