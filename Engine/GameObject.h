#pragma once
#include <string>

#include "MeshComponent.h"
#include "Types.h"
#include "Camera.h"

class GameObject
{
    std::string name;

    Transform transform = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };

    MeshComponent* mesh_component = nullptr;

public:
    GameObject(const char* object_name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    virtual ~GameObject();

    void setMesh(MeshComponent* mesh);
    glm::vec3 getPosition();
    void setPosition(float x, float y, float z);
    void draw(glm::vec3 camera_position, glm::mat4 projection, glm::mat4 view, glm::vec3 light_position, glm::vec3 light_color);
};
