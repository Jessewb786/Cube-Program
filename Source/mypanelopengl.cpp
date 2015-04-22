#include "mypanelopengl.h"
#include "openglapp.h"
#include "GL/glu.h"
#include "MatrixMath.h"
#include <cmath>

static const GLfloat vertices[] = {
    -0.25f, -0.25f,  0.25f,  0.25f, -0.25f,  0.25f,  0.25f,  0.25f,  0.25f,// Front
     0.25f,  0.25f,  0.25f, -0.25f,  0.25f,  0.25f, -0.25f, -0.25f,  0.25f,
     0.25f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f,  0.25f, -0.25f,// Back
    -0.25f,  0.25f, -0.25f,  0.25f,  0.25f, -0.25f,  0.25f, -0.25f, -0.25f,
    -0.25f, -0.25f, -0.25f, -0.25f, -0.25f,  0.25f, -0.25f,  0.25f,  0.25f,// Left
    -0.25f,  0.25f,  0.25f, -0.25f,  0.25f, -0.25f, -0.25f, -0.25f, -0.25f,
     0.25f, -0.25f,  0.25f,  0.25f, -0.25f, -0.25f,  0.25f,  0.25f, -0.25f,// Right
     0.25f,  0.25f, -0.25f,  0.25f,  0.25f,  0.25f,  0.25f, -0.25f,  0.25f,
    -0.25f,  0.25f,  0.25f,  0.25f,  0.25f,  0.25f,  0.25f,  0.25f, -0.25f,// Top
     0.25f,  0.25f, -0.25f, -0.25f,  0.25f, -0.25f, -0.25f,  0.25f,  0.25f,
    -0.25f, -0.25f, -0.25f,  0.25f, -0.25f, -0.25f,  0.25f, -0.25f,  0.25f,// Bottom
     0.25f, -0.25f,  0.25f, -0.25f, -0.25f,  0.25f, -0.25f, -0.25f, -0.25f
};

static const GLfloat colors[] = {
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    1.0f, 0.0f, 0.0f, 1.0f, //Red vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 1.0f, 0.0f, 1.0f, //Green vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
    0.0f, 0.0f, 1.0f, 1.0f, //Blue vertice
};


MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) : QGLWidget(parent)
{
    alpha = 25;
    beta = -25;
    distance = 2.5;
    wireframeState = false;
    projectionState = false;
    projtoOrthRatio = 0.40;
    MatrixMath::makeIdentity(&tranMatrix);
    MatrixMath::makeIdentity(&scaleMatrix);
    MatrixMath::makeIdentity(&rotXMatrix);
    MatrixMath::makeIdentity(&rotYMatrix);
    MatrixMath::makeIdentity(&rotZMatrix);
    MatrixMath::makeIdentity(&mMatrix);
    MatrixMath::makeIdentity(&pMatrix);
    MatrixMath::rotateX(&rotXMatrix,beta);
    MatrixMath::rotateY(&rotYMatrix,alpha);
    MatrixMath::matrixMult4x4(&tempMatrix, &rotXMatrix, &rotYMatrix);
    MatrixMath::matrixMult4x4(&mMatrix, &tempMatrix, &mMatrix);

}

MyPanelOpenGL::~MyPanelOpenGL()
{
}

void MyPanelOpenGL::initializeGL(){

    qglClearColor(QColor(Qt::black));

    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/fragmentShader.fsh");

    shaderProgram.link();

    numCubeVertices = 36;

    //Camera view
    QMatrix4x4 cameraTransformation;

    QVector3D cameraPosition = cameraTransformation*QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation*QVector3D(0, 1, 0);
    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

    //Prepare Cube Buffer
    cubeBuffer.create();
    cubeBuffer.bind();
    cubeBuffer.allocate(numCubeVertices*(3+4)*sizeof(GLfloat));

    //Load the buffer
    cubeBuffer.write(0, vertices, numCubeVertices*3*sizeof(GLfloat));
    cubeBuffer.write(numCubeVertices*3*sizeof(GLfloat), colors, numCubeVertices*4*sizeof(GLfloat));
    cubeBuffer.release();
}

