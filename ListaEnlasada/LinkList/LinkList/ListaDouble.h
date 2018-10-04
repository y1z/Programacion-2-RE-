#pragma once
#include "ListaEnlasada.h"

class ListaDouble :public ListaEnlasada
{
	//contructores y destructor 
public:
	ListaDouble();
	ListaDouble(int Valor);
	 ~ListaDouble();
public:
	ListaDouble * next;
	ListaDouble * last;
public:
	void EnlasarDouble(ListaDouble &ListaDoble);

};

