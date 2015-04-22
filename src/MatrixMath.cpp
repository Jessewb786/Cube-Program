#include "MatrixMath.h"
#define PI 3.1415926f

//Function for multiplying 2 matrixes
void MatrixMath::matrixMult4x4(GLfloat (*result)[4][4], GLfloat (*m1)[4][4], GLfloat (*m2)[4][4])
{
    GLfloat interMatrix[4][4];
    MatrixMath::makeIdentity(&interMatrix);
    interMatrix[0][0] = (*m1)[0][0] * (*m2)[0][0] + (*m1)[1][0] * (*m2)[0][1] + (*m1)[2][0] * (*m2)[0][2] + (*m1)[3][0] * (*m2)[0][3];
    interMatrix[1][0] = (*m1)[0][0] * (*m2)[1][0] + (*m1)[1][0] * (*m2)[1][1] + (*m1)[2][0] * (*m2)[1][2] + (*m1)[3][0] * (*m2)[1][3];
    interMatrix[2][0] = (*m1)[0][0] * (*m2)[2][0] + (*m1)[1][0] * (*m2)[2][1] + (*m1)[2][0] * (*m2)[2][2] + (*m1)[3][0] * (*m2)[2][3];
    interMatrix[3][0] = (*m1)[0][0] * (*m2)[3][0] + (*m1)[1][0] * (*m2)[3][1] + (*m1)[2][0] * (*m2)[3][2] + (*m1)[3][0] * (*m2)[3][3];

    interMatrix[0][1] = (*m1)[0][1] * (*m2)[0][0] + (*m1)[1][1] * (*m2)[0][1] + (*m1)[2][1] * (*m2)[0][2] + (*m1)[3][1] * (*m2)[0][3];
    interMatrix[1][1] = (*m1)[0][1] * (*m2)[1][0] + (*m1)[1][1] * (*m2)[1][1] + (*m1)[2][1] * (*m2)[1][2] + (*m1)[3][1] * (*m2)[1][3];
    interMatrix[2][1] = (*m1)[0][1] * (*m2)[2][0] + (*m1)[1][1] * (*m2)[2][1] + (*m1)[2][1] * (*m2)[2][2] + (*m1)[3][1] * (*m2)[2][3];
    interMatrix[3][1] = (*m1)[0][1] * (*m2)[3][0] + (*m1)[1][1] * (*m2)[3][1] + (*m1)[2][1] * (*m2)[3][2] + (*m1)[3][1] * (*m2)[3][3];

    interMatrix[0][2] = (*m1)[0][2] * (*m2)[0][0] + (*m1)[1][2] * (*m2)[0][1] + (*m1)[2][2] * (*m2)[0][2] + (*m1)[3][2] * (*m2)[0][3];
    interMatrix[1][2] = (*m1)[0][2] * (*m2)[1][0] + (*m1)[1][2] * (*m2)[1][1] + (*m1)[2][2] * (*m2)[1][2] + (*m1)[3][2] * (*m2)[1][3];
    interMatrix[2][2] = (*m1)[0][2] * (*m2)[2][0] + (*m1)[1][2] * (*m2)[2][1] + (*m1)[2][2] * (*m2)[2][2] + (*m1)[3][2] * (*m2)[2][3];
    interMatrix[3][2] = (*m1)[0][2] * (*m2)[3][0] + (*m1)[1][2] * (*m2)[3][1] + (*m1)[2][2] * (*m2)[3][2] + (*m1)[3][2] * (*m2)[3][3];

    interMatrix[0][3] = (*m1)[0][3] * (*m2)[0][0] + (*m1)[1][3] * (*m2)[0][1] + (*m1)[2][3] * (*m2)[0][2] + (*m1)[3][3] * (*m2)[0][3];
    interMatrix[1][3] = (*m1)[0][3] * (*m2)[1][0] + (*m1)[1][3] * (*m2)[1][1] + (*m1)[2][3] * (*m2)[1][2] + (*m1)[3][3] * (*m2)[1][3];
    interMatrix[2][3] = (*m1)[0][3] * (*m2)[2][0] + (*m1)[1][3] * (*m2)[2][1] + (*m1)[2][3] * (*m2)[2][2] + (*m1)[3][3] * (*m2)[2][3];
    interMatrix[3][3] = (*m1)[0][3] * (*m2)[3][0] + (*m1)[1][3] * (*m2)[3][1] + (*m1)[2][3] * (*m2)[3][2] + (*m1)[3][3] * (*m2)[3][3];
    MatrixMath::copyMatrix(&interMatrix,result);
}


