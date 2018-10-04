#include <iostream>
#include "ListaEnlasada.h"
#include "ListaDouble.h"

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

int main() {
	//ListaEnlasada L1(1);
	//ListaEnlasada L2(2);
	//ListaEnlasada L3(3);
	//ListaEnlasada L4(4);
	//ListaEnlasada L5(5);

	ListaDouble LD1(1);
	ListaDouble LD2(2);
	ListaDouble LD3(3);
	ListaDouble LD4(4);

	LD1.EnlasarDouble(LD2);
	LD2.EnlasarDouble(LD3);
	LD3.EnlasarDouble(LD4);
	LD1.BuscarValor(4);
	Stop();

	return 0;
}