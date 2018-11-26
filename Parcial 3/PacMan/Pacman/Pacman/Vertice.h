#pragma once
#include "stdafx.h"
#include "Arista.h"

class Vertice
{
public:
	Vertice();
	//para settiar los valores 
	Vertice(short x, short y);
	~Vertice();
public:// Variables 
	// La coordenadas 
	short M_x, M_y;

public:
	bool operator==(Vertice&);
};

