/*
 * userInput.cpp
 * 
 * This module handles user input for the application, including keyboard and mouse events.
 * It processes input to perform actions such as closing the window and adding circles to the 
 * physics world upon mouse clicks, with a cooldown to prevent rapid repeated input.
 *
 * The functionalities provided by this module include:
 * - processInput: Processes keyboard and mouse input, closes the window on ESC key press,
 *   and adds a circle to the world on left mouse button click with a cooldown period.
 *
 * The module includes the following headers:
 * - userInput.h: For the function declarations related to user input.
 * - shapeFactory.h: For creating shape instances.
 * - physics.h: For physics-related functions and definitions.
 * - utilities.h: For general utility functions.
 * 
 * Author: Danny Martinez Hibbert
 * Date: 2024-06-23
 */

#include "userInput.h"
#include "shapeFactory.h"
#include "physics.h"
#include "utilities.h"
#include <iostream>
#include <thread>
#include <chrono>

bool mousePressed = false;

std::chrono::time_point<std::chrono::system_clock> lastMouseClickTime;  // Initialize a timestamp
const std::chrono::duration<float> cooldownDuration(0.2); //in seconds

double xpos;
double ypos;

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        delete world;
    }
    else if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        auto currentTime = std::chrono::system_clock::now();
        
        if((currentTime - lastMouseClickTime >= cooldownDuration)) {
            glfwGetCursorPos(window, &xpos, &ypos);
            addCircle(xpos, ypos, 4, true, 3); 
            
            lastMouseClickTime = currentTime;
        }
    }
}
