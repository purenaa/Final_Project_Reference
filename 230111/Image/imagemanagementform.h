#ifndef IMAGEMANAGEMENTFORM_H
#define IMAGEMANAGEMENTFORM_H

#include <QWidget>

namespace Ui {
class ImageManagementForm;
}

class GridForm;
class FMXForm;
class ToothGridForm;

class ImageManagementForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImageManagementForm(QWidget *parent = nullptr);
    ~ImageManagementForm();

private:
    Ui::ImageManagementForm *ui;

    GridForm *gridForm;
    FMXForm *fmxForm;
    ToothGridForm *toothGridForm;
};

#endif // IMAGEMANAGEMENTFORM_H
