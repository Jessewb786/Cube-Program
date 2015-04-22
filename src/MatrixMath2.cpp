#include "MatrixMath.h"
#define A11 0
#define A12 1
#define A13 2
#define A14 3
#define A21 4
#define A22 5
#define A23 6
#define A24 7
#define A31 8
#define A32 9
#define A33 10
#define A34 11
#define A41 12
#define A42 13
#define A43 14
#define A44 15

//Function for multiplying 2 matrixes
void MatrixMath::matrixMult4x4(GLfloat* result, GLfloat* m1, GLfloat* m2)
{
    //Clear the result matrix
    for (int i = 0; i < 16; i++) {
        result[i] = 0.0f;
    }
    result[A11] = m1[A11] * m2[A11] + m1[A12] * m2[A21] + m1[A13] * m2[A31] + m1[A14] * m2[A41];
    result[A12] = m1[A11] * m2[A12] + m1[A12] * m2[A22] + m1[A13] * m2[A32] + m1[A14] * m2[A42];
    result[A13] = m1[A11] * m2[A13] + m1[A12] * m2[A23] + m1[A13] * m2[A33] + m1[A14] * m2[A43];
    result[A14] = m1[A11] * m2[A14] + m1[A12] * m2[A24] + m1[A13] * m2[A34] + m1[A14] * m2[A44];

    result[A21] = m1[A21] * m2[A11] + m1[A22] * m2[A21] + m1[A23] * m2[A31] + m1[A24] * m2[A41];
    result[A22] = m1[A21] * m2[A12] + m1[A22] * m2[A22] + m1[A23] * m2[A32] + m1[A24] * m2[A42];
    result[A23] = m1[A21] * m2[A13] + m1[A22] * m2[A23] + m1[A23] * m2[A33] + m1[A24] * m2[A43];
    result[A24] = m1[A21] * m2[A14] + m1[A22] * m2[A24] + m1[A23] * m2[A34] + m1[A24] * m2[A44];

    result[A31] = m1[A31] * m2[A11] + m1[A32] * m2[A21] + m1[A33] * m2[A31] + m1[A34] * m2[A41];
    result[A32] = m1[A31] * m2[A12] + m1[A32] * m2[A22] + m1[A33] * m2[A32] + m1[A34] * m2[A42];
    result[A33] = m1[A31] * m2[A13] + m1[A32] * m2[A23] + m1[A33] * m2[A33] + m1[A34] * m2[A43];
    result[A34] = m1[A31] * m2[A14] + m1[A32] * m2[A24] + m1[A33] * m2[A34] + m1[A34] * m2[A44];

    result[A41] = m1[A41] * m2[A11] + m1[A42] * m2[A21] + m1[A43] * m2[A31] + m1[A44] * m2[A41];
    result[A42] = m1[A41] * m2[A12] + m1[A42] * m2[A22] + m1[A43] * m2[A32] + m1[A44] * m2[A42];
    result[A43] = m1[A41] * m2[A13] + m1[A42] * m2[A23] + m1[A43] * m2[A33] + m1[A44] * m2[A43];
    result[A44] = m1[A41] * m2[A14] + m1[A42] * m2[A24] + m1[A43] * m2[A34] + m1[A44] * m2[A44];
}


// Makes an identity matrix
void MatrixMath::makeIdentity(GLfloat* result)
{
    for (int i = 0; i < 16; i++) {
        result[i] = 0.0f;
    }
    result[A11] = result[A22] = result[A33] = result[A44] = 1.0f;
}

// Returns a matrix that translates by x, y and z amount
void MatrixMath::translate(GLfloat* result, GLfloat x, GLfloat y, GLfloat z)
{
	makeIdentity(result);
    result[A14] = x;
    result[A24] = y;
    result[A34] = z;
}

// Returns matrices that rotate about the X, Y and Z axes by a rotation amount (radians)
void MatrixMath::rotateX(GLfloat* result, GLfloat rotation)
{
	makeIdentity(result);
    result[A22] = result[A33] = cos(rotation);
    result[A23] = sin(rotation);
    result[A32] = -result[A23];
}
void MatrixMath::rotateY(GLfloat* result, GLfloat rotation)
{
	makeIdentity(result);
    result[A11] = result[A33] = cos(rotation);
    result[A13] = -sin(rotation);
    result[A31] = -result[A13];
}
void MatrixMath::rotateZ(GLfloat* result, GLfloat rotation)
{
	makeIdentity(result);
    result[A11] = result[A22] = cos(rotation);
    result[A12] = sin(rotation);
    result[A21] = -result[A12];
}

// 2) Create the makeScale method here and fill in the code using the examples above and below
void MatrixMath::scale(GLfloat* result, GLfloat x, GLfloat y, GLfloat z)
{
	makeIdentity(result);
    result[A11] = x;
    result[A22] = y;
    result[A33] = z;
}


void MatrixMath::makePerspectiveMatrix(GLfloat* result, GLfloat fov, GLfloat aspect, GLfloat nearPlane, GLfloat farPlane) {
	GLfloat f = 1.0f / tan(fov*3.1415926f / 360.0f);
	makeIdentity(result);
    result[A11] = f / aspect;
    result[A22] = f;
    result[A33] = ((farPlane + nearPlane) / (nearPlane - farPlane));
    result[A34] = -1;
    result[A43] = (2.0f*farPlane*nearPlane) / (nearPlane - farPlane);
    result[A44] = 0;
}

void MatrixMath::translateMatrixBy(GLfloat* result, GLfloat x, GLfloat y, GLfloat z)
{
    result[A14] += x;
    result[A24] += y;
    result[A34] += z;
}

void MatrixMath::copyMatrix(GLfloat* src, GLfloat* dest)
{
    for (int i = 0; i < 16; i++) {
        dest[i] = src[i];
	}
}

void MatrixMath::print4x4Matrix(GLfloat* mat)
{
    printf("====================================");
    for (int i = 0; i < 16; i++) {
        if (i % 4 == 0) printf("\n");
        printf("%f\t", mat[i]);
    }
    printf("\n");
}
