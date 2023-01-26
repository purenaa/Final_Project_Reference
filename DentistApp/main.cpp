//#include "mainwindow.h"
//#include "layout.h"
//#include "fmx.h"
//#include "loginform.h"
#include "mainwidget.h"
#include <QStackedWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget main;


//    LoginForm n;
//    n.show();
//    w.show();
    main.show();
    return a.exec();


//    QApplication a(argc, argv);
//    Layout L;
//    L.show();
//    return a.exec();

//    QApplication a(argc, argv);
//    Layout L;
//    L.setStyleSheet("background:rgb(32, 56, 100)");
//    L.show();
//    return a.exec();


//    QApplication a(argc, argv);
//    FMX X;
//    X.show();
//    return a.exec();

//    QApplication a(argc, argv);
//    Listalbum A;
//    A.show();
//    return a.exec();

//    QApplication a(argc, argv);
//    LoginForm n;
//    n.show();
//    return a.exec();
}
