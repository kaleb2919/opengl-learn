#pragma once
#include "GameObject.h"

class Box : public GameObject
{
public:
    Box(const char* object_name, glm::vec3 position, glm::vec3 rotation);

    ~Box() override;
};
