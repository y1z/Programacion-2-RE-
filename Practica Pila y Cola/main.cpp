#include <iostream>
#include <string>
#include "Stack.h"
#include "Cola.h"


void Stop() {
	std::cin.ignore();
	std::cin.get();
}

void Comenzar();

void Buscar(Stack* ptr_stack);

void Menu(Stack* ptr_stack);

void Buscar(Cola* ptr_Cola);

void Menu(Cola* ptr_Cola);

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
		Stack* ptr_stack = new Stack;
		printf("\n\n\n\n\n\n\n");
		Menu(ptr_stack);
		delete ptr_stack;
	}
	else if (Opciones == 2)
	{
		Cola* ptr_cola = new Cola;
		printf("\n\n\n\n\n\n\n");
		Menu(ptr_cola);
		delete ptr_cola;
	}

}


void Buscar(Stack* ptr_stack)
{
	std::string tem;
	std::cout << "a quien quiere buscar \n ";
	std::cin >> tem;
	std::cout << " OK \n";
	ptr_stack->BuscarValor(tem);

}

void Menu(Stack* ptr_stack)
{
	int Opciones = -1;
	printf("1- Agregar Persona \n");
	printf("2- Quitar  Persona \n");
	printf("3- Mostrar Lista   \n");
	printf("4- Buscar por Nombre\n");
	printf("5- Buscar por apellido\n");
	printf("0- sailr\n");
	printf("si desea ver esta lista de comando de nuevo \n");
	printf("solo precione cualquier numero que no este arriba \n");

		
	while (Opciones != 0) {
		std::cin >> Opciones;

		switch (Opciones)
		{
		case(1):
			ptr_stack->Push();
			break;
		case(2):
			ptr_stack->Pop();
			break;
		case(3):
			ptr_stack->PrintList();
			break;
		case(4):
			Buscar(ptr_stack);
			break;
		case(5):
			Buscar(ptr_stack);
			break;
		default:
			DibujarMenu();
			break;
		}
	



	}


}

void Buscar(Cola* ptr_stack)
{
	std::string tem;
	std::cout << "A quien desea buscar ";
	std::cin >> tem;
	std::cout << " OK ";
	ptr_stack->BuscarValor(tem);
	Stop();
	std::cout << "----------";

}

void Menu(Cola* ptr_cola)
{
	int Opciones = -1;
	printf("1- Agregar Persona \n");
	printf("2- Quitar  Persona \n");
	printf("3- Mostrar Lista   \n");
	printf("4- Buscar por Nombre\n");
	printf("5- Buscar por apellido\n");
	printf("0- sailr\n");
	printf("si desea ver esta lista de comando de nuevo \n");
	printf("solo precione cualquier numero que no este arriba \n");


	while (Opciones != 0)
	{
		std::cin >> Opciones;
		switch (Opciones)
		{
		case(1):
			ptr_cola->Push();
			break;
		case(2):
			ptr_cola->Pop();
			break;
		case(3):
			ptr_cola->PrintList();
			break;
		case(4):
			Buscar(ptr_cola);
			break;
		case(5):
			Buscar(ptr_cola);
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
