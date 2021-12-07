#pragma once
#include <vector>

class GameObject;

class Scene
{
public:
    std::vector<GameObject*> game_objects;

    void add(GameObject* box);
};
