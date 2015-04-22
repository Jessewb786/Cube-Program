#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <QGLBuffer>
#include <QGLShaderProgram>

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT

public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
    ~MyPanelOpenGL();


protected:
    void initializeGL();
    void resizeGL(int ,int);
    void paintGL();

private:
    GLfloat tranMatrix[4][4];
    GLfloat scaleMatrix[4][4];
    GLfloat rotXMatrix[4][4];
    GLfloat rotYMatrix[4][4];
    GLfloat rotZMatrix[4][4];
    GLfloat tempMatrix[4][4];
    GLfloat mMatrix[4][4];
    GLfloat pMatrix[4][4];
    GLfloat projtoOrthRatio;
    QMatrix4x4 vMatrix;
    QGLShaderProgram shaderProgram;
    QGLBuffer cubeBuffer;
    double alpha, beta, distance;
    bool wireframeState, projectionState;
    int numCubeVertices, viewWidth, viewHeight;

private slots:
    void restartCube();
    void toggleWireframe();
    void toggleProjection();
    void translateCube(double, double, double);
    void rotateCube(double, double, double, double, double, double, bool);
    void scaleCube(double, double, double);
    void mirrorCube(bool,bool,bool);
    void shearCube(bool,bool,bool);
};

#endif // MYPANELOPENGL_H
