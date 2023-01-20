#include "widget.h"
//#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    View v;
//    v.show();
//    return a.exec();
//}
