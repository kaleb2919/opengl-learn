#include "Box.h"

Box::Box(const char* object_name, glm::vec3 position, glm::vec3 rotation)
    : GameObject(object_name, position, rotation)
{
    auto box_material = new Material("shader.vert", "shader.frag");
    box_material->setBaseTexture(new Image("./data/texture/box_rgb.png"));
    box_material->setNormalMap(new Image("./data/texture/box_n.png"));
    box_material->setRoughnessMap(new Image("./data/texture/box_r.png"));

    setMesh(new MeshComponent("./data/model/box.fbx", box_material));
}

Box::~Box()
{
}
