//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "sb7.h"
#include "GameMan.h"
#include "MathEngine.h"
#include "VectApp.h"
#include "QuatApp.h"
#include "GameObject.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "GraphicsObject_ColorByPosition.h"
#include "GraphicsObject_Wireframe.h"
#include "GraphicsObject_FlatTexture.h"
#include "GraphicsObject_TextureLight.h"
#include "GraphicsObject_ConstColor.h"
#include "GraphicsObject_WireframeConstantColor.h"
#include "TextureMan.h"
#include "InputMan.h"
#include "InputTest.h"
#include "Camera.h"
#include "GameObjectMan.h"
#include "MeshNodeMan.h"
#include "ShaderMan.h"
#include "ModelNodeMan.h"
#include "ProtoBuffMesh.h"
#include "CameraMan.h"
#include "BoundingSphereGameObject.h"
#include "AnimTimer.h"
#include "Anim.h"
#include "TimerController.h"
#include "AnimController.h"
#include "Clip.h"
#include "ImageMan.h"
#include "GlyphMan.h"
#include "GraphicsObject_Sprite.h"
#include "SpriteMesh.h"
#include "GameObject2D.h"
#include "GameObjectBasic.h"
#include "GraphicsObject_Font.h"
#include "GameObjectFont.h"


using namespace Azul;

namespace Azul
{
	AnimController* pAnim1 = nullptr;
	AnimController* pAnim2 = nullptr;
	AnimController* pAnim3 = nullptr;
	AnimController* pAnim4 = nullptr;
	GameObjectFont* pF1 = nullptr;
	GameObjectFont* pF2 = nullptr;
	GameObjectFont* pF3 = nullptr;
	GameObjectFont* pF4 = nullptr;
	GameObjectFont* pF5 = nullptr;
	GameObjectFont* pF6 = nullptr;
	bool show2 = false;

	//-----------------------------------------------------------------------------
	//  Game::Game()
	//		Game Engine Constructor
	//-----------------------------------------------------------------------------
	Game::Game(const char* const pWindowName, const int Width, const int Height)
		: Engine(pWindowName, Width, Height)
	{
		assert(pWindowName);
		this->globalTimer.Tic();
		this->intervalTimer.Tic();
	}

	//-----------------------------------------------------------------------------
	//  Game::~Game()
	//		Game Engine destructor
	//-----------------------------------------------------------------------------
	Game::~Game()
	{
	}

	//-----------------------------------------------------------------------------
	// Game::Initialize()
	//		Allows the engine to perform any initialization it needs to before 
	//      starting to run.  This is where it can query for any required services 
	//      and load any non-graphic related content. 
	//-----------------------------------------------------------------------------
	void Game::Initialize()
	{
	}


	//-----------------------------------------------------------------------------
	// Game::LoadContent()
	//		Allows you to load all content needed for your engine,
	//	    such as objects, graphics, etc.
	//-----------------------------------------------------------------------------
	void Game::LoadContent()
	{
		// Start the managers
		InputMan::Create();
		TextureMan::Create();
		MeshNodeMan::Create();
		ModelNodeMan::Create();
		ShaderMan::Create();
		CameraMan::Create();
		GameObjectMan::Create();
		ImageMan::Create();
		GlyphMan::Create();


		// --------------------------
		// Camera setup
		// --------------------------


		//---------------------------------------------------------------------------------------------------------
		// Setup the current 3D perspective Camera
		//---------------------------------------------------------------------------------------------------------
		auto pCam0 = new Camera(Camera::Type::PERSPECTIVE_3D);
		pCam0->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
		pCam0->setPerspective(
			35.0f, static_cast<float>(pCam0->getScreenWidth()) / static_cast<float>(pCam0->getScreenHeight()), 1.0f,
			10000.0f);
		pCam0->setOrientAndPosition(Vect(1.0f, 0.0f, 0.0f), Vect(-1.0f, 0.0f, 0.0f), Vect(-1.0f, 12.0f, 0.0f));
		pCam0->updateCamera();
		CameraMan::Add(Camera::Name::CAMERA_0, pCam0);
		// w1(1) - Camera Type
		CameraMan::SetCurrent(Camera::Name::CAMERA_0, Camera::Type::PERSPECTIVE_3D);

		//---------------------------------------------------------------------------------------------------------
		// Setup the current 2D orthographic Camera
		//---------------------------------------------------------------------------------------------------------
		auto pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

		pCam2D->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
		pCam2D->setOrthographic(static_cast<float>(-pCam2D->getScreenWidth()) / 2.0f,
		                        static_cast<float>(pCam2D->getScreenWidth()) / 2.0f,
		                        static_cast<float>(-pCam2D->getScreenHeight()) / 2.0f,
		                        static_cast<float>(pCam2D->getScreenHeight()) / 2.0f,
		                        1.0f, 1000.0f);
		pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, -1.0f), Vect(0.0f, 0.0f, 2.0f));

		// Holder for the current 2D  cameras
		CameraMan::Add(Camera::Name::CAMERA_1, pCam2D);
		CameraMan::SetCurrent(Camera::Name::CAMERA_1, Camera::Type::ORTHOGRAPHIC_2D);

		// -----------------------------------
		// Load the Mesh from Data file
		// -----------------------------------

		Mesh* pCubeMesh = new ProtoBuffMesh("cubeMesh.m.proto.azul");
		MeshNodeMan::Add("CUBE", pCubeMesh);

		Mesh* pSphereMesh = new ProtoBuffMesh("SphereMesh.m.proto.azul");
		MeshNodeMan::Add("SPHERE", pSphereMesh);

		Mesh* pPyra = new ProtoBuffMesh("PyramidMesh.m.proto.azul");
		MeshNodeMan::Add("Pyramid", pPyra);

		Mesh* pdoge = new ProtoBuffMesh("doge.m.proto.azul");
		MeshNodeMan::Add("Doge", pdoge);

		Mesh* pCorset = new ProtoBuffMesh("Corset.m.proto.azul");
		MeshNodeMan::Add("Corset", pCorset);


		auto pChicken = new Model("walk_mesh.msa.proto.azul");
		ModelNodeMan::Add(Model::Name::CHICKEN, pChicken);
		pChicken->AddClip("shot_front+mesh.msa.proto.azul");

		auto pMousey = new Model("Walking.msa.proto.azul");
		pMousey->AddClip("Running.msa.proto.azul");
		pMousey->AddClip("Joyful Jump.msa.proto.azul");
		ModelNodeMan::Add(Model::Name::MOUSEY, pMousey);

		auto pMouseyCompressed = new Model("Walking_compressed.msa.proto.azul");
		ModelNodeMan::Add(Model::Name::MOUSEY, pMouseyCompressed);
		pMouseyCompressed->AddClip("Running_compressed.msa.proto.azul");
		pMouseyCompressed->AddClip("Joyful Jump_compressed.msa.proto.azul");


		// Load the Sprite Mesh
		auto pSpriteMesh = new SpriteMesh("SpriteModel.azul");
		assert(pSpriteMesh);
		MeshNodeMan::Add("SPRITE", pSpriteMesh);

		GlyphMan::ReadGlyph("Consolas36pt.f.proto.azul");

		// ----------------------------------
		// Create/Load Shader 
		// ----------------------------------

		ShaderObject* pShaderObject_sprite = ShaderMan::Add(ShaderObject::Name::SPRITE, "spriteRender",
		                                                    ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_sprite);

		ShaderObject* pShaderObject_constcolor = ShaderMan::Add(ShaderObject::Name::CONST_COLOR, "constColorRender",
		                                                        ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_constcolor);

		ShaderObject* pShaderObject_color = ShaderMan::Add(ShaderObject::Name::COLOR_POSITION, "colorRender",
		                                                   ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_color);

		ShaderObject* pShaderObject_texture = ShaderMan::Add(ShaderObject::Name::TEXTURE_SIMPLE, "textureRender",
		                                                     ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_texture);

		ShaderObject* pShaderObject_textureLight = ShaderMan::Add(ShaderObject::Name::TEXTURE_POINT_LIGHT,
		                                                          "texturePointLightDiff",
		                                                          ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_textureLight);

		ShaderObject* pShaderObject_constColor = ShaderMan::Add(ShaderObject::Name::CONST_COLOR, "constcolorRender",
		                                                        ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_constColor);

		ShaderObject* pShaderObject_colorSingle = ShaderMan::Add(ShaderObject::Name::COLOR_SINGLE, "colorSingleRender",
		                                                         ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_colorSingle);

		ShaderObject* pShaderObject_skinLight = ShaderMan::Add(ShaderObject::Name::SKIN_TEXTURE_LIGHT,
		                                                       "skinTextureLightRender", ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_skinLight);

		ShaderObject* pShaderObject_skin = ShaderMan::Add(ShaderObject::Name::SKIN_TEXTURE, "skinTextureRender",
		                                                  ShaderObject::Type::GRAPHICS);
		assert(pShaderObject_skin);

		// Compute shader

		ShaderObject* pShaderObject_mixer = ShaderMan::Add(ShaderObject::Name::COMPUTE_MIXER, "computeMixer",
		                                                   ShaderObject::Type::COMPUTE);
		assert(pShaderObject_mixer);

		ShaderObject* pShaderObject_world = ShaderMan::Add(ShaderObject::Name::COMPUTE_WORLD, "computeWorld",
		                                                   ShaderObject::Type::COMPUTE);
		assert(pShaderObject_world);

		// ------------------------------------------
		// Load Textures from Data File
		// ------------------------------------------
		TextureMan::Add("HotPink.t.proto.azul", Texture::Name::HOT_PINK);
		TextureMan::Add("Aliens.t.proto.azul", Texture::Name::INVADERS);
		TextureMan::Add("Duckweed.t.proto.azul", Texture::Name::DUCKWEED);
		TextureMan::Add("Rocks.t.proto.azul", Texture::Name::ROCKS);
		TextureMan::Add("Stone.t.proto.azul", Texture::Name::STONES);
		TextureMan::Add("RedBrick.t.proto.azul", Texture::Name::RED_BRICK);
		TextureMan::Add("ChickenbotDiffuse.t.proto.azul", Texture::Name::CHICKEN_BOT);
		TextureMan::Add("Ch14_1001_Diffuse.t.proto.azul", Texture::Name::MOUSEY);

		// -------------------------------------------
		// Images
		// -------------------------------------------

		auto pImageGreen = new Image(Image::Name::Alien_Green, Texture::Name::INVADERS,
		                             Rect(136.0f, 64.0f, 85.0f, 63.0f));
		auto pImageRed = new Image(Image::Name::Alien_Red, Texture::Name::INVADERS, Rect(554.0f, 63.0f, 98.0f, 64.0f));

		assert(pImageGreen);
		ImageMan::Add(pImageGreen);
		ImageMan::Add(pImageRed);

		// --------------------------------------------
		// Sprite
		// --------------------------------------------

		auto pGraphics_Sprite = new GraphicsObject_Sprite(pSpriteMesh, pShaderObject_sprite, pImageGreen,
		                                                  Rect(455, 155, 100, 100));
		auto pA1 = new GameObject2D(pGraphics_Sprite);
		GameObjectMan::Add(pA1, GameObjectMan::GetRoot());
		pA1->posX = 600.0f;
		pA1->posY = 200.0f;

		pA1->SetName("ALIEN");


		auto pGraphics_Sprite2 = new GraphicsObject_Sprite(pSpriteMesh, pShaderObject_sprite, pImageRed,
		                                                   Rect(455, 155, 100, 100));
		auto pA2 = new GameObject2D(pGraphics_Sprite2);
		GameObjectMan::Add(pA2, GameObjectMan::GetRoot());
		pA1->posX = 1000.0f;
		pA1->posY = 200.0f;

		pA1->SetName("ALIEN");


		// --------------------------------------------
		// Font
		// --------------------------------------------
		auto pGraphics_Font = new GraphicsObject_Font(pSpriteMesh, pShaderObject_sprite, GlyphMan::Find(32),
		                                              Rect(455, 105, 25, 30));
		pF1 = new GameObjectFont(pGraphics_Font, "Current Time ");
		GameObjectMan::Add(pF1, GameObjectMan::GetRoot());
		pF1->posX = 700.0f;
		pF1->posY = 1000.0f;

		auto pGraphics_Font1 = new GraphicsObject_Font(pSpriteMesh, pShaderObject_sprite, GlyphMan::Find(32),
		                                               Rect(455, 105, 25, 30));
		pF2 = new GameObjectFont(pGraphics_Font1, "Walk");
		GameObjectMan::Add(pF2, GameObjectMan::GetRoot());
		pF2->posX = 300.0f;
		pF2->posY = 400.0f;

		auto pGraphics_Font2 = new GraphicsObject_Font(pSpriteMesh, pShaderObject_sprite, GlyphMan::Find(32),
		                                               Rect(455, 105, 25, 30));
		pF3 = new GameObjectFont(pGraphics_Font2, "Walk_Compressed");
		GameObjectMan::Add(pF3, GameObjectMan::GetRoot());
		pF3->posX = 900.0f;
		pF3->posY = 400.0f;

		auto pGraphics_Font3 = new GraphicsObject_Font(pSpriteMesh, pShaderObject_sprite, GlyphMan::Find(32),
		                                               Rect(455, 105, 25, 30));
		pF4 = new GameObjectFont(pGraphics_Font3, "FrameCount:");
		GameObjectMan::Add(pF4, GameObjectMan::GetRoot());
		pF4->posX = 300.0f;
		pF4->posY = 300.0f;

		auto pGraphics_Font4 = new GraphicsObject_Font(pSpriteMesh, pShaderObject_sprite, GlyphMan::Find(32),
		                                               Rect(455, 105, 25, 30));
		pF5 = new GameObjectFont(pGraphics_Font4, "FrameCount:");
		GameObjectMan::Add(pF5, GameObjectMan::GetRoot());
		pF5->posX = 900.0f;
		pF5->posY = 300.0f;

		auto pGraphics_Font5 = new GraphicsObject_Font(pSpriteMesh, pShaderObject_sprite, GlyphMan::Find(32),
		                                               Rect(455, 105, 25, 30));
		pF6 = new GameObjectFont(pGraphics_Font5, "Compress Ratio:");
		GameObjectMan::Add(pF6, GameObjectMan::GetRoot());
		pF6->posX = 500.0f;
		pF6->posY = 350.0f;


		// ---------------------------------
		// Create model
		// ---------------------------------
		Vect color(1.50f, 1.50f, 1.50f, 1.0f);
		Vect pos(1, 1, 1);
		auto* pDogeLight = new GraphicsObject_TextureLight(MeshNodeMan::Find("Doge"),
		                                                   ShaderMan::Find(ShaderObject::Name::TEXTURE_POINT_LIGHT),
		                                                   Texture::Name::DEFAULT, color, pos);
		auto* pDoge = new GameObjectBasic(pDogeLight);
		pDoge->SetName("doge");
		pDoge->SetScale(1.0f, 1.0f, 1.0f);
		pDoge->SetTrans(-3.0f, -1.0f, -4.0f);
		auto rot = Quat(Quat::Rot1::Y, MATH_PI2);
		pDoge->SetQuat(rot);
		pDoge->delta_x = 0.003f;
		GameObjectMan::Add(pDoge, GameObjectMan::GetRoot());
		auto* pcor = new GraphicsObject_TextureLight(MeshNodeMan::Find("Corset"),
		                                             ShaderMan::Find(ShaderObject::Name::TEXTURE_POINT_LIGHT),
		                                             Texture::Name::DEFAULT, color, pos);
		auto* pcors = new GameObjectBasic(pcor);
		pcors->SetName("corset");
		pcors->SetScale(24.0f, 24.0f, 24.0f);
		pcors->SetTrans(-3.0f, -1.0f, 4.0f);
		rot = Quat(Quat::Rot1::Z, -MATH_PI2);
		pcors->SetQuat(rot);
		pcors->delta_x = 0.001f;
		GameObjectMan::Add(pcors, GameObjectMan::GetRoot());


		// ---------------------------------
		// Create Animation
		// ---------------------------------

		AnimTime delta = 0.3f * AnimTime(AnimTime::Duration::FILM_24_FRAME);
		rot = Quat(Matrix::Special::Identity);
		pAnim3 = new AnimController(delta, Vect(0, 0, -4), rot, Vect(25, 25, 25), pChicken, Texture::Name::CHICKEN_BOT,
		                            2);
		pAnim4 = new AnimController(delta, Vect(0, 0, 4), rot, Vect(25, 25, 25), pChicken, Texture::Name::CHICKEN_BOT,
		                            2);
		pAnim4->SwitchClip(1);
		rot = Quat(Quat::Rot1::Z, -MATH_PI2);
		rot = rot * Quat(Quat::Rot1::X, -MATH_PI2);
		pAnim1 = new AnimController(delta, Vect(-2, 0, -2), rot, Vect(2, 2, 2), pMousey, Texture::Name::MOUSEY, 3);
		pAnim2 = new AnimController(delta, Vect(-2, 0, 2), rot, Vect(2, 2, 2), pMouseyCompressed, Texture::Name::MOUSEY,
		                            3);
		pF2->updateMessage("Walking");
		pF3->updateMessage("Walking_Compressed");
	}

	//-----------------------------------------------------------------------------
	// Game::Update()
	//      Called once per frame, update data, tranformations, etc
	//      Use this function to control process order
	//      Input, AI, Physics, Animation, and Graphics
	//-----------------------------------------------------------------------------
	void Game::Update(float currentTime)
	{
		my_string framecount("FrameCount: ");
		my_string frameRatio("FrameRatio: ");
		my_string message("Time: ");
		AZUL_UNUSED_VAR(currentTime);
		Keyboard* key = InputMan::GetKeyboard();

		// ------------------------------------
		// Camera update
		// ------------------------------------

		Camera* pCam3D = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);
		pCam3D->updateCamera();

		Camera* pCam2D = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
		pCam2D->updateCamera();

		// ------------------------------------------------
		// Timer update
		// ------------------------------------------------

		this->intervalTimer.Toc();
		this->intervalTimer.Tic();
		if (key->GetKeyState(Keyboard::KEY_1))
		{
			pAnim1->BlendClip(0, 1.0f);
			pAnim2->BlendClip(0, 1.0f);
			pF2->updateMessage("Walking");
			pF3->updateMessage("Walking_Compressed");
		}
		if (key->GetKeyState(Keyboard::KEY_2))
		{
			pAnim1->BlendClip(1, 1.0f);
			pAnim2->BlendClip(1, 1.0f);
			pF2->updateMessage("Running");
			pF3->updateMessage("Running_Compressed");
		}
		if (key->GetKeyState(Keyboard::KEY_3))
		{
			pAnim1->BlendClip(2, 1.0f);
			pAnim2->BlendClip(2, 1.0f);
			pF2->updateMessage("Joyful Jump");
			pF3->updateMessage("Joyful Jump_Compressed");
		}
		if (key->GetKeyState(Keyboard::KEY_4))
		{
			pAnim3->BlendClip(1, 1.0f);
			pAnim4->BlendClip(0, 1.0f);
		}
		if (key->GetKeyState(Keyboard::KEY_5))
		{
			pAnim3->BlendClip(0, 1.0f);
			pAnim4->BlendClip(1, 1.0f);
		}

		my_string time(currentTime);
		my_string ptmp = message + time;
		pF1->updateMessage(ptmp.c_str());
		float a1 = static_cast<float>(pAnim1->GetFrameCount()), a2 = static_cast<float>(pAnim2->GetFrameCount());


		// ------------------------------------
		// Animate Me
		// ------------------------------------

		my_string f4 = framecount + my_string(a1);
		my_string f5 = framecount + my_string(a2);
		my_string f6 = frameRatio + my_string(a1 / a2);

		pF4->updateMessage(f4.c_str());
		pF5->updateMessage(f5.c_str());
		pF6->updateMessage(f6.c_str());

		pAnim1->Update();
		pAnim2->Update();
		pAnim3->Update();
		pAnim4->Update();

		// ------------------------------------
		// Update GameObjects
		// ------------------------------------
		GameObjectMan::Update(this->globalTimer.Toc());
	}


	//-----------------------------------------------------------------------------
	// Game::Draw()
	//		This function is called once per frame
	//	    Use this for draw graphics to the screen.
	//      Only do rendering here
	//-----------------------------------------------------------------------------
	void Game::Draw()
	{
		GameObjectMan::Draw();
	}


	//-----------------------------------------------------------------------------
	// Game::UnLoadContent()
	//       unload content (resources loaded above)
	//       unload all content that was loaded before the Engine Loop started
	//-----------------------------------------------------------------------------
	void Game::UnLoadContent()
	{
		GlyphMan::Destroy();
		ImageMan::Destroy();
		TextureMan::Destroy();
		InputMan::Destroy();
		GameObjectMan::Destroy();
		MeshNodeMan::Destroy();
		ModelNodeMan::Destroy();
		ShaderMan::Destroy();
		CameraMan::Destroy();


		delete pAnim1;
		delete pAnim2;
		delete pAnim3;
		delete pAnim4;
	}

	//------------------------------------------------------------------
	// Game::ClearBufferFunc()
	// Allows user to change the way the clear buffer function works
	//------------------------------------------------------------------
	void Game::ClearBufferFunc()
	{
		const GLfloat grey[] = {0.7f, 0.7f, 0.8f, 1.0f};
		const GLfloat one = 1.0f;

		glViewport(0, 0, info.windowWidth, info.windowHeight);
		glClearBufferfv(GL_COLOR, 0, grey);
		glClearBufferfv(GL_DEPTH, 0, &one);
	}
} // namespace 

// --- End of File ---
