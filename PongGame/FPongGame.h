#pragma once
#include <SFML/Graphics.hpp>

class FPongGame
{
public:
	FPongGame();

	int GetWindowWidth();
	int GetWindowHeight();
	sf::RectangleShape GetLeftPaddle();		// Get shapes to send to Draw function
	sf::RectangleShape GetRightPaddle();
	sf::CircleShape GetBall();

	void Reset();


private:
	const int WindowWidth = 1000;
	const int WindowHeight = 700;
	const int PaddleWidth = 5;
	const int PaddleHeight = 10;
	const float BallRadius = 4;

	sf::RectangleShape LeftPaddle;
	sf::RectangleShape RightPaddle;
	sf::CircleShape Ball;

	int LeftPaddleX;						// Positions of various game elememts
	int LeftPaddleY;
	int RightPaddleX;
	int RightPaddleY;
	int BallX;
	int BallY;

	

};