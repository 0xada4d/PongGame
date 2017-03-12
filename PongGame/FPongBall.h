#pragma once
#include <SFML/Graphics.hpp>

using int32 = int;

class FPongBall
{
public:
	FPongBall();
	void Reset();

	sf::CircleShape GetBall();

	void ChangeBallXDirection();
	void ChangeBallYDirection(); 
	void ChangeBallPosition();

private:
	const float BallRadius = 4.0;
	const float BallDiameter = BallRadius * 2.0;
	float BallSpeed = .3;
	float BallDirectionX;		
	float BallDirectionY;

	float BallPositionX;
	float BallPositionY;
	
	sf::CircleShape Ball;
};