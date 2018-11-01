#pragma once
#include "Nodo.h"
class Cola :
	public Nodo
{
public:
	Cola();
	~Cola();
public:
	Nodo * ptr_FirstNodo;
	Persona M_Valor;

	int M_Elementos = 0;
public:
	void Push()override;
	void Pop()override;
	void pull(const std::string &Valor);
	void CrearCola(int x);
	void BuscarValor()override;
public:
	void PrintList()override;
};

