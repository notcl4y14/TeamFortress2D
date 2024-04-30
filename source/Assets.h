#include <map>

#include "SFML/Graphics.hpp"

class Assets
{
	public:
	std::map<std::string, sf::Font> fonts;

	Assets ();

	sf::Font loadFont (std::string name, sf::Font font);

	sf::Font font (std::string name);
};