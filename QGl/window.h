#ifndef WINDOW_H
#define WINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class QOpenGLShaderProgram;

class GlWindow : public QOpenGLWindow,
               protected QOpenGLFunctions
{
  Q_OBJECT

// OpenGL Events
public:
  ~GlWindow();

  void initializeGL();
  void resizeGL(int width, int height);
  void paintGL();
  void paintUnderGL();
  void paintOverGL();
  void teardownGL();

private:
  // OpenGL State Information
  QOpenGLBuffer m_vertex;
  QOpenGLVertexArrayObject m_object;
  QOpenGLShaderProgram *m_program;
  // Private Helpers
  void printContextInformation();
};

#endif // WINDOW_H
