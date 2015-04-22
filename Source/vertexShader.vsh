#version 130

uniform mat4 pMatrix;
uniform mat4 mMatrix;
uniform mat4 vMatrix;
in vec4 vertex;
in vec4 vertexColor;
out vec4 color;

void main(void){
    gl_Position = pMatrix*vMatrix*mMatrix*vertex;
    color=vertexColor;
}
