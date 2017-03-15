#pragma once
#include <SFML/Graphics.hpp>
#include "FPongBall.h"
#include "FPongPaddle.h"

class FPongBall
{
public:
	FPongBall();
	void Reset();

	const sf::RectangleShape GetBall();
	const sf::FloatRect GetBallPosition();

	void ChangeBallXDirection(FPongBall&, FPongPaddle&);
	void ChangeBallYDirection(); 
	void ChangeBallPosition();

private:
	const float BallWidth = 10.0f;
	const float BallHeight = 10.0f;
	float BallSpeed = .3f;
	float BallDirectionX;		
	float BallDirectionY;

	float BallPositionX;
	float BallPositionY;
	
	sf::RectangleShape Ball;
};