#pragma once
#include "FPongGame.h"

FPongGame::FPongGame() { Reset(); }								// Constructor
void FPongGame::Reset()
{
	WindowWidth = 1000.f;
	WindowHeight = 700.f;
	return;
}
float FPongGame::GetWindowWidth() const { return WindowWidth; }
float FPongGame::GetWindowHeight() const { return WindowHeight; }

