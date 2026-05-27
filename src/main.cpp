#include "../include/simulation/Object.h"
#include "../include/simulation/PhysicsEngine.h"

#include "../include/rendering/Renderer.h"
#include "../include/rendering/Shader.h"
#include "../include/rendering/Camera.h"

#include "../include/input/InputHandler.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>

int main()
{
    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "Gravity Simulation", NULL, NULL);

    if (!window)
    {
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        std::cout
            << "GLEW Initialization Failed\n";

        return -1;
    }

    glViewport(0, 0, 800, 600);

    Shader shader("shaders/basic.vert", "shaders/basic.frag");

    Renderer::initialize();

    Camera camera;

    bool paused = false;

    std::vector<Object> objects;

    objects.push_back(
        Object(glm::vec2(400.0f, 300.0f), glm::vec2(2.0f, 2.0f), 100.0f));

    float deltaTime = 1.0f;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        InputHandler::processInput(window, paused);

        InputHandler::handleMouseInput(window, objects);

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            camera.position.x -= 5.0f;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            camera.position.x += 5.0f;
        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            camera.position.y += 5.0f;
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            camera.position.y -= 5.0f;
        }

        if (!paused)
        {
            PhysicsEngine::update(objects, deltaTime);

            PhysicsEngine::checkCollisions(objects);

            for (auto &obj : objects)
            {
                PhysicsEngine::checkBoundary(obj, 0, 600, 0, 800);
            }
        }

        shader.use();

        Renderer::render(objects, shader, camera);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}