#pragma once
#include <SDL_image.h>


class Smoke
{
	SDL_Texture* pSpriteTex = nullptr;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_Renderer* renderer;

	//Animation related variables

	//Which frame we are displaying
	int displayFrame = 0;

	//How mnay frames there are
	int frameCount = 24;


	/*
	Total size of the image: 768x32
	Each frame size: 32x32
		Width: Total Width / Frame Count; 768/24 = 32 pixels
		Height: 32 pixels because there's only a single row
	*/
	int frameWidth = 32;
	int frameHeight = 32;






public:
	Smoke() { };
	Smoke(SDL_Renderer* renderer, int posX, int posY);


	~Smoke() {};

	bool animate();
	void cleanup();
};

