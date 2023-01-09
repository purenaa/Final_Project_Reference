#include "mainwindow.h"
#include "memoalbum.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    MemoAlbum m;
    m.show();
    return a.exec();
}
