#include "MisFunciones.h"
// detiene el programa 
void Stop() {
	std::cin.ignore();
	std::cin.get();

}

// Imprime \n a la consola para tener mas 
// control sobre cuanto espacio ahi entre Lines. 
void ExtraLine(int x)
{
	for (int i = 0; i < x; ++i) 
	{
		std::cout << '\n';
	}

}
