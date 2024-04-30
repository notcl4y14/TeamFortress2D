#include <map>
#include "SFML/Window.hpp"

class Input
{
	public:
	std::map<sf::Keyboard::Key, bool> keys;

	Input ();

	bool IsKeyDown (sf::Keyboard::Key key);
	bool IsKeyUp (sf::Keyboard::Key key);
};