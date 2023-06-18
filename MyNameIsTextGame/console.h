#pragma once
#include<Windows.h>
enum class COLOR
{
	BLACK,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VOILET,
	YELLOW,
	LIGHT_GRAY,
	GRAY,
	LIGHT_BLUE, LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VOILET, LIGHT_YELLOW,
	WHITE
};
void FullScreen();
BOOL Gotoxy(int x, int y);
void GotoxyPlayer(int x, int y);
void ConsoleCursor(bool, DWORD);
void SetColor(int, int);
int GetColor();
int GetbgColor();