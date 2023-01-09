#include "scenewithmovableproxies.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  SceneWithMovableProxies w;
  w.show();

  return a.exec();
}
