#pragma once

#include "SFML/Graphics.hpp"

#include "Input.h"
#include "Assets.h"

class Game
{
	public:
	sf::RenderWindow window;

	sf::Clock Perf_DeltaClock;
	sf::Time Perf_DeltaTime;

	Input Input;
	Assets assets;

	Game (const char* title, sf::Uint32 width, sf::Uint32 height);
};