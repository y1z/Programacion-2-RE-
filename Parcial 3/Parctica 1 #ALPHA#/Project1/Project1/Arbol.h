#pragma once
#include "NodoX.h"

class Arbol
{
public:
	Arbol();
	~Arbol();


public://Variables
	NodoX* Raiz = nullptr;

public://Metodos 
	void Add();
	void Add(NodoX* NuevoNodo);
	void Remove();
	void Remove(std::string &Remover);
	bool Seach(std::string &Buscar);
	void Print();
	void ConvertirVector(std::vector<Persona*> &Vec, int bajo , int alto);

	void Sort(std::vector<Persona*> &Vec,int bajo, int alto);
private:
	int Particion(std::vector<Persona*> &vec, int bajo, int alto);
};

