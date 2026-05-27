#pragma once

#include <vector>

class Mesh
{
private:
    unsigned int VAO;
    unsigned int VBO;

    int vertexCount;

public:
    Mesh(std::vector<float> &vertices);

    void draw();
};