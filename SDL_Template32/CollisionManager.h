#pragma once
#include "BulletList.h"
#include "EnemyList.h"
#include "Hero.h"

class CollisionManager
{
	BulletList* m_pBulletList;
	EnemyList* m_pEnemyList;
	Hero* m_pHero;


	void checkBulletToEnemyCollisions();
	bool checkShipToAsteroidCollisions();



public:

	CollisionManager();
	~CollisionManager();
	CollisionManager(BulletList* bulletList, EnemyList* enemyList, Hero* hero);

	bool checkCollisions();

};


