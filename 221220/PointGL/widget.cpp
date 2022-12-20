#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("Hello OpenGL");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void Widget::paintGL()
{
    /* 점 3개 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
//    glBegin(GL_POINTS);             /* GL_POINTS : 점 */
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glEnd();

//    glFlush();

    /* 점 3개를 크고 동그랗게 */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(10.0);              /* 점의 크기 조정 */
    glEnable(GL_POINT_SMOOTH);      /* 점을 동그랗게(매끄럽게) */
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}












