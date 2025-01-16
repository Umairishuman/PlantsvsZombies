#include <SFML/Graphics.hpp>
#include"Executor.h"
#include <iostream>
using namespace sf;
using namespace std;


int main()
{
	RenderWindow window(VideoMode(1000, 600), "Plants Vs Zombies");
	window.setSize(sf::Vector2u(640, 640)); // Recommended for 1366x768 (768p) displays.
	window.setPosition(sf::Vector2i(100, 0));
	Executor executor;
	/*Image icon;
	if (!icon.loadFromFile("../SFML/Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());*/

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			executor.handleInput(event, window);
			if (event.type == Event::Closed)
				window.close();
		}
		executor.Run(window);
		window.setSize(sf::Vector2u(1000, 600));
		window.display();
		window.clear();
	}
	return 0;
}
