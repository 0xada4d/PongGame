/*
This is the console exe that makes use of the FPongGame class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FPongGame, FPongBall, and FPongPaddle classes.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <vector>
#include "FPongGame.h"
#include "FPongBall.h"
#include "FPongPaddle.h"

sf::RenderWindow window;
FPongGame PongGame;
FPongBall PongBall;
FPongPaddle AIPaddle;
FPongPaddle UserPaddle(true);

int main()  // Entry point for our application
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(PongGame.GetWindowWidth(), PongGame.GetWindowHeight()), "Pong");	// Make a window

	bool bPlayAgain = true;

	do {

		while (window.isOpen())							// Keep looping while window is open
		{
		
			if (PongGame.Lives > 0)
			{
				sf::Event event;
				while (window.pollEvent(event))				// Loop through event queue
				{
					if (event.type == sf::Event::Closed)	// If close event, close window
						window.close();
				}

				window.clear();								// Clear everything from the last run of the while loop

				PongBall.ProcessBallXPos(PongBall, UserPaddle, PongGame);

				if (PongGame.GetBallOOB())						// If the ball goes below x = 1.0, this will be true
				{												
					PongGame.Lives--;							// Decrement lives and reset the game
					PongBall.Reset();
					AIPaddle.Reset();
					PongGame.Reset();
					continue;
				}

				PongBall.ProcessBallYPos(PongGame);
				PongBall.ChangeBallPosition();
				PongBall.BallLeadPaddle(AIPaddle);
				UserPaddle.UserControlPaddle();

				window.draw(PongBall.GetBall());
				window.draw(AIPaddle.GetPaddle());
				window.draw(UserPaddle.GetPaddle());

				window.display();							// Show everything we just drew
			}
			else 
			{ 
				sf::Event event;
				while (window.pollEvent(event))				// Loop through event queue
				{
					if (event.type == sf::Event::Closed)	// If close event, close window
						window.close();

				}
				window.clear();

				sf::Font font;
				font.loadFromFile("Raleway-Medium.ttf");
				sf::Text GameLossNotice("Game Over", font, 100);								// Loss message
				GameLossNotice.setFillColor(sf::Color::Green);
				
				float GLNoticeWidthHalf = GameLossNotice.getLocalBounds().width * .5f;			// Find center of GameLossNotice Text

				GameLossNotice.setPosition((PongGame.GetWindowWidth() * .5f) - GLNoticeWidthHalf, PongGame.GetWindowHeight() * .4f);
		
				window.draw(GameLossNotice);
				window.display();
			}

		}
	} while (bPlayAgain);

	return 0;										// Exit application
}

/* 

void IntroduceGame()
{
	sf::Event event1;
	while (window.pollEvent(event1))				// Loop through event queue
	{
		if (event1.type == sf::Event::Closed)	// If close event, close window
			window.close();
	}

	sf::Text GameTitle;
	sf::Text GameIntro;
	sf::Text EnterGame;
	sf::Text ExitGame;
	std::vector<sf::Text> TextObjectArray = { GameTitle, GameIntro, EnterGame, ExitGame };

	sf::Font font;
	font.loadFromFile("Raleway-Medium.ttf");

	GameTitle.setString("Pong");
	GameTitle.setFont(font);
	GameTitle.setFillColor(sf::Color::Green);
	GameTitle.setCharacterSize(75);
	GameTitle.setPosition(PongGame.GetWindowWidth() * .5f, PongGame.GetWindowHeight() * .2f);
	GameIntro.setString("Ready to play?");
	GameIntro.setCharacterSize(60);
	EnterGame.setString("Play Game!");
	EnterGame.setCharacterSize(50);
	ExitGame.setString("Not Now");
	ExitGame.setCharacterSize(50);
	
	window.draw(GameTitle);
	window.display();


}

*/

