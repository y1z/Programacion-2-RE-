#include "stdafx.h"
#include "Tablero.h"


Tablero::Tablero()
{
}

Tablero::Tablero(std::vector<std::vector<char>> &Maze)
{
	Laberinto = Maze;
}

Tablero::~Tablero()
{
}

// Para saber si el pacman puede moverse en 
// las coordenadas espesificadas de Laberinto 
bool Tablero::IsPared(char x, char y)
{

	if (!(y > this->Laberinto.size()) || !(x > this->Laberinto[0].size()))
	{
		if (Laberinto[y][x] == '0')
		{
			return true;
		}
	}


	return false;
}
