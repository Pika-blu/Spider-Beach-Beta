#include "Hero.h"
#include <iostream>

//constructor
Hero::Hero()
{
}

//constructor
Hero::Hero(SDL_Renderer* renderer, const char* filename,
	int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	dst.x = 300;
	dst.y = 300;
	dst.w = w;
	dst.h = h;
}

//constructor
Hero::Hero(SDL_Renderer* renderer, const char* filename,
	int srcX, int srcY, int srcW, int srcH,
	int dstX, int dstY, int dstW, int dstH)
{
	pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = srcX;
	src.y = srcY;
	src.w = srcW;
	src.h = srcH;


	dst.x = dstX;
	dst.y = dstY;
	dst.w = dstW;
	dst.h = dstH;
}


//destructor
Hero::~Hero()
{
}


void Hero::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

void Hero::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Hero::moveBy(int x, int y)
{
	dst.x += x * speedX;
	dst.y += y * speedY;

	if (dst.x < 0 || dst.x > 600)
	{
		speedX = 0.0f;

		if (dst.x < 0) dst.x += x + 1.5f;

		else if (dst.x > 600) dst.x += x - 1.5f;

	}
	else if (dst.x >= 0 || dst.x <= 600) speedX = 5.0f;


	if (dst.y < 190 || dst.y > 400)
	{
		speedY = 0.0f;

		if (dst.y < 190) dst.y += y + 3.0f;

		else if (dst.y > 400) dst.y += y - 3.0f;

	}
	else if (dst.y >= 0 || dst.y <= 400) speedY = 5.0f;
}

void Hero::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}


bool Hero::checkCollision(SDL_Rect r)
{
	return
		r.x < dst.x + dst.w &&
		r.x + r.w > dst.x &&
		r.y < dst.y + dst.h &&
		r.h + r.y > dst.y;
}