#include <iostream>
#include <chrono>
#include "Name.hpp"
#include "RWFile.hpp"

void printNamesToConsole(std::vector<Name> &names)
{
	for (int i = 0; i < names.size(); ++i)
	{
		std::cout << names[i] << '\n';
	}
}
//esto es un sort borbuja
void AlphabetacalSort(int comienzo, int Final, std::vector<Name> &vec)
{
	std::string NombreActual = "0";
	std::string NombreComparar = "0";
	// uso esta variable para determinar si voy a mover el nombre que
	// NombreActual al lugar de NOmbreComparar .
	bool MoverNombre = false;

	for(int j = comienzo; j <Final; ++j)
	{

		for(int i = comienzo; i < Final; ++i )
		{
			NombreActual = vec[i].getValue();
			NombreComparar = vec[i + 1].getValue();

			// comparo las primeras letras de los nombres
			// y largo de los nombres para determinar si
			// debo moverlas o no
			if (NombreActual[0] > NombreComparar[0] && NombreActual.size() == NombreComparar.size())
			{
				MoverNombre = true;
			}

			if (MoverNombre == true)
		    {
			   vec[i] = NombreComparar;
			   vec[i + 1] = NombreActual;

			   MoverNombre = false;
		    }

		}

	}

}


int Particionar(int bajo, int alto, std::vector<Name> &names)
{
	// la razon de porque el pivote es una referencia es para
	// tener la habilida de alterar el arreglo
	Name &Pivote = names[alto];
	// esta variable no dice cuantos elementos son
	// menores que el valor del Pivote
	int Contador = bajo - 1;

	for (int i = bajo; i < alto; ++i)
	{
		if (names[i] < Pivote)
		{
			++Contador;
			// la razon para este if es para segurarnos que solo
			// los valores que necesitan intercambiarse se
			// intercambian
			if (i != Contador) {

			   std::string Intercambio = names[i].getValue();
				names[i] = names[Contador];
				names[Contador] = Intercambio;

			}
		}
	}

	std::string Intercambio = Pivote.getValue();
	Pivote = names[Contador + 1];
	names[Contador + 1] = Intercambio;

	return Contador + 1;
}

void sortMejorado(int bajo , int alto , std::vector<Name> &names)
{
	if( bajo < alto )
	{
		int pivote = Particionar(bajo, alto, names);

		sortMejorado(bajo, pivote - 1, names);
		sortMejorado(pivote + 1, alto, names);
	}
}


int main()
{
	std::cout << "::::\tStart of process\n";
	const char *inputFile = "RandomNames.txt";
	const char *outputFile = "SortedNames.txt";

	std::vector<Name> names;
	readNamesFromFile(inputFile, names);

	//Printing names to console
	printNamesToConsole(names);

	auto begin = std::chrono::high_resolution_clock::now();

	//Sort by length and alphabetically
	//TODO

	sortMejorado(0, names.size() - 1, names);


	auto end = std::chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

	std::cout << "::::\tElapsed time: " << ms << " ms\n";

	//Printing sorted names

	printNamesToConsole(names);

	writeNamesToFile(outputFile, names);

	std::cout << "::::\tEnd of process\n";
	std::cin.ignore();
	std::cin.get();
}
