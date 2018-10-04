#include "ListaDouble.h"



ListaDouble::ListaDouble()
{
}

ListaDouble::ListaDouble(int Valor) 
{
	this->Valor = Valor;
}

ListaDouble::~ListaDouble()
{
}

void ListaDouble::EnlasarDouble(ListaDouble &ListaDoble)
{
	this->next = &ListaDoble;
	ListaDoble.last = this;
}


