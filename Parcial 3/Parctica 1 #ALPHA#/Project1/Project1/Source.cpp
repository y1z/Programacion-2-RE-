#include <iostream>
#include "NodoX.h"

int main() {

	NodoX * ptr_nodo = new NodoX("D", "tets", 3, 3, 3);

	for (int i = 0; i < 4; ++i) {
		NodoX *ptr_addcional = new NodoX();
		ptr_addcional->CrearPersona();
		ptr_nodo->Push(ptr_addcional);
	}


	ptr_nodo->Pop();

	
	ptr_nodo->PopAll();
	ptr_nodo = nullptr;

	return 0;
}