#pragma once
#include "stdafx.h"
#include "Entidad.h"
#include "Structs.h"
#include "Vertice.h"
#include "Tablero.h"
#include "Grafo.h"

class PacMan;

class Fantasma : public Entidad
{
public:
	Fantasma();
	~Fantasma();
public:
	void Move() override;
	void SetLimites(short x, short y) override;
	void Darw();
	void IniciarFantasma(char, short ,short);
	void Conportamiento(Grafo&, Vertice&);

public:
	bool EstaMoviendo = false;
	std::vector<Vertice> M_Camino;
//
	Coordenadas M_Limite;
	// para el bitmap 
	DatosBitMap M_datos;
	Vertice M_PosActual;
	// sera nuestro metodos de busqueda 
	std::vector<Vertice>(*MetodosBusqueda)(Grafo&grafo, Vertice &PuntoEntrada, Vertice &Destino);

	Tablero *ptr_tablero = nullptr;
};

