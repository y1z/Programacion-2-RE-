#include <iostream>
#include "ListaEnlasada.h"
#include "ListaEnlasadaDoble.h"

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

int main() {
	ListaEnlasadaDoble *LDp = new ListaEnlasadaDoble(5);
	Nodo *Np1 = new Nodo(789);
	LDp->PushBack(Np1);

	LDp->PrintList();
	
	
	delete LDp;
	Stop();
	return 0;
}