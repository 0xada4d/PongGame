#pragma once
#include <SFML/Graphics.hpp>

class FPongPaddle
{
public:
	FPongPaddle();
	FPongPaddle(bool);
	void Reset();

	sf::RectangleShape GetPaddle();

	void MovePaddle();

private:
	const float PaddleWidth = 9;
	const float PaddleHeight = 100;
	const float PaddleSpeed = .5;

	float PaddleX;
	float PaddleY;
	
	sf::RectangleShape Paddle;
};
