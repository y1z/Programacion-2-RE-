#include <iostream>
#include <string>
#include "Stack.h"
#include "Cola.h"

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

// solo imprime el '\n' x cantidad de veces 
//para hacer el efecto de un Clear screen
void SemiClearScreen(int x = 40)
{
	for (int i = 0; i < x; ++i) {
		printf("\n");
	}
}

void Comenzar();

void Menu(List* ptr_list);

void DibujarMenu();

int main() {
	Comenzar();
	Stop();
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
		List* ptr_stack = new Stack;
		printf("\n\n\n\n\n\n\n");
		Menu(ptr_stack);
		delete ptr_stack;
	}
	else if (Opciones == 2)
	{
		List* ptr_cola = new Cola;
		printf("\n\n\n\n\n\n\n");
		Menu(ptr_cola);
		delete ptr_cola;
	}


}

void Menu(List* ptr_list)
{
	SemiClearScreen();
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
			ptr_list->Push();
			printf("\n-->puede seleciona otro comando<-- \n");
			break;
		case(2):
			ptr_list->Pop();
			printf("\n-->puede seleciona otro comando<-- \n");
			break;
		case(3):
			ptr_list->PrintList();
			printf("\n-->puede seleciona otro comando<-- \n");
			break;
		case(4):
			ptr_list->BusquedaBinariaNombre();
			printf("\n-->puede seleciona otro comando<-- \n");
			break;
		case(5):
			ptr_list->BusquedaBinariaApellido();
			printf("\n-->puede seleciona otro comando<-- \n");
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
