#include "glyphData.h"
namespace Azul
{
	glyphData::~glyphData()
	{
		
	}

	void glyphData::set(float _key, float _x, float _y, float _width, float _height)
	{
		this->key = _key;
		this->x = _x;
		this->y = _y;
		this->width = _width;
		this->height = _height;
	}


	glyphData::glyphData()
		:key(0),
		x(0),
		y(0),
		width(0),
		height(0)
	{
	}

	glyphData::glyphData(float _key, float _x, float _y, float _width, float _height)
		:key(_key),
		x(_x),
		y(_y),
		width(_width),
		height(_height)
	{
	}

	glyphData::glyphData(const glyphData& r)
	{
		this->key = r.key;
		this->x = r.x;
		this->y = r.y;
		this->width = r.width;
		this->height = r.height;
	}

	glyphData& glyphData::operator = (const glyphData& r)
	{
		if (this != &r)
		{
			this->key = r.key;
			this->x = r.x;
			this->y = r.y;
			this->width = r.width;
			this->height = r.height;
		}
		return *this;
	}



	void glyphData::Serialize(glyphData_proto& out) const
	{
		out.set_key(this->key);
		out.set_x(this->x);
		out.set_y(this->y);
		out.set_width(this->width);
		out.set_height(this->height);
	}

	void glyphData::Deserialize(const glyphData_proto& in)
	{
		this->key = in.key();
		this->x = in.x();
		this->y = in.y();
		this->width = in.width();
		this->height = in.height();
	}

	void glyphData::Print() const
	{
		printf("Character: %f, x: %f, y: %f, width: %f, height: %f  \n", key, x, y, width, height);
	}
}



