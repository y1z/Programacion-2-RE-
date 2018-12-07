#pragma once
#include "stdafx.h"
#include "Entidad.h"
#include "Tablero.h"
#include "Structs.h"


class PacMan :public Entidad
{
public:
	PacMan();
	// TODOS TERMINAR CONTRUCTOR 
	PacMan(ALLEGRO_BITMAP *, char, char, char);
	~PacMan();
public ://variables 
	// para saber donde esta en la matriz 
	Coordenadas M_MapCoordenadas;
	// saber donde esta en el mapa 
	Coordenadas M_Limite;

	Tablero *ptr_tablero = nullptr;

public : // metodos 
	void Move() override;
	void Draw();
	// hacer que solo puedeas moverte dentro de los 
	// confines del Laberinto 
	void SetLimites(short x, short y) ;

	void setDirection(Direcciones);

	Coordenadas getCondenadas();
private:

};

