#include "heap vs Stack.h"

void StackAndHeap() {
//Stack

// el Stack si no usamos new malloc o cual quier otra funcion que nos 
// permite tener alocar memoria , atomaticamente nos allcan en el Stack todo.
int var1 = 5;
int arr[5];
arr[0] = 3;
arr[1] = 3;
int var2 = 8;

//Heap

// la palabra new no permite resevar memoria que esta en el 
//heap 
int *ptrNumber = new int(5);
int *ptrArrey = new int[5];

ptrArrey[0] = 2;
ptrArrey[1] = 2;
ptrArrey[2] = 2;
ptrArrey[3] = 2;

int *ptrPc = new int(8);

// se deshace de los valore que estaban apuntando los punteros 
delete ptrNumber;
delete ptrPc;
delete[] ptrArrey;
}
