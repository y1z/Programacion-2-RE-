#pragma once
#include"Vertice.h"
class Vertice;

class Arista
{
public:// constructor y destructor 
	Arista();
	Arista(Vertice&, Vertice&);
	~Arista();
public:// Variables 
	Vertice* ptr_Vert1 = nullptr;
	Vertice* ptr_Vert2 = nullptr;

public:// metodos 
	void setVertices(Vertice&, Vertice&);
	bool Comparar(Vertice*, Vertice&);
public: 
	bool operator==(Vertice&);
};

