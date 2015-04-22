#ifndef MATH_HELPER
#define MATH_HELPER

#include "GL/glu.h"
#include <math.h>
#include <stdio.h>

class MatrixMath {
public:
	// This is a multiplication of matrices m1 and m2.
    static void matrixMult4x4(GLfloat (*result)[4][4], GLfloat (*m1)[4][4], GLfloat (*m2)[4][4]);
	// Makes an identity matrix
    static void makeIdentity(GLfloat (*result)[4][4]);

	// Returns a matrix that translates by x, y and z amount
    static void translate(GLfloat (*result)[4][4], GLfloat x, GLfloat y, GLfloat z);

	// Returns matrices that rotate about the X, Y and Z axes by a rotation amount (radians)
    static void rotateX(GLfloat (*result)[4][4], GLfloat rotation);
    static void rotateY(GLfloat (*result)[4][4], GLfloat rotation);
    static void rotateZ(GLfloat (*result)[4][4], GLfloat rotation);

	// Returns a scaling matrix
    static void scale(GLfloat (*result)[4][4], GLfloat x, GLfloat y, GLfloat z);

	// Make a perspective camera
    static void makePerspectiveMatrix(GLfloat (*result)[4][4], GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
    static void makeOrthographicMatrix(GLfloat (*result)[4][4], GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);

	// Copies the src matrix into the dest matrix
    static void copyMatrix(GLfloat (*src)[4][4], GLfloat (*dest)[4][4]);

private:
};


#endif
