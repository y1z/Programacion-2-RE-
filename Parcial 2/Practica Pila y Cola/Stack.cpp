#include "Stack.h"

Stack::Stack()
{
}

Stack::Stack(int x)
{	
	AumentarElementos(x);
}

Stack::Stack(const char Name[], const char Apellido[], int day, int month, int year) {
	// los nodo contiene una clase persona 
	Nodo *Temp = new Nodo(Name, Apellido, day, month, year);

	//si no tiene elementos el stack 
	//usamos el primer Nodo del stack 
	NextNodo = Temp;
	Temp = nullptr;
	M_Elementos++;
}

Stack::~Stack()
{
	// borro todos los nodos 
	for (int i = 0; i < (M_Elementos - 1); ++i)
	{
		NextNodo->Pop();
	}
	delete NextNodo;
	if (ptr_Pull != nullptr) 
	{
		delete ptr_Pull;
		ptr_Pull = nullptr;
	}
}

void Stack::Push()
{
	// creo al nodo que contiene La Clase 
	// Persona

	Nodo* NodoAdicional = new Nodo;

	ptr_Head = NodoAdicional;
	/*Estod dos son para guardar los Nombre y 
	Apellido de la clase Persona */
	std::string Nombre;
	std::string Apellido;

	/*Son para los valores que determinan cuando nacio 
	 la persona en cuestion Y como ,los valores en 
	 cuestion representan dia ,meses y  años
	 sus valore no puede logicamente ser 0 	
	 dado que no existe dia o mes representado por 
	  0*/
	unsigned int Dia = 1;
	unsigned int Mes = 1;
	unsigned int Year = 2000;


	std::cout << "porfavor ingresa un Nombre ,Apellido y fecha de nacimiento\n" << "en el siguente formato dd/mm/yyyy ";
	std::cin >> Nombre;
	std::cin >> Apellido;
	std::cin >> Dia >> Mes >> Year;

	// El nodo contiene la clase persona 
	// uso este metodo para settiar los 
	//valore de la instancia 
	NodoAdicional->M_Valor.SetValor(Nombre.c_str(), Apellido.c_str(), Dia, Mes, Year);

	if (M_Elementos < 1) {
		NextNodo = NodoAdicional;
	}
	else {
		this->NextNodo->PushDouble(NodoAdicional);
	}
	// esto para saber cuantos elementos tengo 
	M_Elementos++;
}

// borro el elemento que esta al final del
// Stack .
void Stack::Pop() {
	if(M_Elementos > 1)
	{
		Nodo* ptr_temp;
		ptr_temp = ptr_Head;
		ptr_temp = ptr_temp->GetPrev();
		ptr_Head->PrevNodo = nullptr;
		ptr_temp->Pop();
		ptr_temp->NextNodo = nullptr;
		ptr_Head = ptr_temp;
	}
	else {
		delete ptr_Head;
		ptr_Head = nullptr;
	}

	M_Elementos--;
	//this->NextNodo->Pop();
}
// voy a quitar pero no borra un elemento 
// del Stack 
void Stack::pull(const std::string &Valor) {
	Nodo* ptr_Comparar = ptr_Head;

	if (ptr_Pull != nullptr) {
		delete ptr_Pull;
	}
	
	while(this->PrevNodo != nullptr)
	{
		if(ptr_Comparar->M_Valor == Valor)
		{
			Nodo* temp1 = ptr_Comparar;
			Nodo* temp2 = ptr_Comparar;

			//verifico que este nodo no este en el final 
			// o comienzo del stack
			if (ptr_Comparar->NextNodo != nullptr && ptr_Comparar->PrevNodo != nullptr)
			{// consigo los nodos ayacientes 
				temp1 = ptr_Comparar->NextNodo;
				temp2 = ptr_Comparar->PrevNodo;
				temp1->NextNodo = temp2;
				temp2->PrevNodo = temp1;

				ptr_Comparar->NextNodo = nullptr;
				ptr_Comparar->PrevNodo = nullptr;
				ptr_Pull = ptr_Comparar;
				ptr_Comparar = nullptr;
			}
			else if (ptr_Comparar->PrevNodo == nullptr) 
			{
				temp1 = ptr_Comparar->GetNext();
				temp1->PrevNodo = nullptr;
				ptr_Pull = ptr_Comparar;
				ptr_Comparar = nullptr;

			}
			else {
				temp1 = ptr_Comparar->GetPrev();
				temp1->NextNodo = nullptr;
				ptr_Pull = ptr_Comparar;
				ptr_Comparar = nullptr;
			}
		}
		else {
			ptr_Comparar = ptr_Comparar->GetPrev();
		}
	
	}

}

void Stack::BuscarValor() {
	// para saber que valor esta 
	// buscado el usario 
	std::string Valor;
	/*Este nodo se sera usado para
	ver si lo que */
	Nodo * ptr_temp = ptr_Head;
	Nodo *ptr_Copia = nullptr;
	// para cuando tengo el mismo nombre 
	// en mulpiles lugares 
	bool IsRepetido = false;
	// por si no encontro el nombre o apellido 
	// por ningun lugar en la lista 
	bool IsEncontrado = false;

	std::cout << "\nDame un nombre o apellido a buscar \n";
	std::cin >> Valor;

	for (int i = M_Elementos; i > 0; --i)
	{
		if(ptr_temp->M_Valor == Valor)
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
		ptr_Copia = ptr_temp;
		ptr_temp = ptr_temp->GetPrev();
	}

	if (IsEncontrado == false) {
		std::cout << "no Pudimos encontrar el [" << Valor << "] en la Pila \n";
	}
}

// solo llama la fucion push x cantidad 
// de veces 
void Stack::AumentarElementos(int x)
{
	for (int i = 0; i < x; ++i) {
		this->Push();
	}
}

void Stack::PrintList()
{
	if(M_Elementos > 0)
	{
		Nodo *tem = ptr_Head;
		for (int i = 0; i < M_Elementos; ++i)
		{
			tem->PrintValue();
			tem = tem->GetPrev();
		}
		tem = nullptr;
	}
	else{
		std::cout << "No hay elementos en la Pila \n";
	}

}

void Stack::BusquedaBinaria(const std::string &Valor)
{
	// uso punteros hacia los valores originales 
	// para consumir menos memoria 
	std::vector <std::string*> ArregloTemp;
	// para hacer espacio para tanto, para el nombre 
	// como el apellido 
	ArregloTemp.resize(M_Elementos * 2);
	Nodo* Temp = ptr_Head;

	for (int i = 0; i < M_Elementos; ++i) {
		// pongo los nombre y apellido en extremos opuestos 
		// del vector para no hacer el doble de ciclos 
		// metiendolos detro del vector 
		ArregloTemp[i] = Temp->M_Valor.getNombrePointer();
		ArregloTemp[(ArregloTemp.size() - 1) - i] = Temp->M_Valor.getApellidoPointer();
		//voy al nodo previo 
		Temp = Temp->GetPrev();
	}


}

void Stack::Sort(std::vector<std::string*> &vec) {


}