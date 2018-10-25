#include "Nodo.h"

Nodo::Nodo()
{
}

Nodo::Nodo(std::string &Name, std::string &Apelledo, int day , int month, int year) 
{
	this->M_Valor.SetValor(Name.c_str(), Apelledo.c_str(), day, month, year);
}

Nodo::Nodo(const char Name[], const char Apellido[], int day, int month, int year)
{
	this->M_Valor.SetValor(Name, Apellido, day, month, year);
}

Nodo::~Nodo()
{
}

void Nodo::Enlasar(Nodo * OtroNodo)
{
	this->NextNodo = OtroNodo;
}

void Nodo::Enlasar(Nodo &OtroNodo)
{
	this->NextNodo = &OtroNodo;
}

void Nodo::EnlasarDouble(Nodo * OtroNodo)
{
	this->NextNodo = OtroNodo;
	OtroNodo->PrevNodo = this;
}

void Nodo::EnlasarDouble(Nodo &OtroNodo)
{
	this->NextNodo = &OtroNodo;
	OtroNodo.PrevNodo = this;
}


void Nodo::Push(Nodo * OtroNodo)
{
	if(this->NextNodo == nullptr)
	{
		this->NextNodo = OtroNodo;
	}
	else
	{
		NextNodo->Push(OtroNodo);
	}
}


void Nodo::Push(Nodo &OtroNodo)
{
	if (this->NextNodo == nullptr)
	{
		NextNodo = &OtroNodo;
	}
	else
	{
		NextNodo->Push(OtroNodo);
	}
}


void Nodo::Push(Nodo * OtroNodo, Persona &Valor, int &Posicion)
{
	if (this->NextNodo == nullptr)
	{
		NextNodo = OtroNodo;
		NextNodo->M_Valor = Valor;
		NextNodo->M_Posicion = Posicion;
		NextNodo->M_Valor;
	}
	else
	{
		NextNodo->Push(OtroNodo, Valor, Posicion);
	}

}

void Nodo::Push()
{
	Nodo *NodoVacio = new Nodo;
	Nodo* tem = this;
	Nodo* Copia = tem;
	while(NextNodo != nullptr )
	{
		tem = tem->GetNext();
		if (Copia == tem) {
			tem->NextNodo = NodoVacio;
			break;
		}
	}

}

void Nodo::PushDouble(Nodo * OtroNodo)
{
	if (this->NextNodo == nullptr)
	{
		this->EnlasarDouble(OtroNodo);
	}
	else
	{
		NextNodo->PushDouble(OtroNodo);
	}

}

void Nodo::PushDouble(Nodo * OtroNodo, Persona &Valor, int &Posicion)
{
	if (this->NextNodo== nullptr)
	{
		NextNodo->EnlasarDouble(OtroNodo);
		NextNodo->M_Posicion = Posicion;
		NextNodo->M_Valor = Valor;
	}
	else
	{
		NextNodo->PushDouble(OtroNodo, Valor, Posicion);
	}
}

void Nodo::Pop()
{
	if (this->NextNodo == nullptr)
	{
		// para la lista doublemente enlasada
		if(this->PrevNodo != nullptr)
		{
			this->PrevNodo = nullptr;
		}

		delete NextNodo;
		this->NextNodo = nullptr;
	}
	else
	{
		NextNodo->Pop();
	}

}

void Nodo::PrintValue()
{
	M_Valor.Print();
}


void Nodo::PrintList()
{

	M_Valor.Print();
	std::cout << "\n";
	if(this->NextNodo == nullptr)
	{
		std::cout << " Fin Del list \n";
	}
	else
	{
		NextNodo->PrintList();
	}
}

void Nodo::BuscarValor(const std::string &Valor)
{
	if(this->M_Valor == Valor)
	{
		std::cout << "su valor si esta en uno de los Nodos \n";
	}
	else if (this->NextNodo == nullptr)
	{
		std::cout << "su valor No este en ninguno de los Nodos \n";
	}
	else {
		this->NextNodo->BuscarValor(Valor);
	}
}

void Nodo::SetValor(Persona &Valor)
{
	this->M_Valor = Valor;
}

void Nodo::InsertarNodoHeap(Nodo *OtroNodo,int Posicion)
{
	//verifico si el proximo nodo esta en la posicion
	// donde quiero replazarlo 
	if(this->NextNodo->M_Posicion == Posicion)
	{
		// para Nodo dobleMenteElasados 
		if (this->NextNodo!= nullptr && this->NextNodo->PrevNodo != nullptr)
		{
			OtroNodo->NextNodo = this->NextNodo->NextNodo;
			OtroNodo->PrevNodo = this->PrevNodo;
			delete this->NextNodo->NextNodo;
			this->NextNodo = OtroNodo;
			OtroNodo = this->NextNodo;

		}
		// para Nodos Singularmente Enlasados 
		else if(this->NextNodo != nullptr)
		{
			OtroNodo->NextNodo = this->NextNodo->NextNodo;
			delete this->NextNodo;
			this->NextNodo = OtroNodo;
		}
	}
	else if(NextNodo != nullptr)
	{
		NextNodo->InsertarNodoHeap(OtroNodo,  Posicion);
	}
}

Nodo* Nodo::GetNext() {
	if (this->NextNodo != nullptr) {
		return this->NextNodo;
	}
	else {
		return this;
	}

}

Nodo* Nodo::GetPrev() {
	if (this->PrevNodo != nullptr)
	{
		return this->PrevNodo;
	}
	else {
		return this;
	}

}


void Nodo::operator=(Nodo &OtroNodo)
{
	this->NextNodo = &OtroNodo;
}

void Nodo::operator=(Nodo *OtroNodo)
{
	this->NextNodo = OtroNodo;
}