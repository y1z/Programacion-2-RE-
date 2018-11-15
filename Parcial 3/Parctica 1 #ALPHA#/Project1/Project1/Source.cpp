#include <iostream>
#include <vector>
#include "MisFunciones.h"
#include "Arbol.h"


void Menu(Arbol &arbol);

void Sort(std::vector<Persona*> &Vec, int bajo, int alto);
int Particion(std::vector<Persona*> &vec, int bajo, int alto);
void PresentarOpciones();

int main() {

	Arbol arbol;

	bool IsPrellenarArbol = false;

	printf("hola ?desea que el arbol binario tenga todo el alphabeto ?\n");
	printf("0) no\n");
	printf("1) si\n");


	std::cin >> IsPrellenarArbol;


	if (IsPrellenarArbol) {
		printf("Ingresando alpabeto \n");

		std::vector<Persona*> Vec;

		 char PirmerCaracter[] = "L";

		for(int i =0; i < 15;++i)
		{
			Persona * tempPer = new Persona(PirmerCaracter, "test", 3, 3, 3);
			PirmerCaracter[0]++;
			Vec.emplace_back(tempPer);
		}

		char SegundoCaracter[] = "K";

		for (int i = 0; i > -11; --i)
		{
			Persona * tempPer = new Persona(SegundoCaracter, "test", 3, 3, 3);
			SegundoCaracter[0]--;
			Vec.emplace_back(tempPer);
		}
	
		Sort(Vec, 0, Vec.size() - 1);


		arbol.Sort(Vec,0,Vec.size() - 1);

		LineaExtra(4);

		arbol.ConvertirVector(Vec, 0, Vec.size() -1);
		LineaExtra(4);
		printf("El alphabeto fue ingresado \n");

	}

	Menu(arbol);

	Stop();

	return 0;
}

int Particion(std::vector<Persona*> &vec, int bajo, int alto)
{
	// este es una referencia a un puntero 
	Persona*& Pivote = vec[alto];

	int ElementosMenoresAlPivote = bajo - 1;

	for (int i = bajo; i < alto; ++i)
	{
		if (Pivote->CompararNombre(*vec[i]))
		{
			ElementosMenoresAlPivote++;
			if (i != ElementosMenoresAlPivote)
			{
				Persona* Temp = vec[i];
				vec[i] = vec[ElementosMenoresAlPivote];
				vec[ElementosMenoresAlPivote] = Temp;
			}
		}
	}
	Persona* Temp = Pivote;
	Pivote = vec[ElementosMenoresAlPivote + 1];
	vec[ElementosMenoresAlPivote + 1] = Temp;

	return ElementosMenoresAlPivote + 1;
}

void Sort(std::vector<Persona*> &Vec, int bajo, int alto) {
	if (bajo < alto)
	{
		int pivote = Particion(Vec, bajo, alto);

		Sort(Vec, bajo, pivote - 1);
		Sort(Vec, pivote + 1, alto);
	}

}


void Menu(Arbol &arbol)
{
	short opciones = -1;
	bool IsRuning = true;

	PresentarOpciones();
	printf("Si quiere ver todo lo que hacer solo ingresa cualquier numero menos los mencionados anteriormente \n");

	NodoX *tempNodo = nullptr;

	while(IsRuning)
	{
		std::string tempString;

		std::cin >> opciones;

		switch (opciones)
		{
		case(1):
			tempNodo = new NodoX();
			tempNodo->CrearPersona();
			arbol.Add(tempNodo);
			break;
		case(2):
			printf("?Cual valor desea Remover? \n respuesta aqui-->");
			std::cin >> tempString;
			arbol.Remove(tempString);
			break;
		case(3):
			printf("?Cual valor esta Buscando? \n respuesta aqui-->");
			std::cin >> tempString;
			arbol.Seach(tempString);
			break;
		case(4):
			arbol.Print();
			break;
		case(0):
			IsRuning = false;
			break;
		default:
			PresentarOpciones();
			break;
		}
	}

}

void PresentarOpciones()
{
	printf("hola puede hacer lo siguente con el arbol \n");
	printf("1 Add elementos \n");
	printf("2 remove elementos \n");
	printf("3 seach elementos \n");
	printf("4 print todos los elementos \n");
	printf("0 para terminar con el menu \n");

}