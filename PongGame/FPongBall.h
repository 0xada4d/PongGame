#pragma once
#include <SFML/Graphics.hpp>
#include "FPongPaddle.h"
#include "FPongGame.h"

class FPongBall
{
public:
	FPongBall();
	void Reset();

	const sf::RectangleShape GetBall();
	const float GetBallX();
	const float GetBallY();
	const sf::FloatRect GetBallPosition();

	void ProcessBallXPos(FPongBall&, FPongPaddle&, FPongGame&);
	void ProcessBallYPos(); 
	void ChangeBallPosition();
	void BallLeadPaddle(FPongPaddle&);					// Function to emulate AI-like behavior in non-user-controlled paddle

private:
	const float BallWidth = 10.0f;
	const float BallHeight = 10.0f;
	float BallSpeed = .4f;
	float BallDirectionX;		
	float BallDirectionY;

	float BallPositionX;
	float BallPositionY;
	
	sf::RectangleShape Ball;
};