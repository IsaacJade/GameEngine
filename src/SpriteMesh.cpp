#include "sb7.h"
#include "SpriteMesh.h"
#include "SpriteVBO.h"

namespace Azul
{


#define SPRITE_TRILIST_NUM_TRIANGLES (sizeof(SpriteTriList)/sizeof(Tri_index))

	Tri_index SpriteTriList[] =
	{
		{ 0, 1, 2 },
		{ 2, 3, 0 }
	};

#define SPRITE_DATA_NUM_VERTS (sizeof(SpriteData_xyz)/sizeof(Vert_xyz))

	Vert_xyz  SpriteData_xyz[] =
	{
		// Triangle 0
		{ -0.5f,  0.5f, 0.0f}, //0
		{  0.5f,  0.5f, 0.0f},// 1
		{  0.5f, -0.5f, 0.0f}, //2

		// Triangle 1
		{ -0.5f, -0.5f, 0.0f },  //3
	};

	Vert_uv  SpriteData_uv[] =
	{
		// Triangle 0
		{  0.0f, 0.0f}, //0
		{  1.0f, 0.0f}, // 1
		{  1.0f, 1.0f}, //2

		// Triangle 1
		{  0.0f, 1.0f },  //3
	};

	void SpriteMesh::privCreateVAO(const char *const modelFileName)
	{
		// future proofing it for a file
		AZUL_UNUSED_VAR(modelFileName);

		this->numVerts = SPRITE_DATA_NUM_VERTS;
		this->numTris = SPRITE_TRILIST_NUM_TRIANGLES;

		// Create a VAO
		glGenVertexArrays(1, &this->vao);
		assert(this->vao != 0);
		glBindVertexArray(this->vao);

		// Create a VBO
		glGenBuffers(1, &this->vbo_verts);
		assert(this->vbo_verts != 0);

	//	glGenBuffers(1, &this->vbo_norms);
	//	assert(this->vbo_norms != 0);

		glGenBuffers(1, &this->vbo_uv);
		assert(this->vbo_uv != 0);

	//	glGenBuffers(1, &this->vbo_color);
	//	assert(this->vbo_color != 0);

		glGenBuffers(1, &this->vbo_index);
		assert(this->vbo_index != 0);

		assert(this->numTris > 0);
		assert(this->numVerts > 0);

		// Load the verts data: ---------------------------------------------------------

		if(true)
		{
			//assert(mB.vbo_vert.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, this->vbo_verts);

			// load the data to the GPU
			//assert(mB.vbo_vert.poData);
			//assert(mB.vbo_vert.dataSize > 0);
			//assert(mB.vbo_vert.count * sizeof(Vert_xyz) == mB.vbo_vert.dataSize);
			glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_xyz) * this->numVerts), SpriteData_xyz, GL_STATIC_DRAW);

			// Vert data is location: 0  (used in vertex shader)
			//assert(0 == mB.vbo_vert.attribIndex);
			//assert(mB.vbo_vert.vboType == vboData::VBO_TYPE::VEC3);
			//assert(mB.vbo_vert.componentType == vboData::VBO_COMPONENT::FLOAT);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyz), 0);
			glEnableVertexAttribArray(0);
		}


		// Load the texts data: ---------------------------------------------------------

		if(true)
		{
			//assert(mB.vbo_uv.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uv);

			// load the data to the GPU
			//assert(mB.vbo_uv.poData);
			//assert(mB.vbo_uv.dataSize > 0);
			glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_uv) * this->numVerts), SpriteData_uv, GL_STATIC_DRAW);

			// Texture data is location: 2  (used in vertex shader)
			//assert(2 == mB.vbo_uv.attribIndex);
			//assert(mB.vbo_uv.vboType == vboData::VBO_TYPE::VEC2);
			//assert(mB.vbo_uv.componentType == vboData::VBO_COMPONENT::FLOAT);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vert_uv), 0);
			glEnableVertexAttribArray(1);
		}

		// Load the index data: ---------------------------------------------------------

		if(true)
		{
			// Bind our 2nd VBO as being the active buffer and storing index ) 
			//assert(mB.vbo_index.targetType == vboData::VBO_TARGET::ELEMENT_ARRAY_BUFFER);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_index);

			// Copy the index data to our buffer 
			//assert(mB.vbo_index.vboType == vboData::VBO_TYPE::SCALAR);
			//assert(mB.vbo_index.componentType == vboData::VBO_COMPONENT::UNSIGNED_INT);
			//assert(mB.vbo_index.dataSize > 0);
			//assert(mB.vbo_index.poData);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Tri_index) * this->numTris), SpriteTriList, GL_STATIC_DRAW);
		}
	}


	SpriteMesh::SpriteMesh(const char *const modelFileName)
		: Mesh()
	{
		this->privCreateVAO(modelFileName);
	}

	SpriteMesh::~SpriteMesh()
	{
		// remove anything dynamic here
	}
}
