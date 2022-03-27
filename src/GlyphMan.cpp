#include "GlyphMan.h"
#include "File.h"
#include "fontData.h"
#include "my_string.h"
#include "TextureMan.h"
using namespace Azul;

GlyphMan* GlyphMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
GlyphMan::GlyphMan(int reserveNum, int reserveGrow)
    : ManBase(reserveGrow)
{
    // Preload the reserve
    this->proFillReservedPool(reserveNum);

    // initialize derived data here
    this->poNodeCompare = new Glyph();
}

GlyphMan::~GlyphMan()
{
    delete this->poNodeCompare;
    this->poNodeCompare = nullptr;

    // iterate through the list and delete
    Iterator* pIt = this->baseGetActiveIterator();

    DLink* pNode = pIt->First();

    // Walk through the nodes
    while (!pIt->IsDone())
    {
        Glyph* pDeleteMe = (Glyph*)pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }

    pIt = this->baseGetReserveIterator();

    pNode = pIt->First();

    // Walk through the nodes
    while (!pIt->IsDone())
    {
        Glyph* pDeleteMe = (Glyph*)pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void GlyphMan::Create(int reserveNum, int reserveGrow)
{
    // make sure values are ressonable 
    assert(reserveNum >= 0);
    assert(reserveGrow > 0);

    // initialize the singleton here
    assert(posInstance == nullptr);

    // Do the initialization
    if (posInstance == nullptr)
    {
        posInstance = new GlyphMan(reserveNum, reserveGrow);
    }

}

void GlyphMan::ReadGlyph(const char* pFileName)
{
    GlyphMan* pMan = GlyphMan::privGetInstance();
    // -------------------------------
   // Read and recreate model data
   // -------------------------------

    File::Handle fh;
    File::Error err;

    assert(pFileName);
    my_string FileDest = my_string("../Data/") + my_string(pFileName);
    err = File::Open(fh, FileDest.c_str(), File::Mode::READ);
    assert(err == File::Error::SUCCESS);

    err = File::Seek(fh, File::Position::END, 0);
    assert(err == File::Error::SUCCESS);

    DWORD FileLength;
    err = File::Tell(fh, FileLength);
    assert(err == File::Error::SUCCESS);

    char* poNewBuff = new char[FileLength]();
    assert(poNewBuff);

    err = File::Seek(fh, File::Position::BEGIN, 0);
    assert(err == File::Error::SUCCESS);

    err = File::Read(fh, poNewBuff, FileLength);
    assert(err == File::Error::SUCCESS);

    err = File::Close(fh);
    assert(err == File::Error::SUCCESS);

    std::string strIn(poNewBuff, FileLength);
    fontData_proto mB_proto;

    mB_proto.ParseFromString(strIn);

    fontData mB;
    mB.Deserialize(mB_proto);

    delete[] poNewBuff;
    Texture* ptext = TextureMan::Add(mB.text_font);
    for (auto glyph : mB.glyphs)
    {
        pMan->Add((int)glyph.key, Rect(glyph.x, glyph.y, glyph.width,glyph.height), ptext);
    }
}

void GlyphMan::Destroy()
{
    GlyphMan* pMan = GlyphMan::privGetInstance();
    assert(pMan != nullptr);
    AZUL_UNUSED_VAR(pMan);

    delete GlyphMan::posInstance;
    GlyphMan::posInstance = nullptr;
}

Glyph* GlyphMan::Add(int key, Rect p_rect, Texture* ptext)
{
    GlyphMan* pMan = GlyphMan::privGetInstance();

    Glyph* pNode = (Glyph*)pMan->baseAddToFront();
    assert(pNode != nullptr);

    // Initialize the date
    pNode->set(key,p_rect,ptext);

    return pNode;
}


Glyph* GlyphMan::Find(int _key)
{
    GlyphMan* pMan = GlyphMan::privGetInstance();
    assert(pMan != nullptr);

    // Compare functions only compares two Nodes

    // So:  Use the Compare Node - as a reference
    //      use in the Compare() function
    pMan->poNodeCompare->key = _key;

    Glyph* pData = (Glyph*)pMan->baseFind(pMan->poNodeCompare);
    return pData;
}


void GlyphMan::Remove(Glyph* pNode)
{
    assert(pNode != nullptr);

    GlyphMan* pMan = GlyphMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseRemove(pNode);
}

void GlyphMan::Dump()
{
    GlyphMan* pMan = GlyphMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseDump();
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
GlyphMan* GlyphMan::privGetInstance()
{
    // Safety - this forces users to call Create() first before using class
    assert(posInstance != nullptr);

    return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink* GlyphMan::derivedCreateNode()
{
    DLink* pNodeBase = new Glyph();
    assert(pNodeBase != nullptr);

    return pNodeBase;
}