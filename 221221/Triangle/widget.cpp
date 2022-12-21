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
    /* 삼각형 2개 (반전출력, 정상출력) */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
//    glBegin(GL_TRIANGLES);
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i = 0; i < 6; i++){
//        glVertex2f(x, y);
//        x += 0.3;
//        y *= -1;
//    };
//    glEnd();
//    glFlush();

    /* 연속으로 이어진 삼각형 4개 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glShadeModel(GL_FLAT);              /* 색상이 하나로 지정된다. */
//    glBegin(GL_TRIANGLE_STRIP);
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i = 0; i < 6; i++){
//        if(i % 2 == 0){
//            glColor3f(1.0, 0.0, 0.0);
//        } else{
//            glColor3f(0.0, 1.0, 0.0);
//        }
//        glVertex2f(x, y);
//        x += 0.3;
//        y *= -1;
//    };
//    glEnd();
//    glFlush();


    /* 부채모양 (연속으로 이어진 삼각형4개가 부채모양으로 회전됨)
           -> 이걸 이용해 삼각형들을 아주 잘게 나누면 완전한 원모양 구현 가능 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glShadeModel(GL_FLAT);              /* 색상이 하나로 지정된다. */
//    glBegin(GL_TRIANGLE_FAN);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex2f(0.0, 0.0);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.35, 0.35);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2f(-0.5, 0.0);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex2f(-0.35, -0.35);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2f(0.0, -0.5);
//    glEnd();
//    glFlush();


    /* 사각형 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glRectf(-0.8, 0.8, 0.8, -0.8);
//    glFlush();


    /* 다각형 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, 0.0);
//    glVertex2f(0.5, 0.0);
//    glVertex2f(0.0, -0.5);
//    glEnd();
//    glFlush();


    /* 리본모양 다각형 (GL_TRIANGLES로 그린 다각형) */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.0, -0.5);
    glEnd();
    glFlush();
}













