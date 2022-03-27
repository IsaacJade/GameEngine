// SKIN_TEXTURE - Vertex Shader

#version 430 core

// Uniforms
//	layout (location = 1000) uniform mat4 view_matrix;
//	layout (location = 2000) uniform mat4 proj_matrix;
//	layout (location = 3000) uniform mat4 invBind[8];
//	layout (location = 4000) uniform mat4 boneWorld[8];   // world is inside

	uniform mat4 view_matrix;
	uniform mat4 proj_matrix;
	uniform vec3 vLightPos;
	uniform vec4 vColor;

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
		vec4 vFragColor;
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
	
	// Get vNorm
		mat4 mvMatrix = view_matrix * skin_matrix;
		mat3 mNormalMatrix;
		mNormalMatrix[0] = normalize(mvMatrix[0].xyz);
		mNormalMatrix[1] = normalize(mvMatrix[1].xyz);
		mNormalMatrix[2] = normalize(mvMatrix[2].xyz);
		vec3 vNorm = normalize(mNormalMatrix * norms);

	// Get vLightDir
		vec4 ecPosition;
		vec3 ecPosition3;
		ecPosition = mvMatrix * vert;
		ecPosition3 = ecPosition.xyz /ecPosition.w;
		vec3 vLightDir = normalize(vLightPos - ecPosition3);

	// Get vFragColor
		float fDot = max(0.0, dot(vNorm, vLightDir)); 
		vs_out.vFragColor.rgb = vColor.rgb * fDot;
		vs_out.vFragColor.a = vColor.a;
}


