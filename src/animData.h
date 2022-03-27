#ifndef ANIM_DATA_H
#define ANIM_DATA_H

#include "animData.pb.h"
#include "MathEngine.h"
#include "Anim.h"

using namespace  Azul;
class animData
{
public:
	animData();
	animData(const animData&);
	animData& operator = (const animData&);
	~animData();

	// Serialization 
	void Serialize(animData_proto& out) const;
	void Deserialize(const animData_proto& in);

	void Print(const char* const pName) const;

public:
	int          frameIndex;
	float			time;
	std::vector<Bone> vectorBone;

};


#endif
