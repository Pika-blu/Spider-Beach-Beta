#pragma once
#include "Bullet.h"
#include <vector>

class BulletList {
	SDL_Renderer* renderer;

public:

	BulletList();
	BulletList(SDL_Renderer* renderer);
	~BulletList();

	void addBullet(int x, int y);
	void updateBullets();

	std::vector<Bullet> bulletArray;

};