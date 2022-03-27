#include "animData.h"

animData::~animData()
{
}

animData::animData()
	:
	frameIndex(0),
	time(0),
	vectorBone()
{
}

animData::animData(const animData& r)
{
	this->frameIndex = r.frameIndex;
	this->time = r.time;
	this->vectorBone = r.vectorBone;
}

animData& animData::operator = (const animData& r)
{
	if (this != &r)
	{
		this->frameIndex = r.frameIndex;
		this->time = r.time;
		this->vectorBone = r.vectorBone;
	}

	return *this;
}


void animData::Serialize(animData_proto& out) const
{
	out.set_frameindex(this->frameIndex);
	out.set_time(this->time);
	out.set_bonecount(this->vectorBone.size());
	for (unsigned int i = 0; i < this->vectorBone.size(); ++i)
	{
		out.add_bone(vectorBone[i].T.x());
		out.add_bone(vectorBone[i].T.y());
		out.add_bone(vectorBone[i].T.z());
		out.add_bone(vectorBone[i].T.w());
		out.add_bone(vectorBone[i].Q.qx());
		out.add_bone(vectorBone[i].Q.qy());
		out.add_bone(vectorBone[i].Q.qz());
		out.add_bone(vectorBone[i].Q.real());
		out.add_bone(vectorBone[i].S.x());
		out.add_bone(vectorBone[i].S.y());
		out.add_bone(vectorBone[i].S.z());
		out.add_bone(vectorBone[i].S.w());
	}

}

void animData::Deserialize(const animData_proto& in)
{
	this->frameIndex = in.frameindex();
	this->time = in.time();
	this->vectorBone.reserve(in.bonecount());
	unsigned int size = in.bonecount();
	for (unsigned int i = 0; i < size; ++i)
	{
		Bone tmp;
		unsigned int cur = i * 12;
		tmp.T.set(in.bone(cur), in.bone(cur + 1), in.bone(cur + 2), in.bone(cur + 3));
		tmp.Q.set(in.bone(cur + 4), in.bone(cur + 5), in.bone(cur + 6), in.bone(cur + 7));
		tmp.S.set(in.bone(cur + 8), in.bone(cur + 9), in.bone(cur + 10), in.bone(cur + 11));
		this->vectorBone.push_back(tmp);
	}

}

void animData::Print(const char* const pName) const
{
	AZUL_UNUSED_VAR(pName);
	Trace::out("\n");
}



