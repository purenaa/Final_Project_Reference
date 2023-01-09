#ifndef SCENEWITHMOVABLEPROXIES_HPP
#define SCENEWITHMOVABLEPROXIES_HPP

#include <QWidget>
#include <QPoint>

namespace Ui {
  class SceneWithMovableProxies;
}

class SceneWithMovableProxies : public QWidget
{
    Q_OBJECT

  public:
    explicit SceneWithMovableProxies(QWidget *parent = 0);
    ~SceneWithMovableProxies();

  private:
    Ui::SceneWithMovableProxies *ui;
    void addWidgetToScene(QPoint initPos);
};

#endif // SCENEWITHMOVABLEPROXIES_HPP
