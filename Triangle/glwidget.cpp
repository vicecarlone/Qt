#include "glwidget.h"
#include "ui_glwidget.h"

#include <QTimer>

GLWidget::GLWidget(QOpenGLWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::GLWidget)
{
    ui->setupUi(this);

    this->ratio = 0;
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(anime()));
    timer->start(100);
}

GLWidget::~GLWidget()
{
    delete ui;
}

void GLWidget::paintGL()
{
    glClearColor(1.0,1.0,1.0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(ratio, 1.0, 1.0, 1.0);


    glColor3f(0.5,0.5,0.5);
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_LINE);
    gluSphere(quadric,0.75,10,10);
    glFlush();
}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);

}

void GLWidget::resizeGL(int h , int w)
{
    glViewport(0,0,w,h);
    qreal aspec = qreal(w)/qreal(h);

    //Setting project matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,aspec,0.1, 4000000);

    //Setting camera postion
    gluLookAt(0.0,0.0,2.0,0.0,0.0,0.0,0.0,1.0,0.0);

    //Restore to modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void GLWidget::anime(){
    ratio += 0.1f;
    this->update();
}
