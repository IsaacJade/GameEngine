#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#include "ManBase.h"
#include "Image.h"

namespace Azul
{

    class ImageMan : public ManBase
    {
        //----------------------------------------------------------------------
        // Static Methods
        //----------------------------------------------------------------------
    public:
        static void Create(int reserveNum = 0, int reserveGrow = 1);
        static void Destroy();
        static Image *Add(Image *pImage);

        static Image *Find(Image::Name name);

        static void Remove(Image *pNode);
        static void Dump();

        //----------------------------------------------------------------------
        // Private methods
        //----------------------------------------------------------------------
    private:
        static ImageMan *privGetInstance();

        ImageMan() = delete;
        ImageMan(const ImageMan &) = delete;
        ImageMan &operator=(const ImageMan &) = delete;
        virtual ~ImageMan();

        ImageMan(int reserveNum, int reserveGrow);

        //----------------------------------------------------------------------
        // Override Abstract methods
        //----------------------------------------------------------------------
    protected:
        DLink *derivedCreateNode() override;

        //----------------------------------------------------------------------
        // Data: unique data for this manager 
        //----------------------------------------------------------------------
    private:
        Image *poNodeCompare;
        static ImageMan *posInstance;

    };
}

#endif
