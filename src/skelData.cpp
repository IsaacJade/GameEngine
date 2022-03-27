#include "skelData.h"


skelData::~skelData()
{
}

skelData::skelData()
	:nodeIndex(0),
	nodeName{ 0 },
	parentIndex(0),
	parentName{ 0 }
{
}

skelData::skelData(const skelData& r)
{
	this->nodeIndex = r.nodeIndex;
	strcpy_s(this->nodeName, skelData::BONE_NAME_SIZE, r.nodeName);
	assert(strlen(this->nodeName) < skelData::BONE_NAME_SIZE);
	this->parentIndex = r.parentIndex;
	strcpy_s(this->parentName, skelData::BONE_NAME_SIZE, r.parentName);
	assert(strlen(this->parentName) < skelData::BONE_NAME_SIZE);
}

skelData& skelData::operator = (const skelData& r)
{
	if (this != &r)
	{
		this->nodeIndex = r.nodeIndex;
		strcpy_s(this->nodeName, skelData::BONE_NAME_SIZE, r.nodeName);
		assert(strlen(this->nodeName) < skelData::BONE_NAME_SIZE);
		this->parentIndex = r.parentIndex;
		strcpy_s(this->parentName, skelData::BONE_NAME_SIZE, r.parentName);
		assert(strlen(this->parentName) < skelData::BONE_NAME_SIZE);
	}

	return *this;
}


void skelData::Serialize(skelData_proto& out) const
{
	out.set_nodeindex(this->nodeIndex);
	std::string snodename((const char*)this->nodeName, skelData::BONE_NAME_SIZE);
	out.set_nodename(snodename);
	out.set_parentindex(this->parentIndex);
	std::string sparentname((const char*)this->parentName, skelData::BONE_NAME_SIZE);
	out.set_parentname(sparentname);
}

void skelData::Deserialize(const skelData_proto& in)
{
	this->nodeIndex = in.nodeindex();
	memcpy_s(this->nodeName, skelData::BONE_NAME_SIZE, in.nodename().data(), skelData::BONE_NAME_SIZE);
	this->parentIndex = in.parentindex();
	memcpy_s(this->parentName, skelData::BONE_NAME_SIZE, in.parentname().data(), skelData::BONE_NAME_SIZE);
}

void skelData::Print(const char* const pName) const
{
	AZUL_UNUSED_VAR(pName);

	Trace::out("    nodeIndex: %d\n", this->nodeIndex);
	Trace::out("  nodeName: %s\n", this->nodeName);
	Trace::out("        parentIndex: %d \n", this->parentIndex);
	Trace::out("     parentName: %s \n", this->parentName);

	Trace::out("\n");

}


