#include "widget.h"

#ifdef __APPLE__            // Mac OS X 인 경우
#include <GLUT/glut.h>
#else                       // Linux 등의 OS 인 경우
#include <GL/glut.h>
#endif

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 0;

    setWindowTitle("OpenGL Modeling");
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
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
/*  // 정면에서 본 주전자
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutWireTeapot(0.2);
    glFlush();
*/

/*  // 주전자의 이동(1)
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glutWireTeapot(0.2);
    glTranslatef(0.6, 0.0, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 주전자의 이동(2)
    glClear(GL_COLOR_BUFFER_BIT);               // 버퍼를 지운다.
    glPushMatrix();
    glutWireTeapot(0.2);
    glTranslatef(0.6, 0.0, 0.0);
    glutWireTeapot(0.2);
    glTranslatef(0.0, 0.6, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 주전자의 이동(3) - 1
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glutWireTeapot(0.2);
    glTranslatef(0.6, 0.0, 0.0);
    glutWireTeapot(0.2);
    glLoadIdentity();
    glTranslatef(0.0, 0.6, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 주전자의 이동(3) - 2
    glClear(GL_COLOR_BUFFER_BIT);               // 버퍼를 지운다.
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glutWireTeapot(0.2);
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glTranslatef(0.0, 0.6, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 확대된 주전자
    glClear(GL_COLOR_BUFFER_BIT);              // 버퍼를 지운다.
    glPushMatrix();
    glScalef(2.0, 3.0, 1.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 뒤집은 주전자
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(-2.0, 3.0, 1.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // x축으로 회전된 주전자
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(45.0, 1.0, 0.0, 0.0);             // glRotatef(각도, x축, y축, z축)
    glutWireTeapot(0.4);
    glPopMatrix();
    glFlush();
*/

/*  // 복합 변환 (확대 -> 이동)
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 복합 변환 (이동 -> 확대)
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.5, 1.5, 1.0);
    glTranslatef(0.5, 0.5, 0.0);                // 위치
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();
*/

/*  // 복합변환(삼각형)
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();
    glPopMatrix();
    glFlush();
*/

/*  // 복합변환(별)
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();
    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.5, -0.5, 0.0);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();
    glPopMatrix();
    glFlush();
*/
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);

    switch(event->key()){
    case Qt::Key_Z:                 // 변환 없음
        break;
    case Qt::Key_1:                 // 이동
        break;
    case Qt::Key_2:                 // 엉뚱한 위치에 나타나는 이동
        break;
    case Qt::Key_3:                 // 단위 행렬로 리셋
        break;
    case Qt::Key_4:                 // 스택에 저장 및 복구
        break;
    case Qt::Key_5:                 // 확대
        break;
    case Qt::Key_6:                 // 회전
        break;
    case Qt::Key_7:                 // 확대 후 이동
        break;
    case Qt::Key_8:                 // 이동 후 확대
        break;
    case Qt::Key_9:                 // 원점 기준 회전
        break;
    case Qt::Key_0:                 // 제자리 회전
        break;
    };

    update();
}
