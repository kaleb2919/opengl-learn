#version 460 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D base_texture;
uniform sampler2D normal_map;
uniform sampler2D roughness_map;

void main()
{
    FragColor = texture(base_texture, TexCoord);
}
