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

int ListaDouble::BuscarValor(int Valor)
{
	 if(this->Valor == Valor)
	 {
		std::cout << "su valor si esta en la ListaEnlasada \n";
		return this->Valor;
	 }
    else if (this->next == nullptr) {
		std::cout << "El valor que buca no esta en la lista \n";
		return 0;
	}
	else {
		next->BuscarValor(Valor);
	}

}
