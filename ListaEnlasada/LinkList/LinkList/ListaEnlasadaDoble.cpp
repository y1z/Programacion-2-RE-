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
			this->NextNodo->M_Posicion = i;
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

void ListaEnlasadaDoble::PushFront(Nodo *OtroNodo)
{
	//crear un puntero temporaral al nodo actual
	Nodo *Temp = this->NextNodo;

	//cambiar el noto al que apunto 
	this->NextNodo = OtroNodo;
	/*dado que estoy insertand una nueva */
	OtroNodo->M_Posicion = 0;
	OtroNodo->NextNodo = Temp;
}

void ListaEnlasadaDoble::PopFront()
{
	Nodo *Temp = this->NextNodo->NextNodo;
	delete this->NextNodo;
	this->NextNodo = Temp;
}

/*todo lo que hace este metodo es 
imprimir los valore que tiene los 
nodos , por que Antes me imprimia 
un zero demas 
*/
void ListaEnlasadaDoble::PrintList()  {
	this->NextNodo->PrintList();
}

/*todo lo que hace este metodo es
Poner un nodo dentro del linklist
*/
void ListaEnlasadaDoble::InsertarNodoHeap(Nodo *OtroNodo, int Posicion)
{
	if (CantidadDeNodos > 0) {
		this->NextNodo->InsertarNodoHeap(OtroNodo, Posicion);
	}


}