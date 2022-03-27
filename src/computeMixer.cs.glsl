#version 430 core

// ------------------------------------------
//    Compute Mixer
// ------------------------------------------

// localize breakdown
layout(local_size_x = 8) in;


struct Bone
{
	vec4 t;
	vec4 q;
	vec4 s;
};


layout (std430, binding = 0) buffer KeyFrameA
{
	Bone KeyA_array[];
};

layout (std430, binding = 1) buffer KeyFrameB
{
	Bone KeyB_array[];
};

layout (std430, binding = 2) buffer Result
{
	Bone Result_array[];
};


// Uniforms
// ...

uniform float ts;
uniform int boneCount;

// Function
vec4 slerp( vec4 src, vec4 tar, float t);

void main()
{
	uint boneIndex = gl_GlobalInvocationID.x;

	Result_array[boneIndex] = KeyA_array[boneIndex];

	if( gl_GlobalInvocationID.x < boneCount )
	{

		vec4 trans = mix( KeyA_array[boneIndex].t, KeyB_array[boneIndex].t, ts );
		vec4 quat = slerp( KeyA_array[boneIndex].q, KeyB_array[boneIndex].q, ts );
		vec4 scale = mix( KeyA_array[boneIndex].s, KeyB_array[boneIndex].s, ts );

		Result_array[boneIndex].t = trans;
		Result_array[boneIndex].q = quat;
		Result_array[boneIndex].s = scale;
	}
	
}


vec4 slerp( vec4 src, vec4 tar, float t)
{
	vec4 result;

	vec4 target;
	float QUAT_EPSILON = 0.001f;

	// Not sure if dot is 3D or 4D... need 4D
	//float cosom = dot(src, tar);
	
	float cosom = src.x*tar.x + src.y*tar.y + src.z*tar.z + src.w*tar.w;

	if(cosom >= 1.0f)
	{
		// do nothing
		result = src;
	}
	else
	{
		// adjust signs if necessary
		if (cosom < 0.0f)
		{
			cosom = -cosom;
			target = -tar;
		}
		else
		{
			target = tar;
		}

		// If the the source and target are close, we can do a lerp.
		float tarFactor = t;
		float srcFactor = 1.0f - t;

		// calculate coefficients
		if (cosom < (1.0f - QUAT_EPSILON))
		{
			// Quats are not close enough for a lerp.
			// Calculating coefficients for a slerp.
			const float omega = acos(cosom);
			const float sinom = 1.0f / sin(omega);

			srcFactor = sin(srcFactor * omega) * sinom;
			tarFactor = sin(tarFactor * omega) * sinom;
		}


		result.x = src.x * srcFactor + target.x * tarFactor;
		result.y = src.y * srcFactor + target.y * tarFactor;
		result.z = src.z * srcFactor + target.z * tarFactor;
		result.w = src.w * srcFactor + target.w * tarFactor;
	}


	return result;

}

