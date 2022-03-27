#ifndef FONT_DATA_H
#define FONT_DATA_H

#include "fontData.pb.h"
#include "glyphData.h"
#include "textureData.h"

namespace Azul
{
	class fontData
	{
	public:
		static const unsigned int FILE_NAME_SIZE = 64;
			
	public:
		fontData();
		fontData(const fontData&) = delete;
		fontData& operator = (const fontData&) = delete;
		~fontData();

		// Serialization 
		void Serialize(fontData_proto& out) const;
		void Deserialize(const fontData_proto& in);

		void Print(const char* const pName) const;

	public:
		textureData text_font;
		std::vector<glyphData> glyphs;
	};
}
#endif
