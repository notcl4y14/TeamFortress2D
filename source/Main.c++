#include <iostream>
#include <string>
#include <math.h>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Game.h"
#include "classes/Player.h"

Game game ("Team Fortress 2D", 900, 600);

Player player (sf::Vector3f(10, 10, -50), sf::Vector3f(25, 25, 50));

sf::Font CreateFont (std::string source)
{
	sf::Font font;
	font.loadFromFile("../assets/TF2secondary.ttf");
	return font;
}

void Update () {
	player.Update(game);
}

void Draw ()
{
	// Clear screen
	game.window.clear(sf::Color(28, 46, 77, 255));

	player.Draw(game);
}

int main ()
{
	sf::Font font = game.assets.loadFont("TF2_Secondary", CreateFont("../assets/TF2secondary.ttf"));

	sf::Text FPS_text ("FPS: ", font, 14);

	sf::Texture crosshairTexture;
	crosshairTexture.loadFromFile("../assets/crosshair01.png");

	sf::Sprite crosshair;
	crosshair.setTexture(crosshairTexture);
	
	sf::Image icon;
	icon.loadFromFile("../assets/icon_rotated.png");

	game.window.setIcon(64, 64, icon.getPixelsPtr());
	game.window.setFramerateLimit(200);

	// Start the game loop
	while (game.window.isOpen())
	{
		// Process events
		sf::Event event;
		while (game.window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					game.window.close();
					break;
				
				case sf::Event::KeyPressed:
					game.Input.keys[event.key.code] = true;
					break;
				
				case sf::Event::KeyReleased:
					game.Input.keys[event.key.code] = false;
					break;
				
				case sf::Event::Resized:
					sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        			game.window.setView(sf::View(visibleArea));
					break;

			}
		}

		game.Perf_DeltaTime = game.Perf_DeltaClock.restart();

		Update();
		Draw();
		

		sf::Vector2i mousePos = sf::Mouse::getPosition(game.window);

		// std::cout << mousePos.x << "; " << mousePos.y << "\n";
		
		crosshair.setPosition(mousePos.x - crosshair.getTexture()->getSize().x / 2, mousePos.y - crosshair.getTexture()->getSize().y / 2);

		game.window.draw( crosshair );

		FPS_text.setString("FPS: " +
			std::to_string(
				(int)floor(
					1 / game.Perf_DeltaTime.asSeconds()
				)
			)
		);

		game.window.draw( FPS_text );
 
		// Update the window
		game.window.display();
	}

	icon.~Image();
 
	return EXIT_SUCCESS;
}