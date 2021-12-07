#pragma once
#include "Image.h"
#include "Shader.h"


class Material
{
    Image* base_texture = nullptr;
    Image* normal_map = nullptr;
    Image* roughness_map = nullptr;
    Shader* shader = nullptr;

public:
    Material(const char* vert, const char* frag);
    virtual ~Material();

    void setBaseTexture(Image* image);
    void setNormalMap(Image* image);
    void setRoughnessMap(Image* image);

    Image* getBaseTexture();
    Image* getNormalMap();
    Image* getRoughnessMap();

    Shader* getShader();
};
