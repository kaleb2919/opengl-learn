#include "Scene.h"

void Scene::add(GameObject* box)
{
    game_objects.push_back(box);
}

void Scene::addLight(Light* game_object)
{
    if (game_object)
    {
        light = game_object;
    }
}
