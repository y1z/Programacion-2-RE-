#include "Arbol.h"

Arbol::Arbol()
{
}

// borra todos los nodos 
Arbol::~Arbol()
{
	Raiz->PopAll();
	Raiz = nullptr;
}

// crear un nuevo nodo 
// para agregralo 
void Arbol::Add() //TODO remove it
{
	if(Raiz != nullptr)
	{
		NodoX *ptr_NuevoNodo = new NodoX();
		ptr_NuevoNodo->CrearPersona();
		Raiz->Push(ptr_NuevoNodo);
	}
	else {
		NodoX *ptr_NuevoNodo = new NodoX();
		ptr_NuevoNodo->CrearPersona();
		Raiz = ptr_NuevoNodo;
	}

}

void Arbol::Add(NodoX *ptr_NuevoNodo) {

	if (Raiz != nullptr)
	{
		Raiz->Push(ptr_NuevoNodo);
	}
	else {
		Raiz = ptr_NuevoNodo;
	}
}
/*
TODO not to ask for user input in the tree
*/
//void Arbol::Remove() {
//	if (Raiz != nullptr) {
//		Raiz->Pop();
//	}
//	else {
//		std::cout << "No Existe nodo para quitar";
//	}
//}


void Arbol::Remove(std::string &Remover)
{
	if (Raiz != nullptr) {
		Raiz->Pop(Remover);
	}
	else {
		std::cout << "No Existe nodo para quitar";
	}

}


bool Arbol::Seach(std::string &Buscar)
{
	if (Raiz != nullptr) {
		bool IsEncontrado = false;
		IsEncontrado = Raiz->Seach(Buscar.c_str());
		if(IsEncontrado == false)
		{
			std::cout << "\n el idividuo que esta buscando [" << Buscar << "] no esta en el arbol ";
		}
		
		return IsEncontrado;
	}
	else {
		std::cout << "No existe nodo para buscar";
	}


}

void Arbol::Print()
{
	if(Raiz != nullptr)
	Raiz->PrintAll();
	else {
		std::cout << "No Existe nodo Printair";
	}
}

void Arbol::Sort(std::vector<Persona*> &Vec,int bajo, int alto) {
	if (bajo < alto)
	{
		int pivote = Particion(Vec, bajo, alto);

		Sort(Vec, bajo, pivote - 1);
		Sort(Vec, pivote + 1, alto);
	}

}


int Arbol::Particion(std::vector<Persona*> &vec, int bajo, int alto)
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

void Arbol::ConvertirVector(std::vector<Persona*> &Vec, int bajo, int alto)
{
	// es extremada mente importante que 
	// esta funcion siga hasta que bajo supere 
	// a alto 
	if (bajo <= alto) {
		// esto dicide el medio del arreglo y 
		// tambien los subarreglos 
		int Pivote = (bajo + alto) / 2;
		
		NodoX * nuevo_nodo = new NodoX();
		//hacemos que nuestra persona sea igual a 
		// persona en el arreglo (copa las caracteristica) 
		nuevo_nodo->M_Persona = *Vec[Pivote];
		// agregamos el nuevo nodo a la raiz 
		Add(nuevo_nodo);

		// esto divide el arreglo en subarreglos 
		ConvertirVector(Vec, bajo, Pivote - 1);
		ConvertirVector(Vec, Pivote + 1, alto);

	}
}