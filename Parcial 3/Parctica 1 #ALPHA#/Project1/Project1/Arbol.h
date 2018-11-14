#pragma once
#include "NodoX.h"

class Arbol
{
public:
	Arbol();
	~Arbol();


public://Variables
	NodoX* Raiz = nullptr;
	std::vector<Persona*> M_Personas;

public://Metodos 
	void Add();
	void Add(NodoX* NuevoNodo);
	void Remove();
	bool Seach();
	void Print();
	void CopiarVector(std::vector<Persona*> &Vec);
	void ConvertirVector(std::vector<Persona*> &Vec, int bajo , int alto);

	void Sort(std::vector<Persona*> &Vec,int bajo, int alto);
private:
	int Particion(std::vector<Persona*> &vec, int bajo, int alto);
};

