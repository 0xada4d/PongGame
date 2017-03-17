#pragma once
#include <SFML/Graphics.hpp>

class FPongPaddle
{
public:
	FPongPaddle();
	FPongPaddle(bool);
	void Reset();

	const float GetPaddleX();
	const float GetPaddleY();
	const float GetPaddleWidth();
	const float GetPaddleHeight();
	const sf::RectangleShape GetPaddle();
	const sf::FloatRect GetPaddlePosition();

	void SetPaddleY(float);

	void UserControlPaddle();

private:
	const float PaddleWidth = 9.0f;
	const float PaddleHeight = 200.0f;
	const float PaddleSpeed = .5f;

	float PaddleX;
	float PaddleY;
	
	sf::RectangleShape Paddle;
};
