#include "../../include/simulation/Object.h"
#include <cmath>

Object::Object(glm::vec2 initPosition, glm::vec2 initVelocity, float initMass)
{
    position = initPosition;
    velocity = initVelocity;

    mass = initMass;

    density = 0.08375f;

    initializing = false;
    launched = false;

    hue = {1.0f, 0.0f, 0.0f, 1.0f};
    calculateRadius();
}

void Object::calculateRadius()
{
    float volume = mass / density;

    radius = pow((3.0f * volume) / (4.0f * 3.14159265359f), 1.0f / 3.0f);
}

void Object::updatePosition(float deltaTime)
{
    position += velocity * deltaTime;
}

glm::vec2 Object::getVelocity() const
{
    return velocity;
}

void Object::setPosition(float x, float y)
{
    position[0] = x;
    position[1] = y;
}

glm::vec2 Object::getPosition() const
{
    return position;
}
void Object::accelerate(float x, float y)
{
    velocity[0] += x;
    velocity[1] += y;
}

void Object::setVelocity(float x, float y)
{
    velocity[0] = x;
    velocity[1] = y;
}