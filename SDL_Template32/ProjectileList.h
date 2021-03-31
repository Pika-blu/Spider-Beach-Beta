#pragma once
#include "Projectile.h"
#include "EnemyList.h"
#include <vector>

class ProjectileList
{

		SDL_Renderer* renderer;

	public:

		ProjectileList();
		ProjectileList(SDL_Renderer* renderer);
		~ProjectileList();

		void addProjectile(int x, int y);
		void updateProjectile();

		std::vector<Projectile> projectileArray;

	
};

