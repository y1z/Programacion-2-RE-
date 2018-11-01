#include<iostream>
#include"heap vs Stack.h"
#include"Referencias.h"
#include "Punteros.h"

#define LOG(x) std::cout<< x<<std::endl;

void Stop() {
	std::cin.ignore();
	std::cin.get();

}

// esto toma un puntero a i 
// y le incrementa hace una suma a su valor mas 1 
void p_Icremiento(int *i) {

	(*i)++;


}

// esto crea una nueva referencia a i 
// y le incrementa hace una suma a su valor mas 1 
void R_Icremento(int &i) {
	++i;

}

// esto crea una nuevo varible i
// solo crea una copia del valor original 
void V_Icremento(int i) {

	i++;
	LOG(i);

}

int main() {
	//int i = 8;
	//LOG("dame un numero \n");
	//std::cin >> i;
	//
	//int *ptr = &i;
	StackAndHeap();


	Stop();
	return 0;
}