#include "BulletList.h"

BulletList::BulletList() {}
BulletList::BulletList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
BulletList::~BulletList() {}

void BulletList::addBullet(int x, int y)
{
	//adds it to the tail end of the list
	bulletArray.emplace_back(Bullet(renderer, x, y));
}

void BulletList::updateBullets()
{
	//for each bullet in the list
	for (auto bullet = bulletArray.begin(); bullet != bulletArray.end();) {
		//update the bullet (moves the bullet up)
		bullet->update();

		//if the bullet reached the top of the screen, erase it
		if (bullet->dst.y <= 0)
		{
			//erase returns us the next bullet in the list so we don't move our 
			//iterator to the next element in the list manually in this case
			bullet = bulletArray.erase(bullet);
		}
		else
		{
			//draw the bullet and move to next bullet in the list to check the next bullet
			bullet->draw(renderer);
			++bullet;
		}
	}
}
