#include <math.h>

#include "Player.h"

int sign (float value)
{
	float abs_val = abs(value);
	int result = abs_val == 0 ? 0 : value / abs_val;
	return result;
}

sf::RectangleShape shape;

Player::Player (sf::Vector3f pos, sf::Vector3f size)
{
	this->pos = pos;
	this->size = size;

	this->accel = 100;
	this->friction = 100;
	this->speedMax = 200;
}

void Player::Update (Game &game)
{
	float DeltaTime = game.Perf_DeltaTime.asSeconds();

	int DirX = game.Input.IsKeyDown(sf::Keyboard::D) - game.Input.IsKeyDown(sf::Keyboard::A);
	int DirY = game.Input.IsKeyDown(sf::Keyboard::S) - game.Input.IsKeyDown(sf::Keyboard::W);

	vel.x += (DirX * accel);
	vel.y += (DirY * accel);
	vel.z += 1500 * DeltaTime;

	if (game.Input.IsKeyDown(sf::Keyboard::Space))
	{
		vel.z = -250;
	}
	
	if (vel.x < speedMax * -1)
	{
		vel.x = speedMax * -1;
	}
	else if (vel.x > speedMax)
	{
		vel.x = speedMax;
	}
	
	if (vel.y < speedMax * -1)
	{
		vel.y = speedMax * -1;
	}
	else if (vel.y > speedMax)
	{
		vel.y = speedMax;
	}

	if (DirX == 0)
	{
		vel.x -= sign(vel.x) * friction;
	}

	if (DirY == 0)
	{
		vel.y -= sign(vel.y) * friction;
	}

	pos.x += vel.x * DeltaTime;
	pos.y += vel.y * DeltaTime;
	pos.z += vel.z * DeltaTime;

	if (pos.z > size.z * -1)
	{
		pos.z = size.z * -1;
		vel.z = 0;
	}
}

void Player::Draw (Game &game)
{
	shape.setOutlineThickness(1);
	shape.setFillColor( sf::Color(0, 0, 0, 0) );
	shape.setOutlineColor( sf::Color::White );
	
	shape.setPosition( sf::Vector2f(pos.x, pos.y + pos.z) );
	shape.setSize( sf::Vector2f(size.x, size.z) );
	game.window.draw( shape );

	shape.setPosition( sf::Vector2f(pos.x, pos.y) );
	shape.setSize( sf::Vector2f(size.x, size.y) );
	game.window.draw( shape );
}