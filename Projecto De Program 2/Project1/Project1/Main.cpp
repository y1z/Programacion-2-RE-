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


//void quickSort(int comienzo, int Final, std::vector<Name> &vec) 
//{
//	// esta varible tiene los tamaños de los string
//	// que voy a comparar(para que el sort no organize 
//	// nombre que son mas pequeños y grandes 
//	int SizeOfString = vec[comienzo].getSize();
//
//	// estas dos variable son para tiener la palabra 
//	// que sera el pivote y su ubicacion dentro del 
//	//vector 
//	std::string Pivote = "";
//	int IndicePivote = 0;
//
//	//Uso este valor para intercambiar strings
//	std::string Intercambio = "";
//
//	
//	// lo mismo que el pivote pero es para las palabras que 
//	// estan a la izquerda del pivote 
//	std::string NomberL = "";
//	int IndiceL = comienzo;
//	// lo mismo que el pivote pero es para las palabras que 
//	// estan a la derecha del pivote
//
//	std::string NomberR = "";
//	int IndiceR = Final;
//
//	// le asigno al pivote el valor del medio y la posion del valor 
//	Pivote = vec[(comienzo + Final) / 2].getValue();
//	IndicePivote = (comienzo + Final) / 2;
//
//	NomberL = vec[IndiceL].getValue();
//	NomberR = vec[IndiceR].getValue();
//
//	while (IndiceL <= IndiceR && vec[IndiceL].getSize() == vec[IndiceR].getSize())
//	{
//		/*intenta encontrar palabras cuyas primeras letra 
//		sean mayores a la primera letra del pivote 
//		*/
//		while (NomberL[0] < Pivote[0])
//		{
//			IndiceL++;
//			NomberL = vec[IndiceL].getValue();
//		}
//
//		/*intenta encontrar palabras cuyas primeras letra
//		sean menores a la primera letra del pivote
//		*/
//
//		while (NomberR[0] > Pivote[0])
//		{
//			IndiceR--;
//			NomberR = vec[IndiceR].getValue();
//		}
//	
//		if(IndiceL <= IndiceR && (Final - comienzo) > 1)
//		{
//			Intercambio = vec[IndiceL].getValue();
//			vec[IndiceL] = vec[IndiceR];
//			vec[IndiceR] = Intercambio;
//
//			IndiceL++;
//			IndiceR--;
//		}
//	
//	}
//
//	if (comienzo < IndiceR && (Final - comienzo) > 1)
//	{
//		quickSort(comienzo, IndiceR, vec);
//	}
//
//	if (IndiceL < Final && (Final - comienzo) > 1)
//	{
//		quickSort(IndiceL, Final, vec);
//	}
//
//
//}


void sort(std::vector<Name> &names) 
{
	// primero vamos a organizar los nombres por tamaño 

	// uso este vector para averiguar la variadad de 
	// tamaños de los nombres para luego separarlos 
	std::vector<int> Sizes;

	// lo doy un valor que es el tamaño de un nombre
	// para que se pueda hace un ciclo (no puedes 
	// hacer un loop con un vector de tamaño 0)
	Sizes.emplace_back(names[0].getSize());

	//uso este variable para determinar los lugare que fueron organizados  
	int LugarOrganizadoLongitud = 0; 
	// para encontra el valor mas chico 
	int ValorMasChico = 0;
	int LugarValorMasChico = 0;

	std::string NombreOriginal ="0";
	std::string NombreIntercambiado ="0";



	for (int i = 0; i < names.size(); ++i) {

		for (int j = 0; j < Sizes.size(); ++j)
		{
			// verifico si un tamaño es repetido 
			if(names[i].getSize() == Sizes[j])
			{
				break;
			}
			// si la condicion de arriba nunca es verdad significa 
			// que el valor en la iteracion no es repetido 
			else if (j == Sizes.size() -1 )
			{
				Sizes.emplace_back(names[i].getSize());
			}
		}
	}
	// uso este arreglo para saber donde comienza mis 
	// string de size x y donde terminan tambien 

	std::vector<int> LugarDeDiviciones;

	int CopiaDeSize = Sizes.size() - 1;

	while(Sizes.size() > 0)
	{
		// asigno el valor en el indice 0 para tener algo 
		// con que compara el resto del arreglo 
		ValorMasChico = Sizes[0];
		// esto es para saber el indice del ValorMasChico 
		// Lo inicialiso como 0 porque la Variable 'ValorMasChico'
		// por el moment esta ubicado ahi .
		LugarValorMasChico = 0;

		// voy por el arreglo para encontra el valor mas chico 
		for (int i = 0; i < Sizes.size(); ++i)
		{
			if (ValorMasChico > Sizes[i])
			{
				ValorMasChico = Sizes[i];
				LugarValorMasChico = i;
			}

		}
		// iguanlo 'j' a 'LugarOrganizadoLongitud' para no ver todo el arreglo 
		// cada interacion 
		for (int j = LugarOrganizadoLongitud; j < names.size(); ++j)
		{
			if(names[j].getSize() == ValorMasChico)
			{
				 /*Consigo la variable 'm_name' de los dos 'Name' porque voy a 
				 intercambiarlas de lugar y no puedo acceder a la variable 'm_name' 
				 desde un 'Name' a otro 'Name' 
				 */
				NombreOriginal = names[LugarOrganizadoLongitud].getValue();
				NombreIntercambiado = names[j].getValue();

				// intrecambio el nombre de su indice original 
				// a otro usando la variable de arriba.
				names[j] = NombreOriginal;
				names[LugarOrganizadoLongitud] = NombreIntercambiado;

				// ago esto porque el lugar donde puse 
				// el m_name deberia estar en el lugar 
				// correcto por lo tanto deberia 
				// ver que va en el indice siguente .
				++LugarOrganizadoLongitud;
			}
		
		}
		
		// uso esto para saber donde esta 

		LugarDeDiviciones.emplace_back(LugarOrganizadoLongitud);


		// ya borro el valor que representa el tamaño de los nombre
		// dado que ya estan organizados 
			Sizes.erase(Sizes.begin() + LugarValorMasChico);
		
	}

		
	for (int i = 0; i < CopiaDeSize ; ++i)
	{
		if(i == 0)
		AlphabetacalSort(0, LugarDeDiviciones[i], names);
		else {
			AlphabetacalSort(LugarDeDiviciones[i - 1], LugarDeDiviciones[i], names);
		}
		
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
	
	sort(names);


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