#pragma once
#include "Shader.h"
#include "../simulation/Object.h"
#include "../rendering/Camera.h"
#include "Mesh.h"

class Renderer
{
public:
    static Mesh *circleMesh;

    static void initialize();

    static void render(std::vector<Object> &objects, Shader &shader, Camera &camera);
};