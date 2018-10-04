#pragma once
#include<iostream>

class ListaEnlasada
{
//contrctores y destructor
public:
	ListaEnlasada();

	ListaEnlasada(int Valor);

	 virtual~ListaEnlasada();
public:

	// Valor que contiene el nodo 
	int Valor = 0;
	// puntero al proximo nodo 
	ListaEnlasada *next = nullptr;

//Metodos de la clase 
public:
    void EnlasarNext(ListaEnlasada &NextLink);
	void PrintValor();
	int BuscarValor(int ValorBuscar);
	void Pop();
virtual	void Push(ListaEnlasada &Nodo);

//Sobre carga de Operadores 
public:
	 void operator>>(ListaEnlasada &Nodo);
};