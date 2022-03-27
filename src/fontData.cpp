#include "fontData.h"
namespace Azul
{
	fontData::~fontData()
	{
		
	}


	fontData::fontData()
		:text_font(),
	glyphs()
	{
	}
	void fontData::Serialize(fontData_proto& out) const
	{
		textureData_proto* pTextproto = new textureData_proto();
		this->text_font.Serialize(*pTextproto);
		out.set_allocated_text_font(pTextproto);
		out.set_numglyph(this->glyphs.size());

		for (unsigned int i = 0; i < this->glyphs.size(); ++i)
		{
			glyphData_proto* pGlyph_proto = out.add_glyphs();
			this->glyphs[i].Serialize(*pGlyph_proto);
		}

	}

	void fontData::Deserialize(const fontData_proto& in)
	{
		this->text_font.Deserialize(in.text_font());
		if (in.numglyph() > 0)
		{
			this->glyphs.reserve(in.numglyph());
			unsigned int reserve = in.numglyph();
			for (unsigned int i = 0; i < reserve; ++i)
			{
				glyphData tmpGlyph;
				this->glyphs.push_back(tmpGlyph);
			}
			for (unsigned int i = 0; i < reserve; ++i)
			{
				this->glyphs[i].Deserialize(in.glyphs((int)i));
			}
		}
	}

	void fontData::Print(const char* const pName) const
	{
		text_font.Print(pName);
		printf("Number of Glyphs: %i \n", (int)glyphs.size());
		for (auto element : glyphs)
		{
			element.Print();
		}

	}
}



