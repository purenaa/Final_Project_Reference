#ifndef IMAGEMANAGEMENTFORM_H
#define IMAGEMANAGEMENTFORM_H

#include <QWidget>

namespace Ui {
class ImageManagementForm;
}

class ImageManagementForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImageManagementForm(QWidget *parent = nullptr);
    ~ImageManagementForm();

private:
    Ui::ImageManagementForm *ui;
};

#endif // IMAGEMANAGEMENTFORM_H
