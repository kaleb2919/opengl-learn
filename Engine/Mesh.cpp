#include "Mesh.h"

#include <glm/ext/matrix_transform.hpp>

#include "Shader.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices):
    vertices(vertices), indices(indices)
{
    setupMesh();
}

void Mesh::draw(Material* material, glm::mat4 projection, glm::mat4 view, glm::vec3 position)
{
    Shader* shader = material->getShader();

    shader->use();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    shader->setMat4("model", glm::scale(glm::translate(glm::mat4(1.0f), position), glm::vec3(1.0f)));

    if (material->getBaseTexture())
    {
        shader->setInt("base_texture", 0);
        glBindTextureUnit(0, material->getBaseTexture()->getDescriptor());
    }

    if (material->getNormalMap())
    {
        shader->setInt("normal_map", 1);
        glBindTextureUnit(1, material->getNormalMap()->getDescriptor());
    }

    if (material->getRoughnessMap())
    {
        shader->setInt("roughness_map", 2);
        glBindTextureUnit(2, material->getRoughnessMap()->getDescriptor());
    }

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture_coordinate));

    glBindVertexArray(0);
}
