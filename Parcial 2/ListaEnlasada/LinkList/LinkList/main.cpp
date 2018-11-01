#include <iostream>
#include "ListaEnlasada.h"
#include "ListaEnlasadaDoble.h"

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

int main() {
	ListaEnlasadaDoble LS(6);
	LS.PrintList();

	Stop();
	return 0;
}