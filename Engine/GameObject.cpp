#include "GameObject.h"

GameObject::GameObject(const char* object_name, glm::vec3 position, glm::vec3 rotation):
    position(position), rotation(rotation)
{
    name = object_name;
}

GameObject::~GameObject()
{
}

void GameObject::setMesh(MeshComponent* mesh)
{
    mesh_component = mesh;
}

void GameObject::draw(glm::mat4 projection, glm::mat4 view)
{
    mesh_component->draw(projection, view, position);
}
