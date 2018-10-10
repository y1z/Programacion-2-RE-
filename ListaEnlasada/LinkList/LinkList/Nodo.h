#pragma once
#include <iostream>
class Nodo
{
public:
	Nodo();
	Nodo(int Valor);
	virtual ~Nodo();
	// Variables de la clase
public:
	// apunta al siguente nodo 
	Nodo * NextNodo = nullptr;

	// apunta al nodo Antrior,para listasDobleMenteEnlasadas
	Nodo * PrevNodo = nullptr;

	// es el valor que contiene el nodo 
	int M_Valor = 0;

	// este miembro determina donde esta 
	// este nodo en relacion a otros nodo 
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
	virtual void Push(Nodo * OtroNodo, int &Valor, int &Posicion);

	void PushDouble(Nodo * OtroNodo);
	void PushDouble(Nodo * OtroNodo, int &Valor, int &Posicion);

	/*Las funciones PopStack y PopHeap hacen lo mismo pero , 
	el PopHeap , usa la palabra reservada 'delete' para quitar un nodo */
	virtual void PopStack();
	virtual void PopHeap();

	/* Esta funcion imprime el valor que contiene 
	 el nodo en cuestion */
	virtual void PrintValue();

	/* Esta funcion imprimem el valor de todos 
	 los nodos conectados */
	virtual void PrintList();
	
    /*Este metodo busca por todo los nodos conectados 
	intentando econtrar el valor que desas , si no 
	lo encuetra , de dice que no lo encontro */
	virtual void BuscarValor(const int &Valor);

	/*Para dar otro Valor al nodo*/
	virtual void SetValor(int Valor);

	virtual void InsertarNodoHeap(Nodo *OtroNodo,int Posicion);
	virtual void InsertarValor(int Valor, int Posicion);
public:
	/* Hace la mismo que el metodos Enlasar */
	virtual void operator=(Nodo &OtroNodo);
	virtual void operator=(Nodo *OtroNodo);
};

