#include <iostream>
#include <vector>

using std::vector;

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

int partition(vector<int> &arrey, int bajo, int alto) {
	// la razon de porque el pivote es una referencia es para
	// tener la habilida de alterar el arreglo 
	int &pivote = arrey[alto];
	// este contador nos dice cuantos elemetos dentro del arreglo son menores que el pivote 
	int count = bajo - 1;

	for (int i = bajo; i < alto; ++i) {
		if(arrey[i] < pivote)
		{
			count++;
			if (i != count) 
			{
			int temporal = arrey[i];
			arrey[i] = arrey[count];
			arrey[count] = temporal;

			}
		}
	}

	int temporal = pivote;
	pivote = arrey[count + 1];
	arrey[count + 1] = temporal;

	return count + 1;

}

void sort(std::vector<int> &arrey, int bajo, int alto) {
	if (bajo < alto) {
		int pivot = partition(arrey, bajo, alto);

		sort(arrey, bajo, pivot - 1);
		sort(arrey, pivot + 1, alto);

	}
}

void PrintVector(std::vector<int> &arr) {
	for(int elemento : arr)
	{
		std::cout << '[' << elemento << "] ";
	
	}
	printf("\n");
}

int main() {
	std::vector<int> toSort = { 5,3,6,4,8,19,0,7 };

	PrintVector(toSort);
	sort(toSort, 0, toSort.size() - 1);
	PrintVector(toSort);
	Stop();
	return 0;
}