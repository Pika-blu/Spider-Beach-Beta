#pragma once
#include <SDL_image.h>
#include <iostream>

class Enemy
{
	SDL_Texture* pEnemyTex = nullptr;
	SDL_Rect src;
	SDL_Rect dst;

	int velY = 0;
	int velX = 0;
public:

	bool isActive = false;

	SDL_Rect getRect();
	// constructors -- these are used when initializing an object
	Enemy();
	Enemy(SDL_Renderer* renderer);

	// destructor -- used when the object is to be removed from memory
	~Enemy();

	void draw(SDL_Renderer* renderer);

	void cleanup();

	void move();
	void initialize();
	int getX() { return dst.x; }
	int getY() { return dst.y; }

};