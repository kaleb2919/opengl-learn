#include "Camera.h"

Camera::Camera(float width, float height, glm::vec3 position, glm::vec3 world_up):
    position(position), world_up(world_up), width(width), height(height)
{
    update();
}

glm::mat4 Camera::getProjection()
{
    return glm::perspective(glm::radians(fov), width / height, 0.1f, 1000.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

void Camera::setPosition(glm::vec3 new_position)
{
    position = new_position;
    update();
}

glm::vec3 Camera::getPosition()
{
    return position;
}

void Camera::zoom(float offset)
{
    fov = glm::clamp(fov - offset, 45.0f, 120.0f);
}

void Camera::look(float yaw_offset, float pitch_offset)
{
    yaw_offset *= mouse_sensitivity;
    pitch_offset *= mouse_sensitivity;

    yaw += yaw_offset;
    pitch = glm::clamp(pitch + pitch_offset, pitch_min, pitch_max);

    update();
}

void Camera::update()
{
    glm::vec3 new_front;
    new_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    new_front.y = sin(glm::radians(pitch));
    new_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(new_front);

    right = glm::normalize(glm::cross(front, world_up));
    up    = glm::normalize(glm::cross(right, front));
}

void Camera::move(CameraMovement direction, float delta_time)
{
    float velocity = movement_speed * delta_time;

    if (direction == FORWARD)
        position += front * velocity;
    if (direction == BACKWARD)
        position -= front * velocity;
    if (direction == LEFT)
        position -= right * velocity;
    if (direction == RIGHT)
        position += right * velocity;
}
