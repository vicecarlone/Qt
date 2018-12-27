#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>
#include <QOpenGLFunctions>

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class Helper
{
public:
    Helper();

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);

private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};


namespace Ui {
class Widget;
}

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit Widget(QOpenGLWidget *parent = nullptr);
    Widget(Helper *helper, QOpenGLWidget *parent = nullptr);
    ~Widget();

public slots:
    void animate();

private:
    Ui::Widget *ui;

    QOpenGLContext *context;
    QOpenGLFunctions *function;

    Helper *helper;
    int elapsed;

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void resizeEvent(QResizeEvent * QOb);
    void paintEvent(QPaintEvent * QOb);


};

#endif // WIDGET_H
