#include "Model.h"

#include "File.h"
#include "StringThis.h"
#include "Mesh.h"
#include "MeshNodeMan.h"
#include "modelData.h"
#include "ProtoBuffMesh.h"

Model::Model()
	:p_mesh(nullptr),
p_sphere(nullptr),
BoneCount(0),
p_clip(nullptr),
pFileName()
{
}

Model::~Model()
{
	if (p_sphere)
	{
		delete p_sphere;
	}
	if (p_clip)
	{
		Clip* pTmp = p_clip;

		while (pTmp != nullptr)
		{
			Clip* pDeleteMe = pTmp;
			pTmp = pTmp->nextClip;
			delete pDeleteMe;
		}
	}
}

Model::Model(const char* const pMeshFileName)
	:p_mesh(nullptr),
	p_sphere(nullptr),
	BoneCount(0),
	p_clip(nullptr),
	pFileName(pMeshFileName)
{
	modelData mB;
	this->privLoad(mB);
	this->p_mesh = new ProtoBuffMesh(mB.mesh_data);
	MeshNodeMan::Add(mB.mesh_data.pMeshName, p_mesh);
	p_sphere = new Sphere();
	this->p_sphere->rad = mB.poRefSphere.rad;
	this->p_sphere->cntr = Vect(mB.poRefSphere.poData[0], mB.poRefSphere.poData[1], mB.poRefSphere.poData[2], mB.poRefSphere.poData[3]);

	if (mB.animCount > 0)
	{
		this->privSetClip(mB);
	}
	if (mB.skelCount > 0)
	{
		this->BoneCount = mB.skelCount;
	}
}

bool Model::Compare(DLink* pTarget)
{
	// This is used in ManBase.Find() 
	assert(pTarget != nullptr);

	Model* pDataB = (Model*)pTarget;

	bool status = false;

	if (this->name == pDataB->name)
	{
		status = true;
	}

	return status;
}

void Model::SetName(Model::Name _name)
{
	this->name = _name;
}

void Model::AddClip(const char* const pMeshFileName)
{
	this->pFileName = my_string(pMeshFileName);
	modelData mA;
	this->privLoad(mA);

	assert(p_clip);
	Clip* tmp = p_clip;
	while(tmp->nextClip)
	{
		tmp = tmp->nextClip;
	}
	tmp->nextClip = new Clip(mA.vectorClip, mA.skelCount);
}

Skeleton* Model::InitSkeleton()
{
	modelData mB;
	this->privLoad(mB);
	Skeleton* p_skeleton = new Skeleton(mB.skelCount, this->p_mesh);
	for (unsigned int i = 0; i < mB.skelCount; ++i)
	{
		p_skeleton->_Skeltable[i]->index = mB.skeletonTable[i].nodeIndex;
		p_skeleton->_Skeltable[i]->parentIndex = mB.skeletonTable[i].parentIndex;
		my_string tmp = my_string(mB.skeletonTable[i].nodeName);
		memcpy_s(p_skeleton->_Skeltable[i]->name, 64, tmp.c_str(), tmp.length() + 1);
	}
	int tablesize = mB.hierarchyTable.size();
	p_skeleton->width = tablesize / mB.skelCount;
	int* hier = new int[tablesize];
	p_skeleton->pBoneHierarchy = new SSBO();
	for (int i = 0; i < tablesize; i++)
	{
		hier[i] = mB.hierarchyTable[i];
	}
	p_skeleton->pBoneHierarchy->Set(tablesize, sizeof(int), hier);
	delete[] hier;
	return p_skeleton;
}

void Model::privLoad(modelData& mB)
{
	// -------------------------------
	// Read and recreate model data
	// -------------------------------

	File::Handle fh;
	File::Error err;

	my_string FileDest = my_string("../Data/") + pFileName;

	err = File::Open(fh, FileDest.c_str(), File::Mode::READ);
	assert(err == File::Error::SUCCESS);

	err = File::Seek(fh, File::Position::END, 0);
	assert(err == File::Error::SUCCESS);

	DWORD FileLength;
	err = File::Tell(fh, FileLength);
	assert(err == File::Error::SUCCESS);

	char* poNewBuff = new char[FileLength]();
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
	modelData_proto mB_proto;
	mB_proto.ParseFromString(strIn);
	mB.Deserialize(mB_proto);
	mB.Print(mB.pModelName);
	delete[] poNewBuff;
}

void Model::privSetClip(modelData& mB)
{
	this->p_clip = new Clip(mB.vectorClip, mB.skelCount);
}

char* Model::GetName()
{
	static char pTmp[128];
	//strcpy_s(pTmp, 128, StringMe(this->name));
	return pTmp;
}