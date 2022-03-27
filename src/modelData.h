#ifndef MODEL_DATA_H
#define MODEL_DATA_H

#include "modelData.pb.h"
#include "vboData.h"
#include "textureData.h"
#include "meshData.h"
#include "BoundingSphere.h"
#include "skelData.h"
#include "animData.h"
using namespace Azul;
class modelData
{
public:
	static const unsigned int FILE_NAME_SIZE = 64;

	static constexpr const char* PROTO_VERSION = "1.2.1"; // Major.Version.Rev
	static const unsigned int VERSION_NUM_BYTES = 8;


	modelData();
	modelData(const modelData&) = delete;
	modelData& operator = (const modelData&) = delete;
	virtual  ~modelData();

	// Serialization 
	void Serialize(modelData_proto& out) const;
	void Deserialize(const modelData_proto& in);

	void Print(const char* const pName) const;

public:
	char             pVersion[VERSION_NUM_BYTES];

	char             pModelName[FILE_NAME_SIZE];
	meshData mesh_data;
	Sphere poRefSphere;
	unsigned int skelCount;
	std::vector<skelData> skeletonTable;
	unsigned int animCount;
	std::vector<animData> vectorClip;
	std::vector<int> hierarchyTable;
};

#endif
