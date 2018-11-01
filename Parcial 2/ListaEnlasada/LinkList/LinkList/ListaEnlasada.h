#pragma once
#include "Nodo.h"
class ListaEnlasada :
	public Nodo
{
public:
	ListaEnlasada();
	ListaEnlasada(int CantidadDeNodos);
	virtual~ListaEnlasada();

	//inicializo esto como -1 para ver si saber 
	// si algo sail mal en el proceso de 
	// asignar posicion al linklist 
	int CantidadDeNodos = 0;

public:
	void CrearListaSingularEnlasada(int CantidadDeNodos);
private:
	void BorrarListaSingularEnlasada();

};

