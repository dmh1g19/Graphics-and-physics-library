/*
 * circle.cpp
 * 
 * This module implements the Circle class, which includes methods for initializing
 * buffer objects and shaders, updating the circle's transformation matrix, and rendering
 * the circle using OpenGL.
 *
 * The Circle class provides the following functionalities:
 * - init: Initializes vertex and fragment shaders, and sets up buffer objects.
 * - update: Updates the circle's position and rotation using a transformation matrix.
 * - render: Sends the transformation matrix to the shader and renders the circle.
 * - useShaderProg: Activates the shader program used by the circle.
 * - draw: Draws the circle with a specified range of vertices.
 *
 * The module includes the following headers:
 * - shapeFactory.h: For the ShapeFactory class.
 * - rendering.h: For rendering utilities and functions.
 * - window.h: For window management.
 * - physics.h: For physics-related functions.
 * - utilities.h: For general utility functions.
 *
 * Author: Danny Martinez Hibbert
 * Date: 2024-06-23
 */

#include "shapeFactory.h"
#include "rendering.h"
#include "window.h"
#include "physics.h"
#include "utilities.h"
#include <iostream>

unsigned int globalShaderProg;

void Circle::init(std::string vertexShaderPath, std::string fragmentShaderPath) {
    initBuffers(VBO, VAO, vertices, sizeof(vertices));

    if(!globalShaderProg) {
        std::cout << "Gobal sphere shader initialized" << std::endl;
        globalShaderProg = initShaders(vertexShaderPath, fragmentShaderPath);
    }
    else {
        std::cout << "Using gobal sphere shader program" << std::endl;
    }
}

void Circle::update(const glm::vec2& position, float rotation) {
    //std::cout << "Updating position: " + std::to_string(position.x) + ", " + std::to_string(position.y) + ", " + std::to_string(rotation) << std::endl;
    transformationMatrix = glm::mat4(1.0f);
    transformationMatrix = glm::translate(transformationMatrix, glm::vec3(screenCoordsToOpenGL(position), 0.0f));
    transformationMatrix = glm::scale(transformationMatrix, glm::vec3(shapeSizeToOpenGLWidth(radius), shapeSizeToOpenGLHeight(radius), 1.0f));
    transformationMatrix = glm::rotate(transformationMatrix, rotation, glm::vec3(0.0, 0.0, 1.0));
}

void Circle::render() {
    unsigned int transformLoc = glGetUniformLocation(globalShaderProg, "transform");

    if (transformLoc == -1) {
        std::cerr << "Could not find uniform location for 'transform'" << std::endl;
    }
    else {
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformationMatrix));
    }
}

void Circle::useShaderProg() {
    useSpecificShader(globalShaderProg);
}

void Circle::draw() {
    int minVerts = 0;
    int maxVerts = 30*3;
    drawShape(globalShaderProg, VAO, minVerts, maxVerts, true);
}
