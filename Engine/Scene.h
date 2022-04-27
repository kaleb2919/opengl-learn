#pragma once
#include <vector>

#include "Light.h"

class GameObject;

class Scene
{
public:
    std::vector<GameObject*> game_objects;
    Light* light;

    void add(GameObject* box);
    void addLight(Light* game_object);
};
