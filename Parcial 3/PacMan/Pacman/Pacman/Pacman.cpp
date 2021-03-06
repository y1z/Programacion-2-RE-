#include "stdafx.h"
#include "Pacman.h"

PacMan::PacMan(ALLEGRO_BITMAP *Bitmap, char poX, char poY, char Scale)
{
	ptr_Bitmap = Bitmap;
	M_MapCoordenadas.x = poX;
	M_MapCoordenadas.y = poY;
	M_Limite.x = 0;
	M_Limite.y = 0;
	M_Scale = Scale;
}

PacMan::PacMan()
{}

PacMan::~PacMan()
{}

void PacMan::Move()
{
	switch (dir)
	{
	case Entidad::Norte:

		if (M_MapCoordenadas.y > 0)
		{	
			if (this->ptr_tablero->IsPared(M_MapCoordenadas.x, M_MapCoordenadas.y - 1))
			{
				// usamos las dimenciones de pacman y 
				// cuanto a avancado en cuador x 
				if (M_EscalaVertical + M_PosicionY <= 0)
				{
					M_MapCoordenadas.y--;
					M_PosicionY = 0;
				}
				else {
					M_PosicionY -= M_speed;
				}
			}

		}
		break;
	case Entidad::Sur:
		// para ver si esta en los confines del juego 
		if (M_MapCoordenadas.y < M_Limite.y)
		{
			// para ver si esta colisionado con una pared 
			if (this->ptr_tablero->IsPared(M_MapCoordenadas.x, M_MapCoordenadas.y + 1))
			{
				if (M_PosicionY - M_EscalaVertical >= 0)
				{
					M_MapCoordenadas.y++;
					M_PosicionY = 0;
				}
				else {
					M_PosicionY += M_speed;
				}
			}
		}
		break;
	case Entidad::Este:
		// revisar si esta en el borde horizontal del juego
		if (M_MapCoordenadas.x < M_Limite.x) {
			// para ver si esta colisionado con una pared 
			if (this->ptr_tablero->IsPared(M_MapCoordenadas.x + 1, M_MapCoordenadas.y))
			{
				if (M_PosicionX >= M_EscalaHorizontal) {
					M_PosicionX = 0;
					M_MapCoordenadas.x++;
				}
				else {
					M_PosicionX += M_speed;
				}
			}

		}
		break;
	case Entidad::Oeste:
		// revisar si esta en el borde horizontal del juego
		if (M_MapCoordenadas.x > 0)
		{// para ver si esta colisionado con una pared 
			if (this->ptr_tablero->IsPared(M_MapCoordenadas.x - 1, M_MapCoordenadas.y))
			{
				if (M_EscalaHorizontal + M_PosicionX <= 0) {
					M_PosicionX = 0;
					M_MapCoordenadas.x--;
				}
				else {
					M_PosicionX -= M_speed;
				}
			}
		}
		break;
	default:
		fprintf(stderr, "Error PacMan en estado desconocido");
		break;
	}
}


void PacMan::Draw() {


	if(Frame < 6)
	{
		al_draw_scaled_bitmap(ptr_Bitmap, 36, 1, 13, 13,
			// determina donde sere dibuado en el mapa 
			(M_EscalaHorizontal * M_MapCoordenadas.x) + this->M_PosicionX,
			(M_EscalaVertical * M_MapCoordenadas.y) +  this->M_PosicionY,
			this->M_EscalaHorizontal,
			this->M_EscalaVertical,
			0);
	}
	else if(Frame < 11)
	{
		al_draw_scaled_bitmap(ptr_Bitmap, 4, 1, 13, 13,
			(M_EscalaHorizontal * M_MapCoordenadas.x) + this->M_PosicionX,
			(M_EscalaVertical * M_MapCoordenadas.y) + this->M_PosicionY,
			this->M_EscalaHorizontal,
			this->M_EscalaVertical,
			(dir == Entidad::Este) ? 0 : ALLEGRO_FLIP_HORIZONTAL);
	}
	else if (Frame < 16)
	{
		al_draw_scaled_bitmap(ptr_Bitmap, 20, 1, 13, 13,
			(M_EscalaHorizontal * M_MapCoordenadas.x) + this->M_PosicionX,
			(M_EscalaVertical * M_MapCoordenadas.y) + this->M_PosicionY,
			this->M_EscalaHorizontal,
			this->M_EscalaVertical,
			(dir == Entidad::Este) ? 0 : ALLEGRO_FLIP_HORIZONTAL);
	}

	(Frame == 15) ? Frame = 0 : Frame++;

}


void PacMan::SetLimites(short x, short y) {
	this->M_Limite.x = x - 1;
	this->M_Limite.y = y - 1;
}

void PacMan::setDirection(Direcciones dir) {
	this->dir = dir;
}

Coordenadas PacMan::getCondenadas() {
	return M_MapCoordenadas;
}