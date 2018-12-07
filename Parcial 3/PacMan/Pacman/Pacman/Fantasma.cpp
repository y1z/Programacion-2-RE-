#include "stdafx.h"
#include "Fantasma.h"


Fantasma::Fantasma()
{
}

void Fantasma::Darw()
{
	al_draw_scaled_bitmap(ptr_Bitmap, M_datos.PosicionX, M_datos.PosicionY, 
		M_datos.Anchura, M_datos.Altura,
		// determina donde sera dibujado en el mapa 
		(M_EscalaHorizontal * M_PosActual.M_x) + this->M_PosicionX,
		(M_EscalaVertical * M_PosActual.M_y) + this->M_PosicionY,
		this->M_EscalaHorizontal,
		this->M_EscalaVertical,
		0);
}

Fantasma::~Fantasma()
{
}

void Fantasma::Move() 
{
	switch (dir)
	{
	case Entidad::Norte:
		break;
	case Entidad::Sur:
		// para ver si esta en los confines del juego 
		break;
	case Entidad::Este:
		// revisar si esta en el borde horizontal del juego
		
		break;
	case Entidad::Oeste:
		// revisar si esta en el borde horizontal del juego
		break;
	default:
		fprintf(stderr, "Error PacMan en estado desconocido");
		break;
	}
}

void Fantasma::SetLimites(short x, short y) {
	this->M_Limite.x = x - 1;
	this->M_Limite.y = y - 1;
}

void Fantasma::IniciarFantasma(char chr,short PosX, short PosY) {
	M_datos.Altura = 14;
	M_datos.Anchura = 14;
	switch (chr)
	{
	case('b'):
		M_datos.PosicionX = 4;
		M_datos.PosicionY = 65;
		break;
	case('p'):

		M_datos.PosicionX = 4;
		M_datos.PosicionY = 81;
		break;
	case('i'):
		M_datos.PosicionX = 4;
		M_datos.PosicionY = 97;
		break;
	default:
		M_datos.PosicionX = 4;
		M_datos.PosicionY = 65;
		break;
	}
	M_PosActual.M_x = PosX;
	M_PosActual.M_y = PosY;
}
// TODO : HACER que solo use esta madre en el loop 
void Fantasma::Conportamiento(Grafo& grafo, Vertice& Destino)
{
	if (EstaMoviendo) {
		Frame++;
		if(Frame == 60)
		{
			if (M_Camino.size() == 0) {
				EstaMoviendo = false;
				Frame = 0;
			}
			else {
				M_PosActual = M_Camino[0];
			
				M_Camino.erase(M_Camino.begin() + 0);
				Frame = 0;
			}
		}
		Darw();
	}
	else {
		 M_Camino = MetodosBusqueda(grafo, M_PosActual, Destino);
		 EstaMoviendo = true;
	}
}