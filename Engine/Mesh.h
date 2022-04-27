#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Material.h"
#include "Types.h"

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

    void draw(glm::vec3 camera_position, Material* material, glm::mat4 projection, glm::mat4 view, Transform transform, glm::vec3 light_position, glm::vec3 light_color);
};
