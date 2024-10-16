#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "dui.h"

#define WIDTH 600
#define HEIGHT 800

GLFWwindow* window;

void handleInput(GLFWwindow* window) {

	// Exit
	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	
}

int main() {

    glfwInit();
    window = glfwCreateWindow(WIDTH, HEIGHT, "DUI", NULL, NULL);
    glfwMakeContextCurrent(window);

	DUI_init(window, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {

		handleInput(window);

		




		DUI_update();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

