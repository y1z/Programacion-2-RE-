#include "ListaEnlasada.h"
ListaEnlasada::ListaEnlasada()
{}

ListaEnlasada::ListaEnlasada(int Valor)
{
	// este constructor es para que la lista tenga un 
	// valor 
	this->Valor = Valor;
}

ListaEnlasada::~ListaEnlasada()
{

}

// para enlasar el proximo nodo 
void ListaEnlasada::EnlasarNext(ListaEnlasada &NextLink) {
	if (this->next == nullptr)
	{
		this->next = &NextLink;
		std::cout << "Enlasada \n";
	}
	else {
		std::cout << "este nodo ya esta enlasado con otro \n";
	}
}

// demuestra el valor del nodo actual  
void ListaEnlasada::PrintValor() {
	std::cout << "el valor de este nodo [" << Valor << ']';
}

// esta funcion buscar un valor por todos los nodos 
// interconectados 
int ListaEnlasada::BuscarValor(int ValorBuscar) {

	if (this->Valor == ValorBuscar)
	{
		std::cout << "su valor si esta en la ListaEnlasada \n";
		return this->Valor;
	}
	else if (this->next == nullptr) {
		std::cout << "El valor que busca no esta en la lista \n";
		return 0;
	}
	else {
		next->BuscarValor(ValorBuscar);

	}
}

// este metodo quita el ultimo elemento de la 
// lista 
void ListaEnlasada::Pop() {
	if(next->next == nullptr)
	{
		next->next->~ListaEnlasada();
		next = nullptr;
		std::cout << "se hizo el pop \n";
	}
	else {
		next->Pop();
	}
}

void ListaEnlasada::Push(ListaEnlasada &Nodo) {
	if(this->next == nullptr)
	{
		this->next = &Nodo;
	}
	else {
		next->Push(Nodo);
	}

}

// este operador hace lo mismo que el metodo 
// [EnlasarNext]
void ListaEnlasada::operator>>(ListaEnlasada &Nodo)
{
	if (this->next == nullptr) {
		this->next = &Nodo;
		std::cout << "Enlasada \n";
	}
	else {
		std::cout << "este nodo ya esta enlasado con otro \n";
	}

}