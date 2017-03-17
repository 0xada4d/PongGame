#pragma once
#include "FPongGame.h"

FPongGame::FPongGame() { Reset(); }		// Constructor
void FPongGame::Reset()
{
	WindowWidth = 1000.f;
	WindowHeight = 700.f;
	BallOOB = false;					// Value is true when ball crosses left boundary (user misses the ball)
	return;
}
float FPongGame::GetWindowWidth() const { return WindowWidth; }
float FPongGame::GetWindowHeight() const { return WindowHeight; }

bool FPongGame::GetBallOOB() const { return BallOOB; }

void FPongGame::BallOOBToggle()			// Switches BallOOB from on to off and vice versa
{
	if (BallOOB) { BallOOB = false; }
	else { BallOOB = true; }
	return;
}

