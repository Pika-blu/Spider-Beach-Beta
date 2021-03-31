#include "TextureManager.h"
#include "SDL.h"
#include <iostream>

// Global static pointer used to ensure a single instance of the class.
TextureManager* TextureManager::s_pInstance = NULL;

TextureManager* TextureManager::Instance()
{
	if (s_pInstance == NULL)
	{
		s_pInstance = new TextureManager();
	}


	return s_pInstance;
}

void TextureManager::AddSmoke(SDL_Renderer* renderer, int x, int y)
{
	s = Smoke(renderer, x, y);
}

void TextureManager::AnimateSmoke()
{
	s.animate();
}
