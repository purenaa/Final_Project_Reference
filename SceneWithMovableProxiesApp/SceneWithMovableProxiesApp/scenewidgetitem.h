#ifndef SCENEWIDGETITEM_H
#define SCENEWIDGETITEM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>

class SceneWidgetItem : public QWidget
{
    Q_OBJECT
    QVBoxLayout *layout;
    QLabel *label;
    QCheckBox *checkbox;
    QComboBox *combobox;
    QPushButton *resetButton;
  public:
    explicit SceneWidgetItem(QWidget *parent = 0);
    ~SceneWidgetItem();

  signals:

  public slots:
    void reset();
};

#endif // SCENEWIDGETITEM_H
