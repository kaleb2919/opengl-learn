#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Material.h"
#include "Shader.h"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texture_coordinate;
    glm::vec3 tangent;
    glm::vec3 bi_tangent;
};

class Mesh
{
    GLuint VAO, VBO, EBO;

    void setupMesh();
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    void draw(Material* material, glm::mat4 projection, glm::mat4 view, glm::vec3 position);
};
