#include "stdafx.h"
#include "Pacman.h"

PacMan::PacMan()
{

}

PacMan::~PacMan()
{
}


void PacMan::Move()
{
	this->M_PosicionX++;
	this->M_PosicionY++;
}
