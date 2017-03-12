#pragma once
#include <SFML/Graphics.hpp>

class FPongPaddle
{
public:
	FPongPaddle();
	FPongPaddle(bool);
	void Reset();

	sf::RectangleShape GetPaddle();

private:
	const float PaddleWidth = 9;
	const float PaddleHeight = 70;
	const float PaddleSpeed = 1;

	float PaddleX;
	float PaddleY;
	
	sf::RectangleShape Paddle;
};
