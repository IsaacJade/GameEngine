#pragma once
#include "Rect.h"
#include "DLink.h"
class Texture;
using namespace Azul;
class Glyph :public DLink
{
public:
	Glyph();
	Glyph(int _key, Rect _prect, Texture* pText);
	void set(int _key, Rect _prect, Texture* pText);
	~Glyph();

	virtual bool Compare(DLink* pTarget) override;
	virtual void Dump() override;
	virtual void Wash() override;
	int key;
	Rect pSubRect;
	Texture* pTexture;
};
