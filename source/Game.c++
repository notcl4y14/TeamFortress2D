#include "Game.h"

Game::Game (const char* title, sf::Uint32 width, sf::Uint32 height)
{
	window.create(sf::VideoMode(width, height), title);
}