#include "Light.h"

Light::Light(const char* object_name, glm::vec3 position, glm::vec3 rotation, glm::vec3 color): GameObject(object_name, position, rotation, glm::vec3(1.0f, 1.0f, 1.0f)),
    color(color)
{ }

glm::vec3 Light::getColor()
{
    return color;
}
