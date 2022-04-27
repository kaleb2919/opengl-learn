#pragma once
#include "GameObject.h"

class Light : public GameObject
{
    glm::vec3 color;

public:
    Light(const char* object_name, glm::vec3 position, glm::vec3 rotation, glm::vec3 color);

    glm::vec3 getColor();
};
