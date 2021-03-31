#include "ProjectileList.h"

ProjectileList::ProjectileList() {}
ProjectileList::ProjectileList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
ProjectileList::~ProjectileList() {}

void ProjectileList::addProjectile(int x, int y)
{

		//adds it to the tail end of the list
		projectileArray.emplace_back(Projectile(renderer, x, y));
	
}

void ProjectileList::updateProjectile()
{
	std::cout << "        Proj"  << projectileArray.size() << std::endl;
	//for each bullet in the list
	for (auto projectile = projectileArray.begin(); projectile != projectileArray.end();) {
		//update the bullet (moves the bullet up)
		projectile->update();

		//if the bullet reached the top of the screen, erase it
		if (projectile->dst.x <= 0)
		{
			//erase returns us the next bullet in the list so we don't move our 
			//iterator to the next element in the list manually in this case
			projectile = projectileArray.erase(projectile);
		}
		else
		{
			//draw the bullet and move to next bullet in the list to check the next bullet
			projectile->draw(renderer);
			++projectile;
		}
	}
	
}
