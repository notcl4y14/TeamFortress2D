#include "Input.h"

Input::Input () {};

bool Input::IsKeyDown (sf::Keyboard::Key key)
{
	for (const auto& [k, value] : keys)
	{
		if (k == key)
		{
			return value;
		}
	}
	
	return false;
}

bool Input::IsKeyUp (sf::Keyboard::Key key)
{
	for (const auto& [k, value] : keys)
	{
		if (k == key)
		{
			return !value;
		}
	}
	
	return true;
}