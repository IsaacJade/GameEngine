// TEXTURE RENDER - Fragment Shader

#version 400 core

// Uniform
    uniform sampler2D tex_object;

// Varying
    in VS_OUT
    {
        vec2 textCoordinate;
    } fs_in;

    out vec4 color;

void main(void)
{
    color = texture(tex_object, fs_in.textCoordinate );
}
