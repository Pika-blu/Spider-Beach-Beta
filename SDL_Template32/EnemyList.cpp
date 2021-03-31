#include "EnemyList.h"

EnemyList::EnemyList()
{
}

EnemyList::EnemyList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

EnemyList::~EnemyList()
{
}

void EnemyList::spawnEnemy()
{
	//Go through all asteroids that are inside the vector. 
	for (auto enemy = enemyArray.begin(); enemy != enemyArray.end(); enemy++)
	{
		//if the current asteroid is not active, we will initialize it and stop processing the rest of the function
		if (!enemy->isActive)
		{
			enemy->initialize();
			return;
		}
	}

	//execution will get here if no inactive asteroids are found. here we will add a new asteroid to the vector
	enemyArray.emplace_back(Enemy(renderer));
	std::cout << "        " << enemyArray.size() << std::endl;
}

void EnemyList::update()
{
	//Go through all asteroids that are inside the vector. 
	for (auto enemy = enemyArray.begin(); enemy != enemyArray.end(); enemy++)
	{
		//if the current asteroid is active, we will move it
		if (enemy->isActive)
		{
			enemy->move();
		}
	}
}


void EnemyList::draw()
{
	std::cout << "        " << enemyArray.size() << std::endl;

	//Go through all asteroids that are inside the vector. 
	for (auto enemy = enemyArray.begin(); enemy != enemyArray.end(); enemy++)
	{
		//if the current asteroid is active, we will draw it
		if (enemy->isActive)
		{
			enemy->draw(renderer);
		}
	}
}