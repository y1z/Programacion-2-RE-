#pragma once
#include <iostream>//<- para imprimir a la consola . 
#include <vector>//<- para crear el arreglo 
#include <random>//<- para general valores aliatorios 
#include <time.h>//< - para crear una semilla aliatorias para srand,


void quickSort(std::vector<int> &Arreglo, int Comienzo, int Final);

void BorbujaSort(std::vector<int> &Arreglo);

void SelectionSort(std::vector<int> &Arreglo);

void InsertionSort(std::vector<int> &Arreglo);

void BorbujaSort(int *Arreglo,unsigned short size);

void InsertionSort(int *Arreglo, unsigned short size);
