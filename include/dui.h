#ifndef DUI_H
#define DUI_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef uint32_t DUI_Element;
typedef uint32_t DUI_Color;

typedef enum {
	BOX,
	BUTTON,
	DROPDOWN,
	INPUT
} DUI_ElementType; 

GLuint createShaderProgram(GLfloat* vertices, size_t vertices_size, const char* vertexShaderSource, const char* fragmentShaderSource, GLuint* VAO, GLuint* VBO);
GLfloat* generateVertices(size_t* vertices_size);
void DUI_update();
void DUI_init();

#endif
