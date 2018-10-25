#include "Cola.h"



Cola::Cola()
{
}


Cola::~Cola()
{
}

void Cola::Push() 
{
	std::string Name, Apellido;
	int day, month, year;

	std::cout << "porfavor ingresa un Nombre ,Apellido y fecha de nacimiento\n" << "en el siguente formato dd/mm/yyyy ";
	std::cin >> Name;
	std::cin >> Apellido;
	std::cin >> day >> month >> year;

	Nodo* nuevoNodo = new Nodo(Name.c_str(),Apellido.c_str(),day,month,year);
	if (M_Elementos == 0)
	{
		ptr_FirstNodo = nuevoNodo;
	}
	else {
		this->ptr_FirstNodo->PushDouble(nuevoNodo);
	}


	M_Elementos++;
}

void Cola::Pop()
{
	Nodo* temp1 = ptr_FirstNodo;
	Nodo* temp2;
	ptr_FirstNodo = ptr_FirstNodo->GetNext();
	temp1->NextNodo = nullptr;
	temp2 = temp1;
	temp2->Pop();
	temp1 = nullptr;
	temp2 = nullptr;
}

void Cola::pull(const std::string &Valor) {

}

void Cola::CrearCola(int x) {

	for (int i = 0; i < x; ++i) {
		this->Push();
	}
}


void Cola::PrintList()
{
	ptr_FirstNodo->PrintList();
}

void Cola::BuscarValor(const std::string &Valor)
{

	// para cuando tengo el mismo nombre 
	// en mulpiles lugares 
	bool IsRepetido = false;

	bool IsEncontrado = false;
	// primero voy al Primer 
	// elemento de la cola 
	Nodo*Comparar = ptr_FirstNodo;
	Nodo *Copia = Comparar;
	for (int i = 0; i < M_Elementos; ++i)
	{
		if (Comparar->M_Valor == Valor)
		{
			if (IsRepetido == false) {
				std::cout << "Encontramos a '" << Valor << "' en el indice " << i;
				IsRepetido = true;
				IsEncontrado = true;
			}
			else
			{
				std::cout << " ," << i;
			}
		}
		// para consiguir el proximo nodo 
		Comparar = Comparar->GetNext();

		// para verificar que si cambio de nodo 
		if(Copia == Comparar)
		{
			if (IsEncontrado == false)
			{
				std::cout << "no Encontramos a " << Valor << " en la lista ";
			}
			break;
		}
		Copia = Comparar;
	}

}
