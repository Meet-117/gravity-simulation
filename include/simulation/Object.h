#pragma once
#include <vector>
#include <glm/glm.hpp>

class Object
{
    glm::vec2 position;
    glm::vec2 velocity;

public:
    float mass;
    float density;
    float radius;

    bool initializing;
    bool launched;

    std::vector<float> hue;

    Object(
        glm::vec2 initPosition,
        glm::vec2 initVelocity,
        float initMass);

    void updatePosition(float deltaTime);
    void accelerate(float x, float y);
    void setVelocity(float x, float y);
    glm::vec2 getPosition() const;
    void calculateRadius();
    glm::vec2 getVelocity() const;
    void setPosition(float x, float y);
};