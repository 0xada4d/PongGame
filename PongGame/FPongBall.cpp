#pragma once
#include <random>
#include "FPongBall.h"
#include "FPongGame.h"

FPongGame Game;

FPongBall::FPongBall()
{
	Reset();
}

void FPongBall::Reset()
{
	BallPositionX = (Game.GetWindowWidth() * .5);
	BallPositionY = 0;
	Ball.setRadius(BallRadius);
	Ball.setPosition(BallPositionX, BallPositionY);
	Ball.setFillColor(Game.GameItemColor);
	BallDirectionX = Game.RIGHT;					// TODO add random beginning direction
	BallDirectionY = Game.DOWN;
}

sf::CircleShape FPongBall::GetBall() { return Ball; }



void FPongBall::ChangeBallXDirection()						// Check if ball has hit width boundary, and choose direction based on that
{
	if (BallPositionX <= 0.0) 
	{ 
		BallDirectionX = Game.RIGHT;
		return;
	}
	if (BallPositionX >= Game.GetWindowWidth() - BallDiameter)
	{
		BallDirectionX = Game.LEFT;
		return;
	}
	return;													// If code gets here, ball continues in same direction
}

void FPongBall::ChangeBallYDirection()						// Check if ball has hit Height boundary, and choose direction based on that
{
	if (BallPositionY <= 0.0)
	{
		BallDirectionY = Game.DOWN;
		return;
	}
	if (BallPositionY >= Game.GetWindowHeight() - BallDiameter)
	{
		BallDirectionY = Game.UP;
		return;
	}
	return;													// If code gets here, ball continues in same direction
}

void FPongBall::ChangeBallPosition()						// Update ball position based on current direction and speed
{
	BallPositionX = BallPositionX + BallSpeed * BallDirectionX;
	BallPositionY = BallPositionY + BallSpeed * BallDirectionY;
	Ball.setPosition(BallPositionX, BallPositionY);
}
