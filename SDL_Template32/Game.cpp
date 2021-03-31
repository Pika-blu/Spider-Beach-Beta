#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//initialization successful

		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}


		//initialize the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);



		if (m_pWindow != 0)
		{
			//window creation successful

			//set up renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				//renderer creation successful
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
			}
			else
			{
				//renderer init failed
				return false;
			}
		}
		else
		{
			//SDL Init failed
			return false;
		}

		//init success! 
		//we are going to move on to the prepare function

		return true;
	}

	//init failed
	return false;
}

void Game::prepare()
{
	background = Background(m_pRenderer,  640, 480);
	hero = Hero(m_pRenderer, "hero2.png",0,0,52,52,0,195,85,85);
	bullets = BulletList(m_pRenderer);
	projectiles = ProjectileList(m_pRenderer);
	smoke = Smoke(m_pRenderer, 32, 32);
	enemys = EnemyList(m_pRenderer);
	collisionManager = CollisionManager(&bullets, &enemys, &hero);

	//set initial deltaTime, and current frame's start time
	deltaTime = 1.0f / targetFramerate;
	currentFrameStartTime = SDL_GetTicks();

	//we are ready to start our game loop
	m_bRunning = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				hero.velY = -1;
				break;

			case SDLK_s:
				hero.velY = 1;
				break;

			case SDLK_a:
				hero.velX = -1;
				break;

			case SDLK_d:
				hero.velX = 1;
				break;

			case SDLK_SPACE:
				bullets.addBullet(hero.getWeaponX(), hero.getWeaponY());
				break;

			default:
				break;
			}

		}
		else if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				hero.velY = 0;
				break;

			case SDLK_s:
				hero.velY = 0;
				break;

			case SDLK_a:
				hero.velX = 0;
				break;

			case SDLK_d:
				hero.velX = 0;
				break;

			case SDLK_ESCAPE:
				m_bRunning = false;
				break;

			default:
				break;
			}
		}
	}

}

void Game::update()
{
	background.moveX();

	enemys.update();

	hero.moveBy(hero.velX, hero.velY);

	enemySpawner();

	projectileSpawner();

}

void Game::render()
{
	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);

	//render the background
	background.draw(m_pRenderer);

	//render the ship
	hero.draw(m_pRenderer);

	//render all asteroids
	enemys.draw();

	//update the bullets
	bullets.updateBullets();

	//update the projectiles
	projectiles.updateProjectile();

	m_bRunning = !collisionManager.checkCollisions();

	//draw everything to the screen
	SDL_RenderPresent(m_pRenderer);
}



void Game::waitForNextFrame()
{
	//In this function, we are going to ensure that our game waits until the time we allocated for each frame passes

	//Step 1: Get the current time (how much time elapsed in milliseconds since SDL was initialized
	Uint32 gameTimeMs = SDL_GetTicks();

	//Step 2: Calculate how much time has passed since the current frame started
	timeSinceLastFrame = gameTimeMs - currentFrameStartTime;

	//Step 3: If the frame started less than the total allocated time for the frame
	if (timeSinceLastFrame < frameDelayMs)
	{
		//Step 4: Halt the execution until the allocated time for the frame passes
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	//Step 5: Store the time when this frame ends
	currentFrameEndTime = SDL_GetTicks();

	//Step 6: Calculate deltaTime (how much time it took for the frame to be completed)
	deltaTime = (currentFrameEndTime - currentFrameStartTime) / 1000.f;

	//Step 7: Set current game time (in seconds)
	gameTime = currentFrameEndTime / 1000.0f;

	//Step 8: Set the start time of the current frame to be the end time, so that the next time this function runs, 
	//		  we take the current end time as the new frame's start time
	currentFrameStartTime = currentFrameEndTime;

	//for testing:
	//std::cout << gameTime << " - " << deltaTime << std::endl;
}

void Game::cleanup()
{
	//cleaning game

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::enemySpawner()
{
	enemySpawnTimer += deltaTime;
	if (enemySpawnTimer >=enemySpawnInterval)
	{
		enemys.spawnEnemy();
		enemySpawnTimer = 0;
	}
}

void Game::projectileSpawner()
{
	projectileSpawnTimer += deltaTime;
	if (projectileSpawnTimer >= projectileSpawnInterval)
	{
		projectiles.addProjectile(enemys.enemyArray[(enemys.enemyArray.size() - i)].getX(),
			enemys.enemyArray[(enemys.enemyArray.size() - i)].getY());
		i++;
		projectileSpawnTimer = 0;
	}
	

}
