#include "../../include/rendering/Mesh.h"

#include <GL/glew.h>

Mesh::Mesh(
    std::vector<float> &vertices)
{
    vertexCount = vertices.size() / 2;

    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void Mesh::draw()
{
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
}