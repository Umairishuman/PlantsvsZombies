#include <SFML/Graphics.hpp>
#include"Executor.h"
#include <iostream>
using namespace sf;
using namespace std;
/*
Name 1: Muhammad Umair
Name 2: Muhammad Kaleem Akhtar

Section: CS-C

Roll No 1: 23I-0662
ROll No 2: 23I0524

Instructor: Mr. Sheryar Rashid
*/

int main()
{
	RenderWindow window(VideoMode(1000, 600), "Plants Vs Zombies");
	window.setSize(sf::Vector2u(640, 640)); 
	window.setPosition(sf::Vector2i(100, 0));
	Executor executor;
	

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
