#pragma once
#include "Nodo.h"
#include <vector>
class Stack :
	public Nodo
{
public:
	Stack();
	Stack(int x);
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
	void Push()override;
	void Pop()override;
	void pull(const std::string &Valor);
public:
//	void BuscarValor(const std::string &Valor)override;
	void BuscarValor()override; 
	void AumentarElementos(int x);
	void PrintList()override;
	void BusquedaBinaria(const std::string &Valor);
private:
	void Sort(std::vector<std::string*> &vec);
	void Particion();
};

