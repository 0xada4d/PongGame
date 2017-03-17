#pragma once
#include "FPongGame.h"

FPongGame::FPongGame() { Reset(); }								// Constructor
void FPongGame::Reset()
{
	WindowWidth = 1000.f;
	WindowHeight = 700.f;
	BallOOB = false;
	return;
}
float FPongGame::GetWindowWidth() const { return WindowWidth; }
float FPongGame::GetWindowHeight() const { return WindowHeight; }

bool FPongGame::GetBallOOB() const { return BallOOB; }

void FPongGame::BallOOBSwitch()
{
	if (BallOOB) { BallOOB = false; }
	else { BallOOB = true; }
	return;
}

