#pragma once

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
//	Vertice* getVertice();
public: 
	bool operator==(Vertice&);
	bool operator==(Vertice);
};

