#include "Gun.h"

Gun::Gun(const char* object_name, glm::vec3 position, glm::vec3 rotation)
    : GameObject(object_name, position, rotation)
{
    auto gun_material = new Material("shader.vert", "shader.frag");
    gun_material->setBaseTexture(new Image("./data/texture/gun_rgb.jpg"));
    gun_material->setNormalMap(new Image("./data/texture/gun_n.jpg"));
    gun_material->setRoughnessMap(new Image("./data/texture/gun_r.jpg"));

    setMesh(new MeshComponent("./data/model/gun.fbx", gun_material));
}

Gun::~Gun()
{
}
