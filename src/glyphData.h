#ifndef GLYPH_DATA_H
#define GLYPH_DATA_H

#include "glyphData.pb.h"

namespace Azul
{
	class glyphData
	{
	public:
		static const unsigned int FILE_NAME_SIZE = 64;

	public:
		glyphData();
		glyphData(float _key,
			float _x,
			float _y,
			float _width,
			float _height);
		glyphData(const glyphData&);
		glyphData& operator = (const glyphData&);
		~glyphData();
		void set(float _key,
			float _x,
			float _y,
			float _width,
			float _height);
		// Serialization 
		void Serialize(glyphData_proto& out) const;
		void Deserialize(const glyphData_proto& in);

		void Print() const;

	public:
		float key;
		float x;
		float y;
		float width;
		float height;
	};
}
#endif
