#ifndef SKEL_DATA_H
#define SKEL_DATA_H

#include "skelData.pb.h"
#include "MathEngine.h"
using namespace  Azul;

class skelData
{
public:
	static const unsigned int BONE_NAME_SIZE = 64;
	skelData();
	skelData(const skelData&);
	skelData& operator = (const skelData&);
	~skelData();

	// Serialization 
	void Serialize(skelData_proto& out) const;
	void Deserialize(const skelData_proto& in);

	void Print(const char* const pName) const;

public:
	int          nodeIndex;
	char        nodeName[BONE_NAME_SIZE];
	int        parentIndex;
	char       parentName[BONE_NAME_SIZE];

};


#endif

