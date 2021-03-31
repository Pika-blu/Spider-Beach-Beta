#ifndef __GAME__
#define __GAME__

#include "SDL.h"
#include "Sprite.h"
#include "Hero.h"
#include "BulletList.h"
#include "Enemy.h"
#include "Smoke.h"
#include "EnemyList.h"
#include "CollisionManager.h"
#include "Background.h"
#include "ProjectileList.h"

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	//we do one time preparation stuff here
	void prepare();

	//these four functions make our game loop
	void handleEvents();
	void update();
	void render();
	void waitForNextFrame();

	//another single call function which runs just before the game is closed
	void cleanup();

	//function to aaccess the running variable
	bool running() { return m_bRunning; }


	


private:

	Hero hero;
	BulletList bullets;
	ProjectileList projectiles;
	Smoke smoke;
	bool animateSmoke = true;
	EnemyList enemys;
	Enemy enemy;
	Background background;
	CollisionManager collisionManager;






	/* 
	A pointer points to an object and is denoted by a "*" in declaration. 
	So m_pWindow is a Pointer which *points* to an object of type SDL_Window
	*/
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	bool m_bRunning;


	//For framerate
	int targetFramerate = 30;
	int frameDelayMs = 1000 / targetFramerate;

	Uint32 currentFrameEndTime;
	Uint32 currentFrameStartTime;
	Uint32 timeSinceLastFrame;

	//for gameplay
	float deltaTime;

	//Keep gameTime in seconds
	float gameTime = 0;



	float enemySpawnTimer = 0;
	float enemySpawnInterval = 2;
	void enemySpawner();

	float projectileSpawnTimer = 0;
	float projectileInitialSpawner = 5;
	float projectileSpawnInterval =2.0; 
	void projectileSpawner();

	int i = 1;

};


#endif /* defined (__Game__) */

