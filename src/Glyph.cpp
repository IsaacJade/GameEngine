#include "Glyph.h"

Glyph::Glyph()
	:key(0),
	pSubRect(),
pTexture(0)
{
}

Glyph::Glyph(int _key, Rect _prect, Texture* pText)
	:key(_key),
	pSubRect(_prect),
	pTexture(pText)
{
}

void Glyph::set(int _key, Rect _prect, Texture* pText)
{
	this->key = _key;
	this->pSubRect = _prect;
	this->pTexture = pText;
}

Glyph::~Glyph()
{
}

bool Glyph::Compare(DLink* pTarget)
{
	// This is used in ManBase.Find() 
	assert(pTarget != nullptr);

	Glyph* pDataB = (Glyph*)pTarget;

	bool status = false;

	if (this->key == pDataB->key)
	{
		status = true;
	}

	return status;
}
void Glyph::Dump()
{
	Trace::out("      Glyph(%p)\n", this);

	// Data:
	//Trace::out("      Name: %s \n", StringMe(this->name));
	//Trace::out("         x: %d \n", this->x);

	DLink::Dump();
}

void Glyph::Wash()
{
	this->key = 0;
	this->pSubRect.clear();
	this->pTexture = nullptr;
}
