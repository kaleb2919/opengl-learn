#pragma once

#include <iostream>

#include <glad/glad.h>

class Image
{
    GLuint descriptor;
    GLuint texture_wrap = GL_CLAMP_TO_EDGE;
    GLenum data_format = GL_RGB;
    GLenum internal_format = GL_RGB;

public:
    Image(const char* file_name);
    GLuint getDescriptor();
};
