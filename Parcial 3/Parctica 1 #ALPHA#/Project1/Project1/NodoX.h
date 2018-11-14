#pragma once
#include "Persona.h"
#include <iostream>
#include <vector>// para la operacion del Pop
class NodoX
{
public:
	NodoX();
	NodoX(const char Name[], const char Apellido[], int day, int month, int year);
	~NodoX();
public:// Variables 
	// apunta a los Nodo con mayor o 
	// menor valores (en este caso 
	// el valor es tipo Persona) 
	NodoX * ptr_Mayor = nullptr;
	NodoX * ptr_Menor = nullptr;
	// el valor que contiene el nodo 
	Persona M_Persona;
public: 
	void CrearPersona();
	void Push(NodoX * NuevoNodo);
	bool Seach(const char Buscar[]);
	void PopAll();
	void Pop();
	void Print();
	NodoX* GetMayor();
	NodoX* GetMenor();
private:
	// esta funcion verifica si el nodo 
	// tiene 2 hijos
	bool VerificarHijos(NodoX *nodo);
	// buscar el valor a quitar y todos 
	// los nodos que estan en el camino hacia ese 
	// nodo 
	bool SeachForPop(std::vector<NodoX*> &Camino,const std::string &Buscar);
	bool CompararPersona(Persona &persona);
};

