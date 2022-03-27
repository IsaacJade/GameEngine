#ifndef MESH_NULL_H
#define MESH_NULL_H

#include "Mesh.h"

class MeshNull : public Mesh
{
public:
	MeshNull(const char* const MeshFileName);
	MeshNull();
	virtual ~MeshNull();

	// tells the compiler do not create or allow it to be used, c++11
	MeshNull(const MeshNull&) = delete;
	MeshNull& operator=(const MeshNull& other) = delete;

private:
	void privCreateVAO(const char* const MeshFileName);


};

#endif
