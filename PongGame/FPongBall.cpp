#pragma once
#include <random>
#include "FPongBall.h"
#include "FPongGame.h"
#include "FPongPaddle.h"

FPongGame Game;
FPongPaddle Paddle1;

FPongBall::FPongBall()
{
	Reset();
}

void FPongBall::Reset()
{
	BallPositionX = (Game.GetWindowWidth() * .3f);
	BallPositionY = 0.f;
	Ball.setSize(sf::Vector2f(BallWidth, BallHeight));
	Ball.setPosition(BallPositionX, BallPositionY);
	Ball.setFillColor(Game.GameItemColor);
	BallDirectionX = Game.RIGHT;					// TODO add random beginning direction
	BallDirectionY = Game.DOWN;
}

const sf::RectangleShape FPongBall::GetBall() { return Ball; }
const sf::FloatRect FPongBall::GetBallPosition() { return Ball.getGlobalBounds(); }



void FPongBall::ChangeBallXDirection(FPongBall& Ball, FPongPaddle& Paddle1)						// Check if ball has hit width boundary, and choose direction based on that
{
	if (Ball.GetBallPosition().intersects(Paddle1.GetPaddlePosition()))
	{ 
		BallDirectionX = Game.RIGHT;
		return;
	}
	if (BallPositionX >= Game.GetWindowWidth() - BallHeight)
	{
		BallDirectionX = Game.LEFT;
		return;
	}
	return;													// If code gets here, ball continues in same direction
}

void FPongBall::ChangeBallYDirection()						// Check if ball has hit Height boundary, and choose direction based on that
{
	if (BallPositionY <= 0.0f)
	{
		BallDirectionY = Game.DOWN;
		return;
	}
	if (BallPositionY >= Game.GetWindowHeight() - BallHeight)
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
	return;
}
