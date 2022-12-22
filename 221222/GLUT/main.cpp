//#include "widget.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}

#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    //glutIconifyWindow();
    //glutDisplayFunc(display);
    Widget w;
    w.show();
    //glutMainLoop();
    return a.exec();
}



