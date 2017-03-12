/*
This is the console exe that makes use of the FPongGame class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FPongGame class.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include "FPongGame.h"
#include "FPongBall.h"

FPongGame PongGame;
FPongBall PongBall;

int main()  // Entry point for our application
{
	srand(time(NULL));								// Seed random number generator
	sf::RenderWindow window(sf::VideoMode(PongGame.GetWindowWidth(), PongGame.GetWindowHeight()), "Hello from SFML");	// Make a window

	while (window.isOpen())							// Keep looping while window is open
	{
		sf::Event event;
		while (window.pollEvent(event))				// Loop through event queue
		{
			if (event.type == sf::Event::Closed)	// If close event, close window
				window.close();
		}

		window.clear();								// Clear everything from the last run of the while loop

		PongBall.ChangeBallXDirection();
		PongBall.ChangeBallYDirection();
		PongBall.ChangeBallPosition();
		
		window.draw(PongBall.GetBall());
		window.draw(PongGame.GetLeftPaddle());
		window.draw(PongGame.GetRightPaddle());

		window.display();							// Show everything we just drew
	}

	return 0;										// Exit application
}
