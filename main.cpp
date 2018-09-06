#include <iostream>//<- para imprimir a la consola . 
#include <vector>//<- para crear el arreglo 
#include <random>//<- para general valores aliatorios 
#include <time.h>//
using std::cout;
using std::cin;

// esta funcion es para detener el programa
// mientras esta correndo 
void Stop() 
{
	cin.ignore();
	cin.get();
}

void BorbujaSort(std::vector<int> &Arreglo) {
	int IndiceMinimo = 0;
	int IndiceMaximo = Arreglo.size()-1;
	int IndicePrevioDelValorMasGrande = 0;
	int ValorMasGrande = 0;
	int Temporarl = 0;

	for (int i = 0; i < Arreglo.size(); ++i) {

		for (int j = 0; j < IndiceMaximo ; ++j) {

			
			if (Arreglo[j] > Arreglo[j + 1])
			{
				//ValorMasGrande = Arreglo[j];
				Temporarl = Arreglo[j + 1];
				Arreglo[j + 1] = Arreglo[j];
				Arreglo[j] = Temporarl;



			}

		}

		//--IndiceMaximo;
	}

}


void ArregloAlitorio() {
	int usuarioValor;// <- el valor que va a ingresar el usario .
	std::vector<int> ValoresAlitorios;

	cout << "ingresa un numero porfavor :) \n";
	cin >> usuarioValor;

	for (int i = 0; i < usuarioValor; ++i)
	{
		ValoresAlitorios.push_back(rand());

	}

	for (int valor : ValoresAlitorios) {
		cout <<'['<< valor << "] ";
	}

	BorbujaSort(ValoresAlitorios);
	std::cout << "------------\n";
	for (int valor : ValoresAlitorios) {
		cout << '[' << valor << "] ";
	}

	Stop();

}




int main() {
	// uso la funcion time(0) para que me de 
	// una semilla aliatoria cada vez que corro 
	// este programa 
	srand(time(0));
	
	ArregloAlitorio();



	return 0;
}