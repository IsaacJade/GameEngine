#include "ProtoBuffMesh.h"
#include "TextureMan.h"

#include "MeshFileHdr.h"
#include "File.h"
#include "meshData.h"
#include "SSBO.h"

using namespace Azul;

struct Vert_xyz
{
	float x;
	float y;
	float z;
};

struct Vert_nxnynz
{
	float nx;
	float ny;
	float nz;
};

struct Vert_uv
{
	float u;
	float v;
};

struct Vert_color
{
	float r;
	float g;
	float b;
	float a;
};

struct Vert_weight
{
	float wa;
	float wb;
	float wc;
	float wd;
};

struct Vert_joint
{
	float ja;
	float jb;
	float jc;
	float jd;
};

void ProtoBuffMesh::privCreateVAO(const char *const pMeshFileName, Texture *&pTexture)
{
	// future proofing it for a file
	AZUL_UNUSED_VAR(pMeshFileName);

	// -------------------------------
	// Read and recreate model data
	// -------------------------------

	File::Handle fh;
	File::Error err;

	assert(pMeshFileName);
	my_string FileDest = my_string("../Data/") + my_string(pMeshFileName);

	err = File::Open(fh, FileDest.c_str(), File::Mode::READ);
	assert(err == File::Error::SUCCESS);

	err = File::Seek(fh, File::Position::END, 0);
	assert(err == File::Error::SUCCESS);

	DWORD FileLength;
	err = File::Tell(fh, FileLength);
	assert(err == File::Error::SUCCESS);

	char *poNewBuff = new char[FileLength]();
	assert(poNewBuff);

	err = File::Seek(fh, File::Position::BEGIN, 0);
	assert(err == File::Error::SUCCESS);

	err = File::Read(fh, poNewBuff, FileLength);
	assert(err == File::Error::SUCCESS);

	err = File::Close(fh);
	assert(err == File::Error::SUCCESS);

	//Trace::out("--------------\n");
	//Trace::out("--------------\n");
	//Trace::out("--------------\n");

	std::string strIn(poNewBuff, FileLength);
	meshData_proto mB_proto;

	mB_proto.ParseFromString(strIn);

	meshData mB;
	mB.Deserialize(mB_proto);
	//mB.Print("mB");

	delete[] poNewBuff;


	// Create a VAO
	glGenVertexArrays(1, &this->vao);
	assert(this->vao != 0);
	glBindVertexArray(this->vao);

	// Create a VBO
	glGenBuffers(1, &this->vbo_verts);
	assert(this->vbo_verts != 0);

	glGenBuffers(1, &this->vbo_norms);
	assert(this->vbo_norms != 0);

	glGenBuffers(1, &this->vbo_uv);
	assert(this->vbo_uv != 0);

	glGenBuffers(1, &this->vbo_index);
	assert(this->vbo_index != 0);

	glGenBuffers(1, &this->vbo_color);
	assert(this->vbo_color != 0);

	// Skin data
	glGenBuffers(1, &this->vbo_weight);
	assert(this->vbo_weight != 0);

	glGenBuffers(1, &this->vbo_joint);
	assert(this->vbo_joint != 0);


	// General stuff
	assert(mB.mode == meshData::RENDER_MODE::MODE_TRIANGLES);

	this->numTris = (int)mB.triCount;
	this->numVerts = (int)mB.vertCount;

	assert(this->numTris > 0);
	assert(this->numVerts > 0);

	// Load the verts data: ---------------------------------------------------------

	if(mB.vbo_vert.enabled)
	{
	assert(mB.vbo_vert.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_verts);

	// load the data to the GPU
	assert(mB.vbo_vert.poData);
	assert(mB.vbo_vert.dataSize > 0);
	assert(mB.vbo_vert.count * sizeof(Vert_xyz) == mB.vbo_vert.dataSize);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_vert.dataSize), mB.vbo_vert.poData, GL_STATIC_DRAW);

	// Vert data is location: 0  (used in vertex shader)
	assert(0 == mB.vbo_vert.attribIndex);
	assert(mB.vbo_vert.vboType == vboData::VBO_TYPE::VEC3);
	assert(mB.vbo_vert.componentType == vboData::VBO_COMPONENT::FLOAT);
	glVertexAttribPointer(mB.vbo_vert.attribIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyz), 0);
	glEnableVertexAttribArray(mB.vbo_vert.attribIndex);
	}

	// Load the norms data: ---------------------------------------------------------

	if(mB.vbo_norm.enabled)
	{
	assert(mB.vbo_norm.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_norms);

	// load the data to the GPU
	assert(mB.vbo_norm.poData);
	assert(mB.vbo_norm.dataSize > 0);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_norm.dataSize), mB.vbo_norm.poData, GL_STATIC_DRAW);

	// normals data in location 1 (used in vertex shader)
	assert(1 == mB.vbo_norm.attribIndex);
	assert(mB.vbo_norm.vboType == vboData::VBO_TYPE::VEC3);
	assert(mB.vbo_norm.componentType == vboData::VBO_COMPONENT::FLOAT);
	glVertexAttribPointer(mB.vbo_norm.attribIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_nxnynz), 0);
	glEnableVertexAttribArray(mB.vbo_norm.attribIndex);
	}

	// Load the texts data: ---------------------------------------------------------
	
	if(mB.vbo_uv.enabled)
	{
	assert(mB.vbo_uv.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uv);

	// load the data to the GPU
	assert(mB.vbo_uv.poData);
	assert(mB.vbo_uv.dataSize > 0);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_uv.dataSize), mB.vbo_uv.poData, GL_STATIC_DRAW);

	// Texture data is location: 2  (used in vertex shader)
	assert(2 == mB.vbo_uv.attribIndex);
	assert(mB.vbo_uv.vboType == vboData::VBO_TYPE::VEC2);
	assert(mB.vbo_uv.componentType == vboData::VBO_COMPONENT::FLOAT);
	glVertexAttribPointer(mB.vbo_uv.attribIndex, 2, GL_FLOAT, GL_FALSE, sizeof(Vert_uv), 0);
	glEnableVertexAttribArray(mB.vbo_uv.attribIndex);
	}

	// Load the color data: ---------------------------------------------------------

	if(mB.vbo_color.enabled)
	{
		assert(mB.vbo_color.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_color);

		// load the data to the GPU
		assert(mB.vbo_color.poData);
		assert(mB.vbo_color.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_color.dataSize), mB.vbo_color.poData, GL_STATIC_DRAW);

		// Texture data is location: 4  (used in vertex shader)
		assert(4 == mB.vbo_color.attribIndex);
		assert(mB.vbo_color.vboType == vboData::VBO_TYPE::VEC4);
		assert(mB.vbo_color.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_color.attribIndex, 4, GL_FLOAT, GL_FALSE, sizeof(Vert_color), 0);
		glEnableVertexAttribArray(mB.vbo_color.attribIndex);
	}

	// Load the weight data: ---------------------------------------------------------

	if (mB.vbo_weights.enabled)
	{
		assert(mB.vbo_weights.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_weight);

		// load the data to the GPU
		assert(mB.vbo_weights.poData);
		assert(mB.vbo_weights.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_weights.dataSize), mB.vbo_weights.poData, GL_STATIC_DRAW);

		// Weight data is location: 5  (used in vertex shader)
		assert(5 == mB.vbo_weights.attribIndex);
		assert(mB.vbo_weights.vboType == vboData::VBO_TYPE::VEC4);
		assert(mB.vbo_weights.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_weights.attribIndex, 4, GL_FLOAT, GL_FALSE, sizeof(Vert_weight), 0);
		glEnableVertexAttribArray(mB.vbo_weights.attribIndex);
	}

// Load the Joint data: ---------------------------------------------------------

	if (mB.vbo_joints.enabled)
	{
		assert(mB.vbo_joints.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_joint);

		// load the data to the GPU
		assert(mB.vbo_joints.poData);
		assert(mB.vbo_joints.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_joints.dataSize), mB.vbo_joints.poData, GL_STATIC_DRAW);

		// Joint data is location: 6  (used in vertex shader)
		assert(6 == mB.vbo_joints.attribIndex);
		assert(mB.vbo_joints.vboType == vboData::VBO_TYPE::VEC4);
		assert(mB.vbo_joints.componentType == vboData::VBO_COMPONENT::UNSIGNED_INT);

		glVertexAttribIPointer(mB.vbo_joints.attribIndex, 4, GL_UNSIGNED_INT, sizeof(Vert_joint), 0);
		glEnableVertexAttribArray(mB.vbo_joints.attribIndex);
	}


	// Load the InverseBind Matrices data: ---------------------------------------------------------

	if (mB.vbo_invBind.enabled)
	{
		assert(mB.vbo_joints.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		//glBindBuffer(GL_ARRAY_BUFFER, this->vbo_invBind);

		// load the data to the GPU
		assert(mB.vbo_invBind.poData);
		assert(mB.vbo_invBind.dataSize > 0);
		//glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_invBind.dataSize), mB.vbo_invBind.poData, GL_STATIC_DRAW);

		// Inverse Bind data is location: 7  (used in vertex shader)
		assert(7 == mB.vbo_invBind.attribIndex);
		assert(mB.vbo_invBind.vboType == vboData::VBO_TYPE::MAT4);
		assert(mB.vbo_invBind.componentType == vboData::VBO_COMPONENT::FLOAT);
		//glVertexAttribPointer(mB.vbo_invBind.attribIndex, 4, GL_FLOAT, GL_FALSE, mB.vbo_invBind.count*sizeof(Matrix), 0);
		//glEnableVertexAttribArray(mB.vbo_invBind.attribIndex);
		// 
		// copy data into buffer
		this->numInverseBind = mB.vbo_invBind.count;
		assert(this->numInverseBind > 0);
		auto* tmp = new Matrix[this->numInverseBind]();
		assert(this->poInverseBind);
		memcpy_s(this->poInverseBind, this->numInverseBind * sizeof(Matrix), mB.vbo_invBind.poData, mB.vbo_invBind.dataSize);
		this->poInverseBind->Set(numInverseBind,sizeof(Matrix),tmp);
		delete[] tmp;
	}

	// Load the index data: ---------------------------------------------------------

	if(mB.vbo_index.enabled)
	{
		// Bind our 2nd VBO as being the active buffer and storing index ) 
		assert(mB.vbo_index.targetType == vboData::VBO_TARGET::ELEMENT_ARRAY_BUFFER);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_index);

		// Copy the index data to our buffer 
		assert(mB.vbo_index.vboType == vboData::VBO_TYPE::SCALAR);
		assert(mB.vbo_index.componentType == vboData::VBO_COMPONENT::UNSIGNED_INT);
		assert(mB.vbo_index.dataSize > 0);
		assert(mB.vbo_index.poData);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_index.dataSize), mB.vbo_index.poData, GL_STATIC_DRAW);
	}

	// ------------------------------------------------------
	// Load the texture - hopefully
	// ------------------------------------------------------


	if (mB.text_color.enabled)
	{
		pTexture = TextureMan::Add(mB.text_color);
		this->hash = mB.text_color.md5[0] ^ mB.text_color.md5[1] ^ mB.text_color.md5[2] ^ mB.text_color.md5[3];
		assert(pTexture);
	}
	else
	{
		pTexture = nullptr;
		this->hash = 0;
	}
}

void ProtoBuffMesh::privCreateVAO(meshData& mB, Texture*& pTexture)
{

	// Create a VAO
	glGenVertexArrays(1, &this->vao);
	assert(this->vao != 0);
	glBindVertexArray(this->vao);

	// Create a VBO
	glGenBuffers(1, &this->vbo_verts);
	assert(this->vbo_verts != 0);

	glGenBuffers(1, &this->vbo_norms);
	assert(this->vbo_norms != 0);

	glGenBuffers(1, &this->vbo_uv);
	assert(this->vbo_uv != 0);

	glGenBuffers(1, &this->vbo_index);
	assert(this->vbo_index != 0);

	glGenBuffers(1, &this->vbo_color);
	assert(this->vbo_color != 0);

	// Skin data
	glGenBuffers(1, &this->vbo_weight);
	assert(this->vbo_weight != 0);

	glGenBuffers(1, &this->vbo_joint);
	assert(this->vbo_joint != 0);


	// General stuff
	assert(mB.mode == meshData::RENDER_MODE::MODE_TRIANGLES);

	this->numTris = (int)mB.triCount;
	this->numVerts = (int)mB.vertCount;

	assert(this->numTris > 0);
	assert(this->numVerts > 0);

	// Load the verts data: ---------------------------------------------------------

	if (mB.vbo_vert.enabled)
	{
		assert(mB.vbo_vert.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_verts);

		// load the data to the GPU
		assert(mB.vbo_vert.poData);
		assert(mB.vbo_vert.dataSize > 0);
		assert(mB.vbo_vert.count * sizeof(Vert_xyz) == mB.vbo_vert.dataSize);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_vert.dataSize), mB.vbo_vert.poData, GL_STATIC_DRAW);

		// Vert data is location: 0  (used in vertex shader)
		assert(0 == mB.vbo_vert.attribIndex);
		assert(mB.vbo_vert.vboType == vboData::VBO_TYPE::VEC3);
		assert(mB.vbo_vert.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_vert.attribIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyz), 0);
		glEnableVertexAttribArray(mB.vbo_vert.attribIndex);
	}

	// Load the norms data: ---------------------------------------------------------

	if (mB.vbo_norm.enabled)
	{
		assert(mB.vbo_norm.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_norms);

		// load the data to the GPU
		assert(mB.vbo_norm.poData);
		assert(mB.vbo_norm.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_norm.dataSize), mB.vbo_norm.poData, GL_STATIC_DRAW);

		// normals data in location 1 (used in vertex shader)
		assert(1 == mB.vbo_norm.attribIndex);
		assert(mB.vbo_norm.vboType == vboData::VBO_TYPE::VEC3);
		assert(mB.vbo_norm.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_norm.attribIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_nxnynz), 0);
		glEnableVertexAttribArray(mB.vbo_norm.attribIndex);
	}

	// Load the texts data: ---------------------------------------------------------

	if (mB.vbo_uv.enabled)
	{
		assert(mB.vbo_uv.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uv);

		// load the data to the GPU
		assert(mB.vbo_uv.poData);
		assert(mB.vbo_uv.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_uv.dataSize), mB.vbo_uv.poData, GL_STATIC_DRAW);

		// Texture data is location: 2  (used in vertex shader)
		assert(2 == mB.vbo_uv.attribIndex);
		assert(mB.vbo_uv.vboType == vboData::VBO_TYPE::VEC2);
		assert(mB.vbo_uv.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_uv.attribIndex, 2, GL_FLOAT, GL_FALSE, sizeof(Vert_uv), 0);
		glEnableVertexAttribArray(mB.vbo_uv.attribIndex);
	}

	// Load the color data: ---------------------------------------------------------

	if (mB.vbo_color.enabled)
	{
		assert(mB.vbo_color.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_color);

		// load the data to the GPU
		assert(mB.vbo_color.poData);
		assert(mB.vbo_color.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_color.dataSize), mB.vbo_color.poData, GL_STATIC_DRAW);

		// Texture data is location: 4  (used in vertex shader)
		assert(4 == mB.vbo_color.attribIndex);
		assert(mB.vbo_color.vboType == vboData::VBO_TYPE::VEC4);
		assert(mB.vbo_color.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_color.attribIndex, 4, GL_FLOAT, GL_FALSE, sizeof(Vert_color), 0);
		glEnableVertexAttribArray(mB.vbo_color.attribIndex);
	}

	// Load the weight data: ---------------------------------------------------------

	if (mB.vbo_weights.enabled)
	{
		assert(mB.vbo_weights.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_weight);

		// load the data to the GPU
		assert(mB.vbo_weights.poData);
		assert(mB.vbo_weights.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_weights.dataSize), mB.vbo_weights.poData, GL_STATIC_DRAW);

		// Weight data is location: 5  (used in vertex shader)
		assert(5 == mB.vbo_weights.attribIndex);
		assert(mB.vbo_weights.vboType == vboData::VBO_TYPE::VEC4);
		assert(mB.vbo_weights.componentType == vboData::VBO_COMPONENT::FLOAT);
		glVertexAttribPointer(mB.vbo_weights.attribIndex, 4, GL_FLOAT, GL_FALSE, sizeof(Vert_weight), 0);
		glEnableVertexAttribArray(mB.vbo_weights.attribIndex);
	}

	// Load the Joint data: ---------------------------------------------------------

	if (mB.vbo_joints.enabled)
	{
		assert(mB.vbo_joints.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_joint);

		// load the data to the GPU
		assert(mB.vbo_joints.poData);
		assert(mB.vbo_joints.dataSize > 0);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_joints.dataSize), mB.vbo_joints.poData, GL_STATIC_DRAW);

		// Joint data is location: 6  (used in vertex shader)
		assert(6 == mB.vbo_joints.attribIndex);
		assert(mB.vbo_joints.vboType == vboData::VBO_TYPE::VEC4);
		assert(mB.vbo_joints.componentType == vboData::VBO_COMPONENT::UNSIGNED_INT);

		glVertexAttribIPointer(mB.vbo_joints.attribIndex, 4, GL_UNSIGNED_INT, sizeof(Vert_joint), 0);
		glEnableVertexAttribArray(mB.vbo_joints.attribIndex);
	}


	// Load the InverseBind Matrices data: ---------------------------------------------------------

	if (mB.vbo_invBind.enabled)
	{
		assert(mB.vbo_joints.targetType == vboData::VBO_TARGET::ARRAY_BUFFER);
		//glBindBuffer(GL_ARRAY_BUFFER, this->vbo_invBind);

		// load the data to the GPU
		assert(mB.vbo_invBind.poData);
		assert(mB.vbo_invBind.dataSize > 0);
		//glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_invBind.dataSize), mB.vbo_invBind.poData, GL_STATIC_DRAW);

		// Inverse Bind data is location: 7  (used in vertex shader)
		assert(7 == mB.vbo_invBind.attribIndex);
		assert(mB.vbo_invBind.vboType == vboData::VBO_TYPE::MAT4);
		assert(mB.vbo_invBind.componentType == vboData::VBO_COMPONENT::FLOAT);
		//glVertexAttribPointer(mB.vbo_invBind.attribIndex, 4, GL_FLOAT, GL_FALSE, mB.vbo_invBind.count*sizeof(Matrix), 0);
		//glEnableVertexAttribArray(mB.vbo_invBind.attribIndex);
		// 
		// copy data into buffer
		this->numInverseBind = mB.vbo_invBind.count;
		assert(this->numInverseBind > 0);
		auto* tmp = new Matrix[this->numInverseBind]();
		this->poInverseBind = new SSBO();
		assert(this->poInverseBind);
		memcpy_s(tmp, this->numInverseBind * sizeof(Matrix), mB.vbo_invBind.poData, mB.vbo_invBind.dataSize);
		this->poInverseBind->Set(numInverseBind, sizeof(Matrix), tmp);
		delete[] tmp;


	}

	// Load the index data: ---------------------------------------------------------

	if (mB.vbo_index.enabled)
	{
		// Bind our 2nd VBO as being the active buffer and storing index ) 
		assert(mB.vbo_index.targetType == vboData::VBO_TARGET::ELEMENT_ARRAY_BUFFER);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_index);

		// Copy the index data to our buffer 
		assert(mB.vbo_index.vboType == vboData::VBO_TYPE::SCALAR);
		assert(mB.vbo_index.componentType == vboData::VBO_COMPONENT::UNSIGNED_INT);
		assert(mB.vbo_index.dataSize > 0);
		assert(mB.vbo_index.poData);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(mB.vbo_index.dataSize), mB.vbo_index.poData, GL_STATIC_DRAW);
	}

	// ------------------------------------------------------
	// Load the texture - hopefully
	// ------------------------------------------------------


	if (mB.text_color.enabled)
	{
		pTexture = TextureMan::Add(mB.text_color);
		this->hash = mB.text_color.md5[0] ^ mB.text_color.md5[1] ^ mB.text_color.md5[2] ^ mB.text_color.md5[3];
		assert(pTexture);
	}
	else
	{
		pTexture = nullptr;
		this->hash = 0;
	}

}

ProtoBuffMesh::ProtoBuffMesh(const char *const pMeshFileName, Texture::Name name)
	: Mesh()
{
	assert(pMeshFileName);
	Texture *pTexture = nullptr;
	this->privCreateVAO(pMeshFileName, pTexture);
	TextureMan::Add(name, pTexture);
}

ProtoBuffMesh::ProtoBuffMesh(const char *const pMeshFileName)
	: Mesh()
{
	assert(pMeshFileName);
	Texture *pTexture = nullptr;
	this->privCreateVAO(pMeshFileName, pTexture);
	//assert(pTexture == nullptr);
}

ProtoBuffMesh::ProtoBuffMesh(meshData& pMeshData)
{
	Texture* pTexture = nullptr;
	this->privCreateVAO(pMeshData, pTexture);
	this->_name = pMeshData.pMeshName;
	//TextureMan::Add(pMeshData);
	//assert(pTexture == nullptr);
}

ProtoBuffMesh::~ProtoBuffMesh()
{
	// remove anything dynamic here
}

