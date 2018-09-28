#include "Sort.h"
#include "MisFunciones.h"

int main() {
	int usuarioNumero = 0;
	std::cout << "Dame un Numero positivo \n";
	std::cin >> usuarioNumero;

	int *Arrey = (int *)calloc(usuarioNumero, sizeof(int));

	std::cout << "\n Antes \n";

	srand(time(0));

	// asignando valores aliatorios 
	for (int i = 0; i < usuarioNumero; i++) {
		Arrey[i] = rand();

	}
	std::cout << "\n Antes \n";

	for (int i = 0; i < usuarioNumero; i++) {
		std::cout << '[' << Arrey[i] << "] ";

	}

	ExtraLine(2);

	InsertionSort(Arrey, usuarioNumero);
	std::cout << "Despues\n";

	for (int i = 0; i < usuarioNumero; i++) {
		std::cout << '[' << Arrey[i] << "] ";

	}



	free(Arrey);
	Arrey = NULL;

	Stop();
	return 0;
}