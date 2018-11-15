#pragma once
#include "stdafx.h"
class Entidad
{
public:
	Entidad();
	virtual ~Entidad();
public://Metodos 
	virtual void Move() = 0;
public:// variables 
	float M_PosicionX = 0;
	float M_PosicionY = 0;

	// esto dicta que cuadro de animacion usara 
	// la entidad 
	unsigned char Frame = 0;

	// TODO : hacer que estos enums controlen 
	// que direcion se mueve la entidad 
	enum class Direcciones
	{
		Norte,
		Sur,
		Este,
		Oeste
	};
};
