
#pragma once
#include <SFML/Graphics.hpp>
#include "FPongGame.h"



FPongGame::FPongGame()
{
	Reset();
}

int FPongGame::GetWindowWidth() { return WindowWidth; }
int FPongGame::GetWindowHeight() { return WindowHeight; }
sf::RectangleShape FPongGame::GetLeftPaddle() { return LeftPaddle; }
sf::RectangleShape FPongGame::GetRightPaddle() { return RightPaddle; }
sf::CircleShape FPongGame::GetBall() { return Ball; }

void FPongGame::Reset()
{
	LeftPaddleX = 0;
	LeftPaddleY = (WindowHeight * .5) - (PaddleHeight * .5);
	RightPaddleX = (WindowWidth - PaddleWidth);
	RightPaddleY = (WindowHeight * .5) - (PaddleHeight * .5);

	Ball.setRadius(BallRadius);
	LeftPaddle.setPosition(LeftPaddleX, LeftPaddleY);
	RightPaddle.setPosition(RightPaddleX, RightPaddleY);
}
