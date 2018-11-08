#pragma once
#include "Nodo.h"
#include <vector>
class Cola :
	public Nodo , public List
{
public:
	Cola();
	Cola(int x);
	~Cola();
public:
	Nodo * ptr_FirstNodo;
	Persona M_Valor;

	int M_Elementos = 0;
public:
	void Push()override;
	void Pop()override;
	void pull(const std::string &Valor);
	void AumentarCola(int x);
	void BuscarValor()override;

	void BusquedaBinariaNombre();
	void BusquedaBinariaApellido();

public:
	void PrintList()override;
	void Sort(std::vector<Persona*> &vec, int bajo, int alto, bool IsNombre);
	int Particion(std::vector<Persona*> &vec, int bajo, int alto, bool IsNombre);
};

