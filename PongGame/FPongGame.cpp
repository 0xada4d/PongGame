
#pragma once
#include <SFML/Graphics.hpp>
#include "FPongGame.h"
#include "FPongBall.h"

using int32 = int;

FPongGame::FPongGame()
{
	Reset();
}

float FPongGame::GetWindowWidth() { return WindowWidth; }
float FPongGame::GetWindowHeight() { return WindowHeight; }
sf::RectangleShape FPongGame::GetLeftPaddle() { return LeftPaddle; }
sf::RectangleShape FPongGame::GetRightPaddle() { return RightPaddle; }

void FPongGame::Reset()
{
	LeftPaddleX = 0;
	LeftPaddleY = (WindowHeight * .5) - (PaddleHeight * .5);
	RightPaddleX = (WindowWidth - PaddleWidth);
	RightPaddleY = (WindowHeight * .5) - (PaddleHeight * .5);
	
	LeftPaddle.setSize(sf::Vector2f(PaddleWidth, PaddleHeight));
	LeftPaddle.setPosition(LeftPaddleX, LeftPaddleY);
	RightPaddle.setPosition(RightPaddleX, RightPaddleY);
	RightPaddle.setSize(sf::Vector2f(PaddleWidth, PaddleHeight));

	LeftPaddle.setFillColor(GameItemColor);
	RightPaddle.setFillColor(GameItemColor);
}
