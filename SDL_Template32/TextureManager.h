#pragma once
#include "Smoke.h"
#include <vector>

class TextureManager
{
private:
	TextureManager() {};
	static TextureManager* s_pInstance;
	
	TextureManager(TextureManager const&) {};             // copy constructor is private
	TextureManager& operator=(TextureManager const&) {};  // assignment operator is private

	Smoke s;

public:

	static TextureManager* Instance();
	void AddSmoke(SDL_Renderer* renderer, int x, int y);
	void AnimateSmoke();
};

