#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../include/rendering/Renderer.h"
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Mesh *Renderer::circleMesh = nullptr;

std::vector<float> createCircleVertices(float radius, int segments)
{
    std::vector<float> vertices;

    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    for (int i = 0; i <= segments; i++)
    {
        float angle = 2.0f * 3.1415926f * i / segments;

        vertices.push_back(radius * cos(angle));

        vertices.push_back(radius * sin(angle));
    }

    return vertices;
}

void Renderer::initialize()
{
    std::vector<float> vertices = createCircleVertices(0.2f, 64);

    circleMesh = new Mesh(vertices);
}

void Renderer::render(std::vector<Object> &objects, Shader &shader, Camera &camera)
{
    glm::mat4 projection =
        glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

    unsigned int projectionLoc = glGetUniformLocation(shader.ID, "projection");

    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glm::mat4 view = camera.getViewMatrix();

    unsigned int viewLoc = glGetUniformLocation(shader.ID, "view");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    for (auto &obj : objects)
    {
        glm::mat4 model = glm::mat4(1.0f);

        glm::vec2 position = obj.getPosition();

        model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));

        model = glm::scale(model, glm::vec3(50.0f, 50.0f, 1.0f));

        unsigned int modelLoc =
            glGetUniformLocation(shader.ID, "model");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        circleMesh->draw();
    }
}