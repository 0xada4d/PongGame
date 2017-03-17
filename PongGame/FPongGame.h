/*
This class houses variables relied upon by game components.
*/

#pragma once
#include <SFML/Graphics.hpp>

class FPongGame
{
public:
	const sf::Color GameItemColor = sf::Color::Green;
	int Lives = 3;

	const float RIGHT = 1.f;					// Directions of travel
	const float LEFT = -1.f;
	const float DOWN = 1.f;
	const float UP = -1.f;
	const float DIRECTION_X[2] = { RIGHT, LEFT };	// Used on Reset, for ball to choose random direction

	bool BallOOB = false;

	const float DIRECTION_Y[2] = { DOWN, UP };

	FPongGame();

	float GetWindowWidth() const;
	float GetWindowHeight() const;

	void Reset();

private:
	float WindowWidth;
	float WindowHeight;
};