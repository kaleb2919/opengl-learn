#pragma once
#include "GameObject.h"

class Gun : public GameObject
{
public:
    Gun(const char* object_name, glm::vec3 position, glm::vec3 rotation);

    ~Gun() override;

};
