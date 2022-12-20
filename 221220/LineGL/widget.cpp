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
    /* 개곡선 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
//    glLineWidth(10.0);              /* 선의 굵기 조절 */
//    glBegin(GL_LINE_STRIP);         /* STRIP은 점들을 계속 이어서 그린다는 뜻 */
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glEnd();
//    glFlush();


    /* 폐곡선 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
//    glLineWidth(10.0);              /* 선의 굵기 조절 */
//    glBegin(GL_LINE_LOOP);          /* STRIP은 점들을 계속 이어서 그린다는 뜻 */
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glEnd();
//    glFlush();


    /* GL_LINES */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
//    glBegin(GL_LINES);              /* STRIP은 점들을 계속 이어서 그린다는 뜻 */
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i = 0; i <6; i++){
//        glVertex2f(x, y);
//        x += 0.3;
//        y *= -1;
//    };
//    glEnd();
//    glFlush();


    /* 원 그리기 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */
//    double rad = 0.5;
//    glLineWidth(50.0);              /* 선의 굵기 조절 */
//    glEnable(GL_LINE_SMOOTH);       /* 원의 곡선을 매끄럽게 해줌 */
//    glBegin(GL_LINE_LOOP);
//    for(int i = 0; i < 360; i++){
//        double angle, x, y;
//        angle = i * 3.141592 / 180;
//        x = rad * cos(angle);
//        y = rad * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//    glFlush();


    /* 선의 두께 점차 증가 */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */

//    GLfloat w = 1, y;
//    for(y = 0.8; y > -0.8; y -= 0.2){
//        glLineWidth(w++);
//        glBegin(GL_LINES);
//        glVertex2f(-0.8, y);
//        glVertex2f(0.8, y);
//        glEnd();
//    };
//    glFlush();


    /* 점선 그리기 (STIPPLE), ex)점묘법 */
    GLushort arPat[] = {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa,
                       0x33ff, 0x33ff, 0x33ff, 0x57ff, 0x57ff};
    GLint arFac[] = { 1, 2, 3, 4, 1, 2, 3, 1, 2 };

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);       /* R, G, B색상 : 흰색 */

    glEnable(GL_LINE_STIPPLE);
    GLfloat w = 1, y;               /* w : 가로 선의 굵기 */
    GLint idx = 0;
    for(y = 0.8; y > -0.8; y -= 0.2){
        glLineStipple(arFac[idx], arPat[idx]);
        glLineWidth(w++);           /* 선의 굵기를 점점 증가 */
        glBegin(GL_LINES);
        glVertex2f(-0.8, y);
        glVertex2f(0.8, y);
        glEnd();
        idx++;
    };
    glEnd();
    glFlush();
}
