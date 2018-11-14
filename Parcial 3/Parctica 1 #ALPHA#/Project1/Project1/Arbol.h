#pragma once
#include "NodoX.h"
class Arbol
{
public://Variables
	NodoX* Raiz = nullptr;
public://Metodos 
	void Add();
	void Remove();
	bool Seach();
	void Print();

public:
	Arbol();
	~Arbol();
};

