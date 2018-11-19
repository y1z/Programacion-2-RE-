#pragma once
#include"stdafx.h"

class PacMan;

class Tablero
{
public:
	Tablero();
	Tablero(std::vector<std::vector<char>> &Maze);
	~Tablero();
public ://variables 
	std::vector<std::vector<char>> Laberinto;
public:// metodos 
	bool IsPared(char x, char y);
	
};

