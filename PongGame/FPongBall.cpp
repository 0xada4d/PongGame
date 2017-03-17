#pragma once
#include <random>
#include "FPongBall.h"
#include "FPongGame.h"
#include "FPongPaddle.h"

FPongGame Game;										// TODO Get rid of these instantiations here, rather use references& as parameters in the functions
FPongPaddle Paddle1;

FPongBall::FPongBall() { Reset(); }
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
const float FPongBall::GetBallX() { return BallPositionX; }
const float FPongBall::GetBallY() { return BallPositionY; }
const sf::FloatRect FPongBall::GetBallBounds() { return Ball.getGlobalBounds(); }

void FPongBall::ProcessBallXPos(FPongBall& Ball, FPongPaddle& Paddle1, FPongGame& Game)		// Check if ball has hit width boundary, and if so choose direction
{
	if (Ball.GetBallX() <= 1.0f)															// Ball has crossed left boundary
	{
		Game.BallOOBToggle();
		return;
	}
	if (Ball.GetBallBounds().intersects(Paddle1.GetPaddleBounds()))							// Ball collides with user paddle
	{ 
		BallDirectionX = Game.RIGHT;
		return;
	}
	if (BallPositionX >= Game.GetWindowWidth() - BallHeight)								// Ball hits right limit of screen
	{
		BallDirectionX = Game.LEFT;
		return;
	}
	return;																					// If code gets here, ball continues in same direction
}

void FPongBall::ProcessBallYPos(FPongGame& Game)			// Check if ball has hit Height boundary, and choose direction based on that
{															// TODO fix references to objects, maybe pass ref's as parameters?
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

void FPongBall::BallLeadPaddle(FPongPaddle& Paddle)			// Function that sets AI paddle y position to follow ball y position
{
	float PaddleY = BallPositionY;
	Paddle.SetPaddleY(PaddleY);
	return;
}
