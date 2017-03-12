#pragma once
#include "FPongPaddle.h"
#include "FPongGame.h"

FPongGame Game1;

FPongPaddle::FPongPaddle()							// AI paddle constructor
{
	PaddleX = Game1.GetWindowWidth() - PaddleWidth;
	PaddleY = (Game1.GetWindowHeight() * .5) - (PaddleHeight * .5);
	Reset();
}

FPongPaddle::FPongPaddle(bool user)					// If the bool is included in constructor, we know that it is constructing a user paddle
{
	PaddleX = 0;
	PaddleY = (Game1.GetWindowHeight() * .5) - (PaddleHeight * .5);
	Reset();
}

void FPongPaddle::Reset()
{
	Paddle.setSize(sf::Vector2f(PaddleWidth, PaddleHeight));
	Paddle.setPosition(PaddleX, PaddleY);
	Paddle.setFillColor(Game1.GameItemColor);
	return;
}

sf::RectangleShape FPongPaddle::GetPaddle() { return Paddle; }