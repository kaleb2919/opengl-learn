#pragma once
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glad/glad.h>

#include "Component.h"
#include "Material.h"
#include "Mesh.h"

class MeshComponent : Component
{
    void loadModel(const char* file_name);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

public:
    std::vector<Mesh> meshes;
    Material* material;

    MeshComponent(const char* file_name, Material* material);

    void draw(glm::mat4 projection, glm::mat4 view, glm::vec3 position);
};
