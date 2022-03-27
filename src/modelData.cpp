#include "modelData.h"

modelData::modelData()
	:
	pVersion{0},
	pModelName{0},
	mesh_data(),
	poRefSphere(),
	skelCount(0),
	skeletonTable(),
	animCount(0),
	vectorClip()
{
	strcpy_s(this->pVersion, modelData::VERSION_NUM_BYTES, modelData::PROTO_VERSION);
	// Make sure version is within the bytes for serialization
	assert(strlen(this->pVersion) < modelData::VERSION_NUM_BYTES);
}

modelData::~modelData()
{
}


void modelData::Serialize(modelData_proto& out) const
{
	AZUL_UNUSED_VAR(out);

	std::string sVersion((const char*)this->pVersion, modelData::VERSION_NUM_BYTES);
	out.set_pversion(sVersion);

	std::string sName((const char*)this->pModelName, modelData::FILE_NAME_SIZE);
	out.set_pmodelname(sName);

	meshData_proto* pMesh_proto;

	pMesh_proto = new meshData_proto();
	this->mesh_data.Serialize(*pMesh_proto);
	out.set_allocated_meshdata(pMesh_proto);

	BoundingSphere_proto* pSphere_proto;
	pSphere_proto = new BoundingSphere_proto();
	this->poRefSphere.Serialize(*pSphere_proto);
	out.set_allocated_porefsphere(pSphere_proto);

	out.set_skelcount(this->skelCount);

	for (unsigned int i = 0; i < this->skeletonTable.size(); ++i)
	{
		skelData_proto* pSkelData = out.add_skeldata();
		this->skeletonTable[i].Serialize(*pSkelData);
	}

	out.set_animcount(this->animCount);

	for (unsigned int i = 0; i < this->animCount; ++i)
	{
		animData_proto* pAnimData = out.add_animdata();
		this->vectorClip[i].Serialize(*pAnimData);
	}
	for (unsigned int i = 0; i < this->hierarchyTable.size(); i++)
	{
		out.add_hierarchytable(hierarchyTable[i]);
	}
}

void modelData::Deserialize(const modelData_proto& in)
{
	// CHECK the Version
	memcpy_s(this->pVersion, modelData::VERSION_NUM_BYTES, in.pversion().data(), modelData::VERSION_NUM_BYTES);
	assert(strcmp(this->pVersion, modelData::PROTO_VERSION) == 0);

	// Load the rest
	memcpy_s(this->pModelName, modelData::FILE_NAME_SIZE, in.pmodelname().data(), modelData::FILE_NAME_SIZE);

	this->mesh_data.Deserialize(in.meshdata());

	this->poRefSphere.Deserialize(in.porefsphere());

	this->skelCount = in.skelcount();
	this->skeletonTable.reserve(skelCount);
	for (unsigned int i = 0; i < skelCount; ++i)
	{
		skelData tmpSkeleton;
		this->skeletonTable.push_back(tmpSkeleton);
		skeletonTable[i].Deserialize(in.skeldata((int)i));
	}

	this->animCount = in.animcount();
	this->vectorClip.reserve(animCount);
	for (unsigned int i = 0; i < animCount; ++i)
	{
		animData tmpAnim;
		this->vectorClip.push_back(tmpAnim);
		vectorClip[i].Deserialize(in.animdata((int)i));
	}
	for ( int i = 0; i < in.hierarchytable_size(); i++)
	{
		this->hierarchyTable.push_back(in.hierarchytable(i));
	}
}

void modelData::Print(const char* const pName) const
{
	this->mesh_data.Print(pName);
}
