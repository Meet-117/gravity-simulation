#pragma once

#include <vector>
#include "Object.h"

class PhysicsEngine
{
public:
    static void update(std::vector<Object> &objects, float deltaTime);

    static void checkBoundary(Object& object, int bottom, int top, int left, int right);

    static void checkCollisions(std::vector<Object>& objects);
};