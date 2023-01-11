#ifndef FMXFORM_H
#define FMXFORM_H

#include <QWidget>

namespace Ui {
class FMXForm;
}

class FMXForm : public QWidget
{
    Q_OBJECT

public:
    explicit FMXForm(QWidget *parent = nullptr);
    ~FMXForm();

private:
    Ui::FMXForm *ui;
};

#endif // FMXFORM_H
