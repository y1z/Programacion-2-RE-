#pragma once
#include "stdafx.h"
class Entidad
{
public:
	Entidad();
	virtual ~Entidad();
public://Metodos 
	virtual void Move() = 0;
	virtual void SetLimites(short x, short y) = 0;
	virtual void getEscala(ALLEGRO_DISPLAY *,char Anchura,char Altura);
public:// variables 
	// determina donde esta ubicado el objeto 
	float M_PosicionX = 0;
	float M_PosicionY = 0;

	// determinara el tamaño del objeto en el 
	// momento que lo dibujamos . 
	float M_EscalaHorizontal = 1;
	float M_EscalaVertical = 1;

	// determina a que velocidad ira nuestro objeto 
	float M_speed = 4.0f;

	//esta Variable determina que es lo mas lejos 
	// que puede ir nuestro objeto 

	// un puntero al la image que va a 
	// representar nuestro objeto 
	ALLEGRO_BITMAP * ptr_Bitmap = NULL;

	// esto dicta que cuadro de animacion usara 
	// la entidad 
	unsigned char Frame = 0;

	char M_Scale = 0;

	// TODO : hacer que estos enums controlen 
	// que direcion se mueve la entidad 
	enum Direcciones
	{
		Norte,
		Sur,
		Este,
		Oeste
	};

	Direcciones dir = Este;
};
