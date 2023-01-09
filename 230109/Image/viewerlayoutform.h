#ifndef VIEWERLAYOUTFORM_H
#define VIEWERLAYOUTFORM_H

#include <QWidget>

namespace Ui {
class ViewerLayoutForm;
}

class ViewerLayoutForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewerLayoutForm(QWidget *parent = nullptr);
    ~ViewerLayoutForm();

private:
    Ui::ViewerLayoutForm *ui;
};

#endif // VIEWERLAYOUTFORM_H
