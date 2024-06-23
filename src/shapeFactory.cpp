/*
 * shapeFactory.cpp
 * 
 * This module contains the implementation of the ShapeFactory class,
 * which is responsible for creating instances of different shapes
 * based on the provided shape type.
 *
 * The ShapeFactory class currently supports the creation of Circle objects.

 * If an unknown shape type is requested, it will return a nullptr and 
 * output an error message to the standard output.
 *
 * Author: Danny Martinez Hibbert
 * Date: 2024-06-23
 */

#include "shapeFactory.h"
#include <memory>
#include <iostream>

std::shared_ptr<Shape> ShapeFactory::createShape(const std::string& shapeType) {
    if (shapeType == "Circle") {
        return std::make_unique<Circle>();
    }
    else {
        std::cout << "Unknown shape type" << std::endl;
        return nullptr; // Return nullptr to indicate an unknown shape type.
    }
}
