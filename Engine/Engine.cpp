#include "Engine.h"

#include <thread>

#include "GameObject.h"

Engine::Engine(int screen_width, int screen_height, const char* title)
{
    window = new Window(screen_width, screen_height, title);
}

void Engine::render(Camera* camera, const Scene* scene)
{
    window->clear();
    glm::mat4 projection = camera->getProjection();
    glm::mat4 view = camera->getViewMatrix();

    for (auto game_object : scene->game_objects)
    {
        game_object->draw(camera->getPosition(), projection, view, scene->light->getPosition(), scene->light->getColor());
    }

    window->swap();
}

void Engine::tick()
{
}

bool Engine::isRunning()
{
    return window->isRunning();
}

void Engine::getMousePosition(double& x, double& y)
{
    window->getMousePosition(x, y);
}

void Engine::getMoiseOffset(double& x, double& y)
{
    window->getMoiseOffset(x, y);
}

int Engine::getKey(int key_code)
{
    return window->getKey(key_code);
}

void Engine::close()
{
    window->close();
}

float Engine::getDeltaTime()
{
    current_time = window->getTime();
    auto delta_time = current_time - last_time;
    last_time = current_time;
    return delta_time;
}


float Engine::getTime()
{
    return window->getTime();
}
