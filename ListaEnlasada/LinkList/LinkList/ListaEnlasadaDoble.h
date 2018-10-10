#pragma once
#include "ListaEnlasada.h"
class ListaEnlasadaDoble :
	public ListaEnlasada
{
public:
	ListaEnlasadaDoble();
	ListaEnlasadaDoble(int CantidadDeNodos);
	~ListaEnlasadaDoble();
public:
	Nodo * LastNodo = nullptr;
//	Nodo *NextNodo = nullptr;

public:
	void CrearListaEnlasadaDoble(int CantidadDeNodos);
	void PushBack(Nodo *OtroNodo);
	void PopBack();
public:
	void BorrarListaEnlasadaDoble();
};

