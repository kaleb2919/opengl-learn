#pragma once
#include <string>

#include "MeshComponent.h"

class GameObject
{
    std::string name;

    glm::vec3 position = {0, 0, 0};
    glm::vec3 rotation = {0, 0, 0};

    MeshComponent* mesh_component = nullptr;

public:
    GameObject(const char* object_name, glm::vec3 position, glm::vec3 rotation);
    virtual ~GameObject();

    void setMesh(MeshComponent* mesh);
    void draw(glm::mat4 projection, glm::mat4 view);
};
