#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glut.h>
#include <GL/glu.h>

namespace Ui {
class GLWidget;
}

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QOpenGLWidget *parent = nullptr);
    ~GLWidget();

public slots:
    void anime();


private:
    Ui::GLWidget *ui;
    float ratio;

protected:
    virtual void paintGL();
    virtual void initializeGL();
    virtual void resizeGL(int,int);
};

#endif // GLWIDGET_H
