/*
 * window.cpp
 * 
 * This module handles the initialization and management of the GLFW window for the application.
 * It includes functions to initialize the window, set up OpenGL context, and handle window
 * resizing dynamically.
 *
 * The functionalities provided by this module include:
 * - framebuffer_size_callback: Adjusts the viewport when the window is resized.
 * - initWindow: Initializes GLFW, creates a window, sets up OpenGL context, and configures
 *   the viewport and callback for window resizing.
 *
 * The module includes the following headers:
 * - window.h: For the function declarations related to window management.
 * - userInput.h: For processing user input (if required for future extensions).
 * - rendering.h: For rendering utilities and functions.
 * - <iostream>: For standard input and output stream.
 * 
 * Author: Danny Martinez Hibbert
 * Date: 2024-06-23
 */

#include "window.h"
#include "userInput.h"
#include "rendering.h"
#include <iostream>

// Dynamically redefine window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLFWwindow* initWindow(int w, int h) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(w, h, "LearnOpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable V-Sync to sync with the refresh rate of the display

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }   

    glViewport(0, 0, w, h);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
    
    return window;
}