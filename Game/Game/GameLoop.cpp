#include"GameLoop.h"

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
}

bool GameLoop::getGameState()
{
	return GameState;
}

void GameLoop::Intialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			cout << "Succeeded!" << endl;
			GameState = true;
		}
		else
		{
			cout << "Not created!" << endl;
		}
	}
	else
	{
		cout << "window not created!" << endl;
	}
}

void GameLoop::Event()
{
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = false;
	}
	if (event1.type == SDL_MOUSEMOTION)
	{
		cout << event1.motion.x << "  " << event1.motion.y << endl;
	}
	if (event1.type == SDL_MOUSEBUTTONDOWN)
	{
		cout << "Pressed!" << endl;
	}
}

void GameLoop::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}