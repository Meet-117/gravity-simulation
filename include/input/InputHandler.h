#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../simulation/Object.h"
#include <vector>

class InputHandler
{
public:
    static void processInput(GLFWwindow *window, bool &paused);
    static void handleMouseInput(GLFWwindow *window, std::vector<Object> &objects);
};