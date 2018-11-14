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
void Arbol::Add()
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

void Arbol::Remove() {
	if (Raiz != nullptr) {
		Raiz->Pop();
	}
	else {
		std::cout << "No Existe nodo para quitar";
	}
}

bool Arbol::Seach() {
	std::string ValorDeBusqueda;
	bool IsEncontrado = false;

	printf("Igresa lo que estas buscando \n aqui -->");
	std::cin >> ValorDeBusqueda;

	// si encuetra el valor me da verdad si no
	// me da falso 
	IsEncontrado = Raiz->Seach(ValorDeBusqueda.c_str());

	return IsEncontrado;
}

void Arbol::Print()
{
	Raiz->PrintAll();
}

void Arbol::Sort(std::vector<Persona*> &Vec,int bajo, int alto) {
	if (bajo < alto)
	{
		int pivote = Particion(Vec, bajo, alto);

		Sort(Vec, bajo, pivote - 1);
		Sort(Vec, pivote + 1, alto);
	}

}

void Arbol::CopiarVector(std::vector<Persona*> &Vec) {
	M_Personas = Vec;
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

		// esto divide el arreglo en suarreglos 
		ConvertirVector(Vec, bajo, Pivote - 1);
		ConvertirVector(Vec, Pivote + 1, alto);

	}
}