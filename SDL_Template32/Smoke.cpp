#include "Smoke.h"


Smoke::Smoke(SDL_Renderer* renderer, int dstX, int dstY)
{
	this->renderer = renderer;


	pSpriteTex = IMG_LoadTexture(renderer, "smoke.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;
	src.w = frameWidth;
	src.h = frameHeight;


	dst.x = dstX;
	dst.y = dstY;
	dst.w = frameWidth;
	dst.h = frameHeight;

}

bool Smoke::animate()
{
	src.x = displayFrame * frameWidth;
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);

	displayFrame++;
	if (displayFrame == frameCount)
	{
		cleanup();
		return false;
	}

	return true;
}

void Smoke::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

