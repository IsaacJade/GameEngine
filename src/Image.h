#ifndef IMAGE_H
#define IMAGE_H

#include "Rect.h"
#include "Texture.h"
#include "DLink.h"

namespace Azul
{
	class Image : public DLink
	{
	public:

		enum Name
		{
			Alien_Blue,
			Alien_Green,
			Alien_Red,
			Stitch,
			Not_Initialized,
		};

	public:
		// public methods: -------------------------------------------------------------
		Image();
		Image(Image::Name imageName, Texture::Name textName, Rect rect);
		Image(Image::Name imageName, Texture *pTexture, Rect rect);
		~Image();
		void Set(Image::Name imageName, Texture::Name textName, Rect rect);
		void Set(Image::Name imageName, Texture *pTexture, Rect rect);
		//EnumName getName();

		virtual bool Compare(DLink *pTarget) override;
		virtual void Dump() override;
		virtual void Wash() override;

	public:
		// data: -----------------------------------------------------------------------
		Image::Name	    imageName;
		Texture         *pText;
		Rect			imageRect;
	};

}


#endif
