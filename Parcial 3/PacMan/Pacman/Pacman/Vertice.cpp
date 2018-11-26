#include "stdafx.h"
#include "Vertice.h"


Vertice::Vertice()
{
}

Vertice::Vertice(short x, short y) 
	:M_x(x),M_y(y)
{}


Vertice::~Vertice()
{
}

/* hacemos la pregunta ? tiene estos vertices las 
 Mismas coordenas ? */
bool Vertice::operator==(Vertice& OtherVertice)
{
	if (this->M_x == OtherVertice.M_x && this->M_y == OtherVertice.M_y)
	{return true;}

return false;
}
