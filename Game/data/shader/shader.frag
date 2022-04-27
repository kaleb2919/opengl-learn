#version 460 core
out vec4 f_color;

in vec3 v_position;
in vec3 v_normal;
in vec2 v_UV;

uniform vec3 view_position;
struct Material {
    sampler2D base_texture;
    sampler2D normal_map;
    sampler2D roughness_map;

    float shininess;
};
uniform Material material;
struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform Light light;

void main()
{
    vec3 ambient = light.ambient * texture(material.base_texture, v_UV).rgb;

    vec3 normal = normalize(v_normal);
    vec3 light_direction = normalize(light.position - v_position);
    float diff = max(dot(normal, light_direction), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.base_texture, v_UV).rgb;

    vec3 view_direction = normalize(view_position - v_position);
    vec3 reflect_direction = reflect(-light_direction, normal);
    float spec = pow(max(dot(view_direction, reflect_direction), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.roughness_map, v_UV).rgb;

    vec3 result = ambient + diffuse + specular;
    f_color = vec4(result, 1.0);
}
