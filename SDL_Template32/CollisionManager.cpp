#include "CollisionManager.h"

void CollisionManager::checkBulletToEnemyCollisions()
{

	//for each bullet in the bullet list
	for (auto bullet = m_pBulletList->bulletArray.begin(); bullet != m_pBulletList->bulletArray.end(); )
	{
		bool moveToNext = true;
		//process each asteroid in the asteroid list
		for (auto enemy = m_pEnemyList->enemyArray.begin(); enemy != m_pEnemyList->enemyArray.end(); ++enemy)
		{
			//if the asteroid is active and we detect a collision between the current bullet and the current asteroid
			if (enemy->isActive && bullet->checkCollision(enemy->getRect()))
			{
				//delete the bullet (we are not using object pooling for bullets)
				bullet = m_pBulletList->bulletArray.erase(bullet);

				//because the erase function already gives us the next bullet, 
				// we set moveToNext to false so that we don't move to the next 
				// bullet manually for the outer for loop
				moveToNext = false;


				//deactivate the asteroid 
				//object pooling: inactive asteroids will not be moved/rendered
				//  but when AsteroidList::spawnAsteroid is called again, instead 
				//  of creating a new asteroid and adding it to the list, we are 
				//  going to re-initialize an inactive Asteroid that's already 
				//  created and is in the list
				enemy->isActive = false;
				break;
			}
		}
		//moveToNext will be true unless erase function is used
		// which will move our iterator to the next bullet in the list
		if (moveToNext)
		{
			++bullet;
		}

	}
}

bool CollisionManager::checkShipToAsteroidCollisions()
{

	//process each asteroid in the asteroid list
	for (auto enemy = m_pEnemyList->enemyArray.begin(); enemy != m_pEnemyList->enemyArray.end(); ++enemy)
	{
		//if the asteroid is active and we detect a collision between the ship and the current asteroid
		if (enemy->isActive && m_pHero->checkCollision(enemy->getRect()))
		{
			//we return true which triggers Game Over
			return false; //switched to false for play testing     
		}
	}


	//if the code execution came here, this means that there 
	// were no collisions detected between the ship and any asteroid
	return false;
}

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager::CollisionManager(BulletList* bulletList, EnemyList* enemyList, Hero* hero)
{
	m_pBulletList = bulletList;
	m_pEnemyList = enemyList;
	m_pHero = hero;
}

bool CollisionManager::checkCollisions()
{
	checkBulletToEnemyCollisions();
	return checkShipToAsteroidCollisions();
}
