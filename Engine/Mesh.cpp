#include "Mesh.h"

#include <glm/ext/matrix_transform.hpp>

#include "Shader.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices):
    vertices(vertices), indices(indices)
{
    setupMesh();
}

void Mesh::draw(glm::vec3 camera_position, Material* material, glm::mat4 projection, glm::mat4 view, Transform transform, glm::vec3 light_position, glm::vec3 light_color)
{
    Shader* shader = material->getShader();

    shader->use();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    shader->setMat4("model", glm::scale(glm::translate(glm::mat4(1.0f), transform.position), transform.scale));
    shader->setVec3("view_position", camera_position);
    shader->setVec3("light.position", light_position);
    shader->setVec3("light.ambient", 0.05, 0.05, 0.05);
    shader->setVec3("light.diffuse", light_color);
    shader->setVec3("light.specular", 1.0f, 1.0f, 1.0f);
    shader->setFloat("material.shininess", 64.0f);

    if (material->getBaseTexture())
    {
        shader->setInt("material.base_texture", 0);
        glBindTextureUnit(0, material->getBaseTexture()->getDescriptor());
    }

    if (material->getNormalMap())
    {
        shader->setInt("material.normal_map", 1);
        glBindTextureUnit(1, material->getNormalMap()->getDescriptor());
    }

    if (material->getRoughnessMap())
    {
        shader->setInt("material.roughness_map", 2);
        glBindTextureUnit(2, material->getRoughnessMap()->getDescriptor());
    }

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::setupMesh()
{
    glCreateBuffers(1, &VBO);
    glNamedBufferStorage(VBO, vertices.size() * sizeof(Vertex), &vertices[0], GL_DYNAMIC_STORAGE_BIT);

    glCreateBuffers(1, &EBO);
    glNamedBufferStorage(EBO, indices.size() * sizeof(unsigned int), &indices[0], GL_DYNAMIC_STORAGE_BIT);

    glCreateVertexArrays(1, &VAO);
    glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(Vertex));
    glVertexArrayElementBuffer(VAO, EBO);

    glEnableVertexArrayAttrib(VAO, 0);
    glEnableVertexArrayAttrib(VAO, 1);
    glEnableVertexArrayAttrib(VAO, 2);

    glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
    glVertexArrayAttribFormat(VAO, 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, normal));
    glVertexArrayAttribFormat(VAO, 2, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, texture_coordinate));

    glVertexArrayAttribBinding(VAO, 0, 0);
    glVertexArrayAttribBinding(VAO, 1, 0);
    glVertexArrayAttribBinding(VAO, 2, 0);
}
