#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bCullFace = GL_FALSE;
    bCcwFront = GL_TRUE;

    setWindowTitle("OpenGL Culling3D");
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

    if(bCullFace){
        glEnable(GL_CULL_FACE);             /* GL_CULL_FACE 기능을 켜면 가려진 안쪽 면을 그리지 않으므로 그리는 속도 증가 */
    } else{
        glDisable(GL_CULL_FACE);
    }
    glFrontFace(bCcwFront ? GL_CCW : GL_CW);

//    //CCW
//    glBegin(GL_POLYGON);
//    glVertex2f(-0.5, 0.5);
//    glVertex2f(-0.9, -0.5);
//    glVertex2f(-0.1, -0.5);
//    glEnd();

//    //CW
//    glBegin(GL_POLYGON);
//    glVertex2f(0.5, 0.5);
//    glVertex2f(0.9, -0.5);
//    glVertex2f(0.1, -0.5);
//    glEnd();
    //    glFlush();

    glPushMatrix( );
    glTranslatef(-0.5f, 0.0f, 0.0f);        /* 좌표 원점 위치 */
    // CCW
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.4, -0.5);
    glVertex2f(0.4, -0.5);
    glEnd( );
    glTranslatef(1.0f, 0.0f, 0.0f);         /* 좌표 원점 위치를 1.0만큼 이동 */

    // CW
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.4, -0.5);
    glVertex2f(-0.4, -0.5);
    glEnd( );
    glPopMatrix( );
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
    case Qt::Key_Up:
        bCullFace = GL_TRUE;
        break;
    case Qt::Key_Down:
        bCullFace = GL_FALSE;
        break;
    case Qt::Key_Left:
        bCcwFront = GL_TRUE;
        break;
    case Qt::Key_Right:
        bCcwFront = GL_FALSE;
        break;
    };

    QString str = QString("Cull : %s, Front : %s").arg(bCullFace ? "ON" : "OFF").arg(bCcwFront ? "CCW" : "CW");
    setWindowTitle(str);
    update();
}
