// buffr_cmake.cpp : Defines the entry point for the application.
//

#include "main.h"

#include <windows.h>
#include <GLFW/glfw3.h>
#include <iostream>

// change this to int main() to allow the console. 
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
    GLFWwindow* window;
    int windowSizeW = 640, windowSizeH = 480;
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
    int count;
    int windowWidth, windowHeight;
    int monitorX, monitorY;

    // I am assuming that main monitor is in the 0 position
    GLFWmonitor** monitors = glfwGetMonitors(&count);
    const GLFWvidmode* videoMode = glfwGetVideoMode(monitors[0]);
    windowWidth = (videoMode->width / 2.0) - (windowSizeW / 2);
    windowHeight = (videoMode->height / 2.0) - (windowSizeH / 2);

    glfwGetMonitorPos(monitors[0], &monitorX, &monitorY);

    // set the visibility window hint to false for subsequent window creation
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowSizeW, windowSizeH, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // reset the window hints to default
    glfwDefaultWindowHints();

    glfwSetWindowPos(window,
        monitorX + (videoMode->width - windowWidth) / 2,
        monitorY + (videoMode->height - windowHeight) / 2);

    // show the window
    glfwShowWindow(window);
    // uncomment following line to see the border of window
    glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0, 0, 1);
        glVertex3f(-0.5, -0.5, -1);
        glColor3f(0, 1, 0);
        glVertex3f(0.5, -0.5, -1);
        glColor3f(1, 0, 1);
        glVertex3f(0.5, 0.5, -1);
        glColor3f(1, 0, 1);
        glVertex3f(-0.5, 0.5, -1);
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}