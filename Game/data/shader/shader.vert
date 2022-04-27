#version 460 core
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_UV;

out vec3 v_position;
out vec3 v_normal;
out vec2 v_UV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    v_position = vec3(model * vec4(in_position, 1.0));
    v_normal = mat3(transpose(inverse(model))) * in_normal;
    v_UV = in_UV;

    gl_Position = projection * view * vec4(v_position, 1.0);
}
