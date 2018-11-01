#include <iostream>
#include<chrono>
int Factorial(int x) 
{
	if (x <= 1) {
		return x;
	}
	return x * Factorial(x-1);
}

int main() {
	int Valor = 0;
	std::cin >> Valor;

	std::cout<<Factorial(Valor);

	std::cin.get();
	return 0;
}