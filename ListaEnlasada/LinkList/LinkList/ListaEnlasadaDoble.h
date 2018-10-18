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
	void PushFront(Nodo *OtroNodo);
	void PopFront();

	void PrintList()override;
	void InsertarNodoHeap(Nodo *OtroNodo, int Posicion)override;
public:
	void BorrarListaEnlasadaDoble();
};

