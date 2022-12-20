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
    /* 정오각형 그라디언트 */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
    glBegin(GL_POLYGON);            /* GL_POLYGON : 도형의 색을 채워줌 */
    glVertex2f(0.0, 0.6);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.4, -0.6);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.4, -0.6);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.6, 0.0);
    glEnd();

    glFlush();
}












