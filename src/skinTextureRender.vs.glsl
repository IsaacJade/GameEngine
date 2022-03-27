// SKIN_TEXTURE - Vertex Shader

#version 430 core

// Uniforms
//	layout (location = 1000) uniform mat4 view_matrix;
//	layout (location = 2000) uniform mat4 proj_matrix;
//	layout (location = 3000) uniform mat4 invBind[8];
//	layout (location = 4000) uniform mat4 boneWorld[8];   // world is inside

	uniform mat4 view_matrix;
	uniform mat4 proj_matrix;
//	uniform mat4 invBind[46];
//	uniform mat4 boneWorld[46];   // world is inside

// Attributes
	layout (location = 0) in vec4 vert;    // x y z  (w=1)
	layout (location = 1) in vec3 norms;
	layout (location = 2) in vec2 uv;

	layout (location = 5) in vec4  weight;
	layout (location = 6) in ivec4 joint;

		layout (std430, binding = 0) buffer boneWorldarr
	{
		mat4 boneWorld[];
	};

	layout (std430, binding = 1) buffer invBindarr
	{
		mat4 invBind[];
	};

// Varying
	out VS_OUT
	{
		vec2 textCoordinate;
	} vs_out;



void main(void)
{
    vs_out.textCoordinate = uv;

	// Remember: We use ROW major, but OpenGL GLSL multiplies in reverse order!

	 mat4 skin_matrix = weight.x * boneWorld[joint.x] * invBind[joint.x]  +
					    weight.y * boneWorld[joint.y] * invBind[joint.y]  +
					    weight.z * boneWorld[joint.z] * invBind[joint.z]  +
					    weight.w * boneWorld[joint.w] * invBind[joint.w] ;
	
    gl_Position = proj_matrix * view_matrix * skin_matrix * vert;    
}

