#include "ListaEnlasada.h"

ListaEnlasada::ListaEnlasada()
{
}

ListaEnlasada::ListaEnlasada(int CantidadDeNodos) 
{
	CrearListaSingularEnlasada(CantidadDeNodos);
}

ListaEnlasada::~ListaEnlasada()
{
	if(CantidadDeNodos != 0){
		BorrarListaSingularEnlasada();
	}

}


void ListaEnlasada::CrearListaSingularEnlasada(int CantidadDeNodos)
{
	for (int i = 0; i < CantidadDeNodos; ++i)
	{
		///no uso el oprador ternario por que por alguna razon 
		///no se deja usar en esta enstancia 
		 //i == 0 ? this->NextNodo = n : NextNodo->Push(n);
		this->CantidadDeNodos++;

		if (i == 0)
		{
			this->NextNodo = new Nodo(i);
			this->NextNodo->M_Posicion = i;
		}
		else {
			Nodo *NuevoNodo = new Nodo(i);
			this->NextNodo->Push(NuevoNodo,i,this->CantidadDeNodos);
		}
	
	}
	
}

void ListaEnlasada::BorrarListaSingularEnlasada()
{
	for (CantidadDeNodos ; CantidadDeNodos > 0; --CantidadDeNodos)
	{
		(CantidadDeNodos != 1) ? this->NextNodo->PopHeap() : delete NextNodo;
	}

}