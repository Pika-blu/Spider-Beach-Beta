#pragma once
#include "Enemy.h"
#include <vector>


class EnemyList
{
	SDL_Renderer* renderer;


public:
	std::vector<Enemy> enemyArray;
	int asteroidLimit = 5;
	EnemyList();
	EnemyList(SDL_Renderer* renderer);
	~EnemyList();

	void spawnEnemy();
	void update();
	void draw();


};

