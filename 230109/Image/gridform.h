#ifndef GRIDFORM_H
#define GRIDFORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GridForm; }
QT_END_NAMESPACE

class GridForm : public QWidget
{
    Q_OBJECT

public:
    GridForm(QWidget *parent = nullptr);
    ~GridForm();

private:
    Ui::GridForm *ui;


signals:

};
#endif // GRIDFORM_H
