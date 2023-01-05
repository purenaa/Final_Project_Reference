#include "zoom.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zoom w;
    w.show();
    return a.exec();
}
