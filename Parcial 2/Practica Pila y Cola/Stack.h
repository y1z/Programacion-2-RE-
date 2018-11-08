#pragma once
#include "Nodo.h"
#include <vector>
class Stack :
	public Nodo,public List
{
public:
	Stack();
	Stack(int x);
	Stack(const char Name[], const char Apellido[], int day, int month, int year);
	~Stack();
	// el ultimo elemento en el stack 
	Nodo *ptr_Head;

	// para contar cuantos elemento 
	// tiene este Stack 
	int M_Elementos = 0;
public:
	void Push()override;
	void Pop()override;
public:
	void BuscarValor()override; 
	void AumentarElementos(int x);
	void PrintList()override;
	void BusquedaBinariaNombre();
	void BusquedaBinariaApellido();
private:
	void Sort(std::vector<Persona*> &vec, int bajo, int alto,bool IsNombre);
	int Particion(std::vector<Persona*> &vec, int bajo, int alto, bool IsNombre);
};

