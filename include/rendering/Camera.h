#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    glm::vec2 position;

    float zoom;

    Camera();

    glm::mat4 getViewMatrix();
};