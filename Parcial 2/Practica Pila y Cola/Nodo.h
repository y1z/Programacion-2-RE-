#pragma once
#include <iostream>
#include "Persona.h"
#include "List.h"
class Nodo
{
public:
	Nodo();
	Nodo(std::string &Name, std::string &Apelledo, int day, int month, int year);
	Nodo(const char Name[], const char Apellido[], int day, int month, int year);

	virtual ~Nodo();
	// Variables de la clase
public:
	// apunta al siguente nodo 
	Nodo * NextNodo = nullptr;

	// apunta al nodo Antrior,para listasDobleMenteEnlasadas
	Nodo * PrevNodo = nullptr;

	// es el valor que contiene el nodo 
	Persona M_Valor;

	// este miembro determina donde esta 
	// el nodo en relacion a otros nodo 
	// Ejemplo : un nodo con M_Posicion = 0 
	// seria el primer nodo del linklist 
	int M_Posicion = -1;

	// Metodos 
public :
	/* Estas funciones connecta este nodo con
	   otro nodo */
	virtual void Enlasar(Nodo * OtroNodo);
	virtual void Enlasar(Nodo  &OtroNodo);

	/*Estas funcion hace que el Nodo actual se 
	 Enlasa con el otro nodo y tambien el OtroNodo 
	 se Enlasa con el Nodo actual  */
	virtual void EnlasarDouble(Nodo * OtroNodo);
	virtual void EnlasarDouble(Nodo &OtroNodo);

	/*Esta fucion va por todos los nodos hasta que encuentra 
	la cabeza(el untimo nodo) y le agrega otro nodo despues 
	de ese */
	virtual void Push(Nodo * OtroNodo);
	virtual void Push(Nodo  &OtroNodo);
	virtual void Push(Nodo * OtroNodo, Persona &Valor, int &Posicion);
	virtual void Push();

	void PushDouble(Nodo * OtroNodo);

	/*todo lo que hace es eleminar el ultimo nodo 
	en la lista */
	virtual void Pop();

	/* Esta funcion imprime el valor que contiene 
	 el nodo en cuestion */
	virtual void PrintValue();

	/* Esta funcion imprime el valor de todos 
	 los nodos conectados */
	virtual void PrintList();
	
    /*Este metodo busca por todo los nodos conectados 
	intentando econtrar el valor que desas , si no 
	lo encuetra , de dice que no lo encontro */
	virtual void BuscarValor(const std::string &Valor);
	
	virtual void BuscarValor();

	/*Para dar otro Valor al nodo*/
	virtual void SetValor(Persona &Valor);

	//virtual void InsertarNodoHeap(Nodo *OtroNodo,int Posicion);
	// consiguir el proximo nodo
	virtual Nodo* GetNext();
	//consiguir el nodo Anterior 
	virtual Nodo* GetPrev();
public:
	/* Hace la mismo que el metodos Enlasar */
	virtual void operator=(Nodo &OtroNodo);
	virtual void operator=(Nodo *OtroNodo);
};

