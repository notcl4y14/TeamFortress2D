#include <math.h>

#include "../utils/Clamp.h"

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

	bool key_left = game.Input.IsKeyDown(sf::Keyboard::A);
	bool key_right = game.Input.IsKeyDown(sf::Keyboard::D);
	bool key_up = game.Input.IsKeyDown(sf::Keyboard::W);
	bool key_down = game.Input.IsKeyDown(sf::Keyboard::S);
	bool key_jump = game.Input.IsKeyDown(sf::Keyboard::Space);

	bool onGround = pos.z > size.z * -1;

	int DirX = key_right - key_left;
	int DirY = key_down - key_up;

	// Controls
	vel.x += (DirX * accel);
	vel.y += (DirY * accel);

	// Gravity
	vel.z += 1500 * DeltaTime;

	// Jumping
	if (key_jump)
	{
		vel.z = -250;
	}

	// Limiting speed
	vel.x = clamp(vel.x, speedMax * -1, speedMax);
	vel.y = clamp(vel.y, speedMax * -1, speedMax);

	// Friction
	if (DirX == 0)
	{
		vel.x -= sign(vel.x) * friction;
	}
	if (DirY == 0)
	{
		vel.y -= sign(vel.y) * friction;
	}

	// Applying velocity
	pos.x += vel.x * DeltaTime;
	pos.y += vel.y * DeltaTime;
	pos.z += vel.z * DeltaTime;

	// Ground collision
	if (onGround)
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