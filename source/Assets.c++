#include "Assets.h"

Assets::Assets () {}

sf::Font Assets::loadFont (std::string name, sf::Font font)
{
	auto it = fonts.find(name);
	if (it != fonts.end())
	{
		return;
	}

	fonts[name] = font;

	return fonts[name];
}

sf::Font Assets::font (std::string name)
{
	return fonts[name];
}