// Makes an identity matrix
void MatrixMath::makeIdentity(GLfloat (*result)[4][4])
{
    //Clear the result matrix
    for(int j = 0; j < 4; j++){
        for (int i = 0; i < 4; i++) {
            (*result)[i][j] = 0.0f;
        }
    }
    (*result)[0][0] = (*result)[1][1] = (*result)[2][2] = (*result)[3][3] = 1.0f;
}

// Returns a matrix that translates by x, y and z amount
void MatrixMath::translate(GLfloat (*result)[4][4], GLfloat x, GLfloat y, GLfloat z)
{
    makeIdentity(result);
    (*result)[3][0] = x;
    (*result)[3][1] = y;
    (*result)[3][2] = -z;
}

// Returns matrices that rotate about the X, Y and Z axes by a rotation amount (radians)
void MatrixMath::rotateX(GLfloat (*result)[4][4], GLfloat rotation)
{
	makeIdentity(result);
    rotation = (PI/180.0f*rotation);
    (*result)[1][1] = (*result)[2][2] = cos(rotation);
    (*result)[2][1] = sin(rotation);
    (*result)[1][2] = -(*result)[2][1];
}
void MatrixMath::rotateY(GLfloat (*result)[4][4], GLfloat rotation)
{
	makeIdentity(result);
    rotation = (PI/180.0f*rotation);
    (*result)[0][0] = (*result)[2][2] = cos(rotation);
    (*result)[2][0] = -sin(rotation);
    (*result)[0][2] = -(*result)[2][0];
}
void MatrixMath::rotateZ(GLfloat (*result)[4][4], GLfloat rotation)
{
    makeIdentity(result);
    rotation = -(PI/180.0f*rotation);
    (*result)[0][0] = (*result)[1][1] = cos(rotation);
    (*result)[1][0] = sin(rotation);
    (*result)[0][1] = -(*result)[1][0];
}

// 2) Create the makeScale method here and fill in the code using the examples above and below
void MatrixMath::scale(GLfloat (*result)[4][4], GLfloat x, GLfloat y, GLfloat z)
{
    makeIdentity(result);
    (*result)[0][0] = (*result)[0][0] * x;
    (*result)[1][1] = (*result)[1][1] * y;
    (*result)[2][2] = (*result)[2][2] * z;
}


void MatrixMath::makePerspectiveMatrix(GLfloat (*result)[4][4], GLfloat n, GLfloat f, GLfloat t, GLfloat b, GLfloat r, GLfloat l) {
    makeIdentity(result);
    (*result)[0][0] = 2*n/(r-l);
    (*result)[1][1] = 2*n/(t-b);
    (*result)[2][0] = (r+l)/(r-l);
    (*result)[2][1] = (t+b)/(t-b);
    (*result)[2][2] = -(f + n)/(f - n);
    (*result)[2][3] = -1;
    (*result)[3][2] = -(2.0f*f*n)/(f - n);
    (*result)[3][3] = 0;
}

void MatrixMath::makeOrthographicMatrix(GLfloat (*result)[4][4], GLfloat n, GLfloat f, GLfloat t, GLfloat b, GLfloat r, GLfloat l) {
    makeIdentity(result);
    (*result)[0][0] = 2/(r-l);
    (*result)[1][1] = 2/(t-b);
    (*result)[2][2] = -2/(f-n);
    (*result)[3][0] = -(r+l)/(r-l);
    (*result)[3][1] = -(t+b)/(t-b);
    (*result)[3][2] = -(f+n)/(f-n);
}

void MatrixMath::copyMatrix(GLfloat (*src)[4][4], GLfloat (*dest)[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
        (*dest)[i][j] = (*src)[i][j];
        }
	}
}

