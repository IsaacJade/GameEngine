#pragma once
#include "Glyph.h"
#include "ManBase.h"
using namespace Azul;
class GlyphMan : public ManBase
{
    //----------------------------------------------------------------------
          // Static Methods
          //----------------------------------------------------------------------
public:
    static void Create(int reserveNum = 0, int reserveGrow = 1);
    static void ReadGlyph(const char* pFileName);
    static void Destroy();
    static Glyph* Add(int key, Rect p_rect, Texture* ptext);

    static Glyph* Find(int key);

    static void Remove(Glyph* pNode);
    static void Dump();

    //----------------------------------------------------------------------
    // Private methods
    //----------------------------------------------------------------------
private:
    static GlyphMan* privGetInstance();

    GlyphMan() = delete;
    GlyphMan(const GlyphMan&) = delete;
    GlyphMan& operator=(const GlyphMan&) = delete;
    virtual ~GlyphMan();

    GlyphMan(int reserveNum, int reserveGrow);

    //----------------------------------------------------------------------
    // Override Abstract methods
    //----------------------------------------------------------------------
protected:
    DLink* derivedCreateNode() override;

    //----------------------------------------------------------------------
    // Data: unique data for this manager 
    //----------------------------------------------------------------------
private:
    Glyph* poNodeCompare;
    static GlyphMan* posInstance;
};
