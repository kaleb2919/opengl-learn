#include "Material.h"

Material::Material(const char* vert, const char* frag)
{
   shader = new Shader();
    if (!shader->loadShaders(vert, frag))
    {
        std::cout << "Failed to load shaders" << std::endl;
        return;
    }
}

Material::~Material()
{
    delete base_texture;
    delete normal_map;
    delete roughness_map;
    delete shader;
}

void Material::setBaseTexture(Image* image)
{
    base_texture = image;
}

void Material::setNormalMap(Image* image)
{
    normal_map = image;
}

void Material::setRoughnessMap(Image* image)
{
    roughness_map = image;
}

Image* Material::getBaseTexture()
{
    return base_texture;
}

Image* Material::getNormalMap()
{
    return normal_map;
}

Image* Material::getRoughnessMap()
{
    return roughness_map;
}

Shader* Material::getShader()
{
    return shader;
}
