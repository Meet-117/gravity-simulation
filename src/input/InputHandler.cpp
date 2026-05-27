#include "../../include/input/InputHandler.h"

void InputHandler::processInput(
    GLFWwindow *window,
    bool &paused)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    static bool pPressed = false;

    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        if (!pPressed)
        {
            paused = !paused;

            pPressed = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE)
    {
        pPressed = false;
    }
}

void InputHandler::handleMouseInput(GLFWwindow *window, std::vector<Object> &objects)
{
    static bool mousePressed = false;

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        if (!mousePressed)
        {
            double mouseX;
            double mouseY;

            glfwGetCursorPos(
                window,
                &mouseX,
                &mouseY);

            mouseY = 600 - mouseY;

            objects.push_back(
                Object(
                    {(float)mouseX,
                     (float)mouseY},
                    {0,
                     0},
                    100));

            mousePressed = true;
        }
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        mousePressed = false;
    }
}