void MyPanelOpenGL::resizeGL(int width,int height){
    if(height == 0) {
        height = 1;
    }

    viewWidth = width;
    viewHeight = height;

    MatrixMath::makeIdentity(&pMatrix);
    MatrixMath::makePerspectiveMatrix(&pMatrix,1.0f, 100.0f,(float) width/height ,(float) -width/height, 1.0f , -1.0f);
    glViewport(0, 0, width, height);
}

void MyPanelOpenGL::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(wireframeState == TRUE){
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }else{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    //Bind the Shader program
    shaderProgram.bind();

    //Get the mvpMatrix, color and vertex attributes from the shader and initialize them
    shaderProgram.setUniformValue("mMatrix", mMatrix);
    shaderProgram.setUniformValue("pMatrix", pMatrix);
    shaderProgram.setUniformValue("vMatrix", vMatrix);
    shaderProgram.setAttributeArray("vertex", vertices,3 ,0);
    shaderProgram.setAttributeArray("vertexColor", colors, 4, 0);
    //Enable the vertex attribute
    shaderProgram.enableAttributeArray("vertex");
    shaderProgram.enableAttributeArray("vertexColor");

    //Draw the vertices
    glDrawArrays(GL_TRIANGLES, 0, numCubeVertices);

    //Disable the vertex attribute and release the shader program from memory
    shaderProgram.disableAttributeArray("vertex");
    shaderProgram.disableAttributeArray("vertexColor");
    shaderProgram.release();
}

void MyPanelOpenGL::toggleWireframe(){
    wireframeState = !wireframeState;
    update();
}

void MyPanelOpenGL::toggleProjection(){
    if(projectionState){
        MatrixMath::makeIdentity(&pMatrix);
        MatrixMath::makePerspectiveMatrix(&pMatrix, 1.0f, 100.0f,(float) viewWidth/viewHeight, (float) -viewWidth/viewHeight, 1.0f, -1.0f);
        MatrixMath::scale(&scaleMatrix, 1/projtoOrthRatio, 1/projtoOrthRatio , 1/projtoOrthRatio);
        MatrixMath::matrixMult4x4(&mMatrix,&scaleMatrix, &mMatrix);
        projectionState = false;
    }else{
        MatrixMath::makeIdentity(&pMatrix);
        MatrixMath::makeOrthographicMatrix(&pMatrix, 1.0f, 100.0f,(float) viewWidth/viewHeight, (float) -viewWidth/viewHeight, 1.0f, -1.0f);
        MatrixMath::scale(&scaleMatrix,projtoOrthRatio,projtoOrthRatio,projtoOrthRatio);
        MatrixMath::matrixMult4x4(&mMatrix,&scaleMatrix, &mMatrix);
        projectionState = true;
    }
    update();
}


void MyPanelOpenGL::translateCube(double x, double y, double z){
   MatrixMath::translate(&tranMatrix,(GLfloat)x,(GLfloat)y,(GLfloat)z);
   MatrixMath::matrixMult4x4(&mMatrix, &tranMatrix, &mMatrix);
    update();
}

void MyPanelOpenGL::rotateCube(double xRot, double yRot, double zRot, double xPos, double yPos, double zPos, bool arbitrary){
    if(arbitrary){
        MatrixMath::translate(&tranMatrix, -xPos,-yPos, -zPos);
        MatrixMath::rotateX(&rotXMatrix,xRot);
        MatrixMath::rotateY(&rotYMatrix,yRot);
        MatrixMath::rotateZ(&rotZMatrix,zRot);
        MatrixMath::matrixMult4x4(&tempMatrix,&rotZMatrix,&tranMatrix);
        MatrixMath::matrixMult4x4(&tempMatrix,&rotYMatrix,&tempMatrix);
        MatrixMath::matrixMult4x4(&tempMatrix,&rotXMatrix,&tempMatrix);
        MatrixMath::translate(&tranMatrix, xPos, yPos, zPos);
        MatrixMath::matrixMult4x4(&tempMatrix,&tranMatrix,&tempMatrix);
        MatrixMath::matrixMult4x4(&mMatrix, &tempMatrix, &mMatrix);
    }else{
        MatrixMath::translate(&tranMatrix, -mMatrix[3][0],-mMatrix[3][1], -mMatrix[3][2]);
        MatrixMath::rotateX(&rotXMatrix,xRot);
        MatrixMath::rotateY(&rotYMatrix,yRot);
        MatrixMath::rotateZ(&rotZMatrix,zRot);
        MatrixMath::matrixMult4x4(&tempMatrix,&rotZMatrix,&tranMatrix);
        MatrixMath::matrixMult4x4(&tempMatrix,&rotYMatrix,&tempMatrix);
        MatrixMath::matrixMult4x4(&tempMatrix,&rotXMatrix,&tempMatrix);
        MatrixMath::translate(&tranMatrix,mMatrix[3][0],mMatrix[3][1], mMatrix[3][2]);
        MatrixMath::matrixMult4x4(&tempMatrix,&tranMatrix,&tempMatrix);
        MatrixMath::matrixMult4x4(&mMatrix, &tempMatrix, &mMatrix);
    }


    update();
}

void MyPanelOpenGL::scaleCube(double x, double y, double z){
    MatrixMath::scale(&scaleMatrix,(GLfloat)x,(GLfloat)y,(GLfloat)z);
    MatrixMath::matrixMult4x4(&mMatrix,&scaleMatrix, &mMatrix);
    update();
}

void MyPanelOpenGL::mirrorCube(bool xMirror, bool yMirror, bool zMirror){
    if(xMirror){
        MatrixMath::rotateX(&rotXMatrix,180);
        MatrixMath::matrixMult4x4(&mMatrix, &rotXMatrix, &mMatrix);
    }else if(yMirror){
        MatrixMath::rotateY(&rotYMatrix,180);
        MatrixMath::matrixMult4x4(&mMatrix, &rotYMatrix, &mMatrix);
    }else if(zMirror){
        MatrixMath::rotateZ(&rotZMatrix,180);
        MatrixMath::matrixMult4x4(&mMatrix, &rotZMatrix, &mMatrix);
    }
    update();
}

void MyPanelOpenGL::shearCube(bool xShear ,bool yShear,bool zShear){
    if(xShear){
        mMatrix[0][1] += 0.25;
        mMatrix[0][2] += 0.25;
        mMatrix[1][0] += 0;
        mMatrix[1][2] += 0;
        mMatrix[2][0] += 0;
        mMatrix[2][1] += 0;
    }else if(yShear){
        mMatrix[0][1] += 0;
        mMatrix[0][2] += 0;
        mMatrix[1][0] += 0.25;
        mMatrix[1][2] += 0.25;
        mMatrix[2][0] += 0;
        mMatrix[2][1] += 0;
    }else if(zShear){
        mMatrix[0][1] += 0;
        mMatrix[0][2] += 0;
        mMatrix[1][0] += 0;
        mMatrix[1][2] += 0;
        mMatrix[2][0] += 0.25;
        mMatrix[2][1] += 0.25;
    }
    update();
}

void MyPanelOpenGL::restartCube(){
    MatrixMath::makeIdentity(&mMatrix);
    MatrixMath::rotateX(&rotXMatrix,beta);
    MatrixMath::rotateY(&rotYMatrix,alpha);
    MatrixMath::matrixMult4x4(&tempMatrix, &rotXMatrix, &rotYMatrix);
    MatrixMath::matrixMult4x4(&mMatrix, &tempMatrix, &mMatrix);
    update();
}

