#include "function.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Function w;
    w.show();
    return a.exec();
}
