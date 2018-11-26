#pragma once
#include "stdafx.h"
#include"Vertice.h"
#include "Arista.h"
class Grafo
{
public:
	Grafo();
	~Grafo();
public:// Variables
	std::vector<Vertice> M_Vertices;
	std::vector<Arista> M_Aristas;

public:// metodos 
	void GeneralGrafo(std::vector<std::vector<char>>&);
	bool EsAdyaciente(Vertice&, Vertice&);
private:
	bool EsConnecionExistente(Vertice&, Vertice&);
	void EnlasarGrafo();
};

