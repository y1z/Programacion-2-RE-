#include "Nodo.h"

Nodo::Nodo()
{
}

Nodo::Nodo(int Valor) 
	:M_Valor(Valor)
{}

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


void Nodo::Push(Nodo * OtroNodo, int &Valor, int &Posicion)
{
	if (this->NextNodo == nullptr)
	{
		NextNodo = OtroNodo;
		NextNodo->M_Valor = Valor;
		NextNodo->M_Posicion = Posicion;
	}
	else
	{
		NextNodo->Push(OtroNodo, Valor, Posicion);
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

void Nodo::PushDouble(Nodo * OtroNodo, int &Valor, int &Posicion)
{
	if (this->NextNodo->NextNodo == nullptr)
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

void Nodo::PopStack()
{
	if(NextNodo->NextNodo == nullptr)
	{
		NextNodo = nullptr;
	}
	else
	{
		NextNodo->PopStack();
	}
	/// ma Dia error cuando uso  el codigo de abajo 
	//(NextNodo->NextNodo == nullptr) ? (NextNodo = nullptr) : (NextNodo->PopStack());
}

void Nodo::PopHeap()
{
	if(NextNodo->NextNodo == nullptr)
	{
		// para la lista doublemente enlasada
		if(NextNodo->PrevNodo != nullptr)
		{
			NextNodo->PrevNodo = nullptr;
		}

		delete NextNodo;
		NextNodo = nullptr;
	}
	else
	{
		NextNodo->PopHeap();
	}

}

void Nodo::PrintValue()
{
	std::cout << M_Valor << '\n';
}


void Nodo::PrintList()
{
	std::cout << '[' << M_Valor << "] -> ";
	if(this->NextNodo == nullptr)
	{
		std::cout << " Fin De list \n";
	}
	else
	{
		NextNodo->PrintList();
	}
}

void Nodo::BuscarValor(const int &Valor)
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

void Nodo::SetValor(int Valor)
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
		if (this->NextNodo->NextNodo != nullptr && this->NextNodo->PrevNodo != nullptr)
		{
			OtroNodo->NextNodo = this->NextNodo->NextNodo;
			OtroNodo->PrevNodo = this->PrevNodo;
			delete this->NextNodo->NextNodo;
			this->NextNodo = OtroNodo;
			OtroNodo = this->NextNodo;

		}
		// para Nodos Singularmente Enlasados 
		else if(this->NextNodo->NextNodo != nullptr)
		{
			OtroNodo->NextNodo = this->NextNodo->NextNodo;
			delete this->NextNodo->NextNodo;
			this->NextNodo = OtroNodo;
		}
	}
	else if(NextNodo != nullptr)
	{
		NextNodo->InsertarNodoHeap(OtroNodo,  Posicion);
	}
}

void Nodo::InsertarValor(int Valor, int Posicion)
{
	if (this->NextNodo->M_Posicion == Posicion)
	{
		this->NextNodo->SetValor(Valor);
	
	}
	else if (NextNodo != nullptr)
	{
		NextNodo->InsertarValor(Valor, Posicion);
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