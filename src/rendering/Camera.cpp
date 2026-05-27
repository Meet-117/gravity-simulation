#include "../../include/rendering/Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
    position = glm::vec2(0.0f);

    zoom = 1.0f;
}

glm::mat4 Camera::getViewMatrix()
{
    glm::mat4 view = glm::mat4(1.0f);

    view = glm::translate(view, glm::vec3(-position.x, -position.y, 0.0f));

    return view;
}