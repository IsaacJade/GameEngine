#ifndef PROTO_BUFF_MESH_H
#define PROTO_BUFF_MESH_H

#include "Mesh.h"
#include "Texture.h"

class meshData;

class ProtoBuffMesh : public Mesh
{
public:
	ProtoBuffMesh(const char *const pMeshFileName, Texture::Name name);
	ProtoBuffMesh(const char *const pMeshFileName);
	ProtoBuffMesh(meshData& pMeshData);

	ProtoBuffMesh() = delete;
	ProtoBuffMesh(const ProtoBuffMesh &) = delete;
	ProtoBuffMesh &operator = (ProtoBuffMesh &) = delete;
	virtual ~ProtoBuffMesh();

private:
	void privCreateVAO(const char *const pMeshFileName, Texture *&pTexture);
	void privCreateVAO(meshData& pMeshData, Texture*& pTexture);

	// Data

};

#endif
