#include "ListaEnlasadaDoble.h"



ListaEnlasadaDoble::ListaEnlasadaDoble()
{
}

ListaEnlasadaDoble::ListaEnlasadaDoble(int CantidadDeNodos)
{
	CrearListaEnlasadaDoble(CantidadDeNodos);
}


ListaEnlasadaDoble::~ListaEnlasadaDoble()
{
	BorrarListaEnlasadaDoble();
}

void ListaEnlasadaDoble::CrearListaEnlasadaDoble(int CantidadDeNodos)
{
	int PosicionDeNodo = 0;
	for(int i =0; i < CantidadDeNodos;++i)
	{
		if (i == 0)
		{
			this->NextNodo = new Nodo(i);
		}
		else
		{
			Nodo *Temp = new Nodo(i);
			this->LastNodo = Temp;
			PushDouble(Temp, i, PosicionDeNodo);
		}
		this->CantidadDeNodos++;
		PosicionDeNodo++;
	}

}

void ListaEnlasadaDoble::BorrarListaEnlasadaDoble()
{
	for (CantidadDeNodos; CantidadDeNodos > 0; --CantidadDeNodos)
	{
		if(CantidadDeNodos != 1)
		{
			this->NextNodo->PopHeap();
		}
		else {
			delete NextNodo;
		}
			
	}

}

void ListaEnlasadaDoble::PushBack(Nodo *OtroNodo)
{
	Nodo *Temp = this->NextNodo;
	this->NextNodo = OtroNodo;
	OtroNodo->NextNodo = Temp;
}

void ListaEnlasadaDoble::PopBack()
{
	Nodo *Temp = this->NextNodo->NextNodo;
	delete this->NextNodo->NextNodo;
	this->NextNodo = Temp;
}