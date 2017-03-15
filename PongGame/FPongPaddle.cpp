#pragma once
#include "FPongPaddle.h"
#include "FPongGame.h"

FPongGame Game1;

FPongPaddle::FPongPaddle()							// AI paddle constructor
{
	PaddleX = Game1.GetWindowWidth() - PaddleWidth;
	PaddleY = (Game1.GetWindowHeight() * .5f) - (PaddleHeight * .5f);
	Reset();
}

FPongPaddle::FPongPaddle(bool user)					// If the bool is included in constructor, we know that it is constructing a user paddle
{
	PaddleX = 0;
	PaddleY = (Game1.GetWindowHeight() * .5f) - (PaddleHeight * .5f);
	Reset();
}

void FPongPaddle::Reset()
{
	Paddle.setSize(sf::Vector2f(PaddleWidth, PaddleHeight));
	Paddle.setPosition(PaddleX, PaddleY);
	Paddle.setFillColor(Game1.GameItemColor);
	return;
}

const float FPongPaddle::GetPaddleX() { return PaddleX; }
const float FPongPaddle::GetPaddleY() { return PaddleY; }
const float FPongPaddle::GetPaddleWidth() { return PaddleWidth; }
const float FPongPaddle::GetPaddleHeight() { return PaddleHeight; }
const sf::RectangleShape FPongPaddle::GetPaddle() { return Paddle; }
const sf::FloatRect FPongPaddle::GetPaddlePosition() { return Paddle.getGlobalBounds(); }

void FPongPaddle::MovePaddle()
{
	float BottomLimit = Game1.GetWindowHeight() - PaddleHeight;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && PaddleY <= BottomLimit)
	{
		PaddleY += PaddleSpeed;
		Paddle.setPosition(PaddleX, PaddleY);
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && PaddleY >= 0.0f)
	{
		PaddleY -= PaddleSpeed;
		Paddle.setPosition(PaddleX, PaddleY);
		return;
	}
}
