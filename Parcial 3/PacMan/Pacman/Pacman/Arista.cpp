#include "stdafx.h"
#include "Arista.h"

Arista::Arista()
{
}


Arista::Arista(Vertice &Vert1 , Vertice &Vert2)
{
	setVertices(Vert1, Vert2);
}

Arista::~Arista()
{
	this->ptr_Vert1 = nullptr;
	this->ptr_Vert2 = nullptr;
}

void Arista::setVertices(Vertice &Ver1, Vertice &Ver2) {
	this->ptr_Vert1 = &Ver1;
	this->ptr_Vert2 = &Ver2;
}

bool Arista::operator==(Vertice& Compara) {
	
	if (ptr_Vert1 == &Compara || ptr_Vert2 == &Compara)
	{return true;}

	return false;
}