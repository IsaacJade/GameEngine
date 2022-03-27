// COLOR RENDER - Fragment Shader

#version 430 core

// varying
    out vec4 color;

    in VS_OUT
    {
        vec4 color;
    } fs_in;

void main(void)
{
    color = fs_in.color;
}
