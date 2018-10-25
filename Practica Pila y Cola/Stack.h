#pragma once
#include "Nodo.h"
class Stack :
	public Nodo
{
public:
	Stack();
	Stack(const char Name[], const char Apellido[], int day, int month, int year);
	~Stack();
	// el ultimo elemento en el stack 
	Nodo *ptr_Head;
	// el elemento que quitamos 
	// pero no borramos 
	Nodo *ptr_Pull;

	
	// para contar cuantos elemento 
	// tiene este Stack 
	int M_Elementos = 0;
public:
	void Push();
	void Pop();
	void pull(const std::string &Valor);
public:
	void BuscarValor(const std::string &Valor)override;
	void CrearStack(int x);
	void PrintList();
};

