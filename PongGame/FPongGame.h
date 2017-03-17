/*
The FPongGame class contains variables and methods used by other game components.
*/

#pragma once
#include <SFML/Graphics.hpp>

class FPongGame
{
public:
	const sf::Color GameItemColor = sf::Color::Green;
	int Lives = 3;

	// Directions of travel
	const float RIGHT = 1.f;					
	const float LEFT = -1.f;
	const float DOWN = 1.f;
	const float UP = -1.f;

	FPongGame();

	float GetWindowWidth() const;
	float GetWindowHeight() const;
	bool GetBallOOB() const;

	void BallOOBToggle();

	void Reset();

private:
	float WindowWidth;
	float WindowHeight;

	bool BallOOB = false;
};