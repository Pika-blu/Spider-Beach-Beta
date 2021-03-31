#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(SDL_Renderer* renderer, int x, int y)
{
	pSpriteTex = IMG_LoadTexture(renderer, "projectile.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;


	dst.x = x;
	dst.y = y + offSetBullet;
	dst.w = 15;
	dst.h = 15;
}

Projectile::~Projectile()
{
}

void Projectile::update()
{
	dst.x -= velX;
}

void Projectile::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}

void Projectile::cleanup()
{
}

bool Projectile::checkCollision(SDL_Rect r)
{
	return
		r.x < dst.x + dst.w &&
		r.x + r.w > dst.x &&
		r.y < dst.y + dst.h &&
		r.h + r.y > dst.y;
}


