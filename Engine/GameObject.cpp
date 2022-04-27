#include "GameObject.h"

GameObject::GameObject(const char* object_name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
    name = object_name;
    transform = { position, rotation, scale };
}

GameObject::~GameObject()
{
}

void GameObject::setMesh(MeshComponent* mesh)
{
    mesh_component = mesh;
}

glm::vec3 GameObject::getPosition()
{
    return transform.position;
}

void GameObject::setPosition(float x, float y, float z)
{
    transform.position = glm::vec3(x,y,z);
}

void GameObject::draw(glm::vec3 camera_position, glm::mat4 projection, glm::mat4 view, glm::vec3 light_position, glm::vec3 light_color)
{
    mesh_component->draw(camera_position, projection, view, transform, light_position, light_color);
}
