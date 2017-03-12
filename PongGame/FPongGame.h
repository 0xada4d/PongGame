#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class FPongGame
{
public:
	const float WindowWidth = 1000;
	const float WindowHeight = 700;
	const sf::Color GameItemColor = sf::Color::Green;

	const float RIGHT = 1;					// Directions of travel
	const float LEFT = -1;
	const float DOWN = 1;
	const float UP = -1;
	const float DIRECTION_X[2] = { RIGHT, LEFT };	// Used on Reset, for ball to choose random direction
	const float DIRECTION_Y[2] = { DOWN, UP };

	FPongGame();

	float GetWindowWidth();
	float GetWindowHeight();

	sf::RectangleShape GetLeftPaddle();		// Get shapes to send to Draw function
	sf::RectangleShape GetRightPaddle();

	void Reset();


private:
	const float PaddleWidth = 9;
	const float PaddleHeight = 70;

	sf::RectangleShape LeftPaddle;
	sf::RectangleShape RightPaddle;

	float LeftPaddleX;						// Positions of various game elements
	float LeftPaddleY;
	float RightPaddleX;
	float RightPaddleY;
};