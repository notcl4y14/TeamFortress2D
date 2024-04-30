#pragma once

#include "SFML/Graphics.hpp"

#include "../Game.h"

class Player
{
public:
	sf::Vector3f pos;
	sf::Vector3f size;

	sf::Vector3f vel;
	sf::Vector3f pivot;

	float accel;
	float friction;
	float speedMax;
	
	Player (sf::Vector3f Position, sf::Vector3f Size);
	
	void Update (Game &game);
	void Draw (Game &game);
};