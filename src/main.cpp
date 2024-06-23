/*
 * main.cpp
 * 
 * This module serves as the entry point for the application. It sets up the
 * main game loop, initializes the window and the Box2D world, and handles 
 * the rendering, user input, and physics updates.
 *
 * The main loop ensures the application runs at the target frame rate by 
 * calculating the time difference between frames and updating the physics 
 * and rendering accordingly. It continues to run until the window is closed.
 *
 * The module includes the following headers:
 * - window.h: For window initialization and management using GLFW.
 * - userInput.h: For processing user input.
 * - rendering.h: For rendering the scene.
 * - physics.h: For updating the physics simulation.
 *
 * Author: Danny Martinez Hibbert
 * Date: 2024-06-23
 */

#include "window.h"
#include "userInput.h"
#include "rendering.h"
#include "physics.h"

double lastFrameTime = glfwGetTime();

int main()
{
    GLFWwindow* window = initWindow(WIDTH, HEIGHT);
    initWorld(); // create the universal box2d world object 

    while(!glfwWindowShouldClose(window))
    {
        double currentFrameTime = glfwGetTime();
        double deltaTime = currentFrameTime - lastFrameTime;

        if (deltaTime >= targetFrameTime)
        {
            stepPhysics();
            processInput(window);
            renderScene();
            glfwSwapBuffers(window);
            glfwPollEvents();

            lastFrameTime = currentFrameTime;
        }
    }

    glfwTerminate();
    return 0;
}
