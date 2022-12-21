#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    polygonMode = GL_FILL;
    shadeMode = GL_FLAT;

    setWindowTitle("OpenGL PolygonMode3D");
    resize(600, 600);
}

Widget::~Widget()
{

}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glShadeModel(shadeMode);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    /* 아랫면 흰 바닥면 */
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    /* 위쪽 빨간면 */
    glColor3f(1, 1, 1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1, 0, 0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    /* 왼쪽 노란면 */
    glColor3f(1, 1, 0);
    glVertex2f(-0.5, -0.5);

    /* 아래쪽 초록면 */
    glColor3f(0, 1, 0);
    glVertex2f(0.5, -0.5);

    /* 오른쪽 파란면 */
    glColor3f(0, 0, 1);
    glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
    case Qt::Key_Up:
        polygonMode = GL_POINT;
        break;
    case Qt::Key_Down:
        polygonMode = GL_LINE;
        break;
    case Qt::Key_Left:
        polygonMode = GL_FILL;
        break;
    case Qt::Key_Right:
        shadeMode = GL_SMOOTH;
        break;
    case Qt::Key_7:
        shadeMode = GL_FLAT;
        break;

    /* 회전 */
    case Qt::Key_1:
        yAngle += 2;
        break;
    case Qt::Key_2:
        yAngle -= 2;
        break;
    case Qt::Key_3:
        xAngle += 2;
        break;
    case Qt::Key_4:
        xAngle -= 2;
        break;
    case Qt::Key_5:
        zAngle += 2;
        break;
    case Qt::Key_6:
        zAngle -= 2;
        break;
    case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break;
    };
    update();
}
