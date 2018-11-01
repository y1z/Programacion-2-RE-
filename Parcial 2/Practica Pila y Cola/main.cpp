#include <iostream>
#include <string>
#include "Stack.h"
#include "Cola.h"


void Stop() {
	std::cin.ignore();
	std::cin.get();
}

void Comenzar();

void Buscar(Nodo* ptr_Nodo);

void Menu(Nodo* ptr_Nodo);

void DibujarMenu();

int main() {


	Comenzar();
	return 0;
}

void Comenzar() 
{
	short Opciones;
	printf("Ingresa el tipo de lista a untilizar \n");
	printf("1 - Pila\n");
	printf("2 - Cola\n");
	printf("0 - Salir\n");
	std::cin >> Opciones;
	if (Opciones == 1)
	{
		Nodo* ptr_stack = new Stack;
		printf("\n\n\n\n\n\n\n");
		Menu(ptr_stack);
		delete ptr_stack;
	}
	else if (Opciones == 2)
	{
		Nodo* ptr_cola = new Cola;
		printf("\n\n\n\n\n\n\n");
		Menu(ptr_cola);
		delete ptr_cola;
	}

}


void Buscar(Nodo* ptr_Nodo)
{
	std::string tem;
	std::cout << "a quien quiere buscar \n ";
	std::cin >> tem;
	std::cout << " OK \n";
	ptr_Nodo->BuscarValor(tem);
}

void Menu(Nodo* ptr_Nodo)
{
	int Opciones = -1;
	bool Activo = true;
	printf("1- Agregar Persona \n");
	printf("2- Quitar  Persona \n");
	printf("3- Mostrar Lista   \n");
	printf("4- Buscar por Nombre\n");
	printf("5- Buscar por apellido\n");
	printf("0- sailr\n");
	printf("si desea ver esta lista de comando de nuevo \n");
	printf("solo precione cualquier numero que no este arriba \n");


	while (Activo)
	{
		std::cin >> Opciones;
		switch (Opciones)
		{
		case(1):
			ptr_Nodo->Push();
			break;
		case(2):
			ptr_Nodo->Pop();
			break;
		case(3):
			ptr_Nodo->PrintList();
			break;
		case(4):
			Buscar(ptr_Nodo);
			break;
		case(5):
			Buscar(ptr_Nodo);
			break;
		case(0):
			Activo = false;
			break;
		default:
			DibujarMenu();
			break;
		}
	}
}

void DibujarMenu() {
	printf("1- Agregar Persona \n");
	printf("2- Quitar  Persona \n");
	printf("3- Mostrar Lista   \n");
	printf("4- Buscar por Nombre\n");
	printf("5- Buscar por apellido\n");
	printf("0- sailr\n");
	printf("si desea ver esta lista de comando de nuevo \n");
	printf("solo precione cualquier numero que no este arriba \n");
}
