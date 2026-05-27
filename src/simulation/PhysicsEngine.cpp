#include "../../include/simulation/PhysicsEngine.h"
#include <cmath>
#include <glm/glm.hpp>
#include <vector>

void PhysicsEngine::update(std::vector<Object> &objects, float deltaTime)
{
    for (auto &obj : objects)
    {
        obj.updatePosition(deltaTime);
    }
}

void PhysicsEngine::checkCollisions(std::vector<Object> &objects)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        for (size_t j = i + 1; j < objects.size(); j++)
        {
            glm::vec2 delta = objects[j].getPosition() - objects[i].getPosition();

            float distance = glm::length(delta);

            if (distance < objects[i].radius + objects[j].radius)
            {
                objects[i].accelerate(0, -2 * objects[i].getVelocity().y);

                objects[j].accelerate(0, -2 * objects[j].getVelocity().y);
            }
        }
    }
}

void PhysicsEngine::checkBoundary(Object &object, int bottom, int top, int left, int right)
{
    float radius = object.radius;

    glm::vec2 position = object.getPosition();

    glm::vec2 velocity = object.getVelocity();

    if (position.y < bottom + radius || position.y > top - radius)
    {
        position.y = position.y < bottom + radius ? bottom + radius : top - radius;

        velocity.y *= -0.8f;
    }

    if (position.x < left + radius || position.x > right - radius)
    {
        position.x = position.x < left + radius ? left + radius : right - radius;

        velocity[0] *= -0.8f;
    }

    object.setPosition(position.x, position.y);

    object.setVelocity(velocity.x, velocity.y);
}