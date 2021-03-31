#include "Enemy.h"

SDL_Rect Enemy::getRect()
{
	return dst;
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pEnemyTex, &src, &dst);
}

void Enemy::cleanup()
{
}

void Enemy::move()
{
	dst.x -= velX;
	if (dst.x <= 0)
	{
		initialize();
	}

}

void Enemy::initialize()
{
	isActive = true;

	int randomSize = 30 + rand() % 30;
	velY = 1 + rand() % 6;
	velX = 2 + rand() % 6;

	dst.x = 640 + randomSize;
	dst.y = 180 + rand() % 300 - randomSize;
	dst.w = randomSize;
	dst.h = randomSize;
	
}

Enemy::Enemy(SDL_Renderer* renderer)
{
	pEnemyTex = IMG_LoadTexture(renderer, "spider1.png");

	SDL_QueryTexture(pEnemyTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	initialize();
}

