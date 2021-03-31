#include "Background.h"
#include <iostream>


//constructor
Background::Background()
{
}

//constructor
Background::Background(SDL_Renderer* renderer, int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, "newBackground.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.h = h;
	src.y = 0;
	src.w = w;

	dst.x = 0;
	dst.y = 0;
	dst.w = w;
	dst.h = h;
}


//destructor
Background::~Background()
{
}


void Background::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

void Background::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}

void Background::moveX()
{

	/*std::cout << src.x << "\n";*/
	src.x++;
	if (src.x == 512)
	{
		src.x = 0;
	}

}