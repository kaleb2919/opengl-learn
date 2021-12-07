#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
    float width = 800;
    float height = 600;

    float fov = 80;

    glm::vec3 position;
    glm::vec3 world_up;

    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up;
    glm::vec3 right;

    float yaw = -90.0f;
    float pitch = 0.0f;
    float pitch_max = 89.0f;
    float pitch_min = -89.0f;

    float movement_speed = 5.0f;
    float mouse_sensitivity = 0.05f;

public:
    Camera(float width, float height, glm::vec3 position, glm::vec3 world_up);

    void move(CameraMovement direction, float delta_time);
    void zoom(float offset);
    void look(float yaw_offset, float pitch_offset);
    void update();

    glm::mat4 getProjection();
    glm::mat4 getViewMatrix();

    void setPosition(glm::vec3 new_position);
    glm::vec3 getPosition();
};
