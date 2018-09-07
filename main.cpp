#include <iostream>//<- para imprimir a la consola . 
#include <vector>//<- para crear el arreglo 
#include <random>//<- para general valores aliatorios 
#include <time.h>//< - para crear una semilla aliatorias para srand,

using std::cout;//<- para no tener que poner std::cout<<"lo que sea"
using std::cin;

// esta funcion es para detener el programa
// mientras esta correndo 
void Stop() 
{
	cin.ignore();
	cin.get();
}




void SelectionSort(std::vector<int> &Arreglo) {
	// el Selection Sort busca el elemento mas 
	// Chico y lo pone al inicio del arreglo
	// en la primero iteracion luego el lugar a 
	// Remplasar es el espacio adelante del 
	//primer espacio

	/*Ejemplo  
	[9][6][4][7]
	 ^
	el 4 y 9 Cambian de lugar
	 [4][6][9][7]
	     ^
	se queda igual 

	[4][6][9][7]
	        ^ 
	el 9 y 7 cambian de lugar 


	[4][6][7][9]

	se Termino . 
	*/

	// tengo este valor(ElementoACambiar) porque voy a ramplazar
	// este con "ElementoMasChico" y para hacer
	// el seleccion sort voy a tener que intercambiar 
	// estos dos valore de lugar por lo tanto necesito una copia .

	int ElementoACambiar = 0;

	// Este valor me dice cual elemento del la seccion no
	//sortiada del Arreglo es el mas Chico .
	int ElementoMasChico = 0;

	// Este valor me dice la posicion del "ElementoMasChico"
	// dentro del Arreglo 
	int IndiceDelElementoMasChico = 0;

	// este valor indica a donde ira 
	// el "ElementoMasChico" dentro del 
	// Arreglo Arreglo 
	int IndiceParaElementoMasChico = 0;


	for (int i = 0; i < Arreglo.size(); ++i)
	{
		// Asigno la variable "ElementoMasChico" al 
		// primer valor del arreglo en el espacio 'i'
		// porque como inicialize la variable "ElementoMasChico"
		// como 0 solo valores menor al 0 se podian asignar 
		// despues y no puedo garantizar que siquiera exista elemento
		// menores que zero . 
		ElementoMasChico = Arreglo[i];
		
		// reposiciono el Indice ( si no ago esto todo el arreglo el sort
		// haveces pone valores en lugares arbirtrarios 
		IndiceDelElementoMasChico = i;

		// esto es para tener la copia del valor que ahi antes
		// para usarlo despues 
		ElementoACambiar = Arreglo[IndiceParaElementoMasChico];
		
		// le asigno j a =IndiceParaElementoMasChico porque SelectionSort
		// no Require que vea todo el arreglo cada ciclo. 
		for (int j = IndiceParaElementoMasChico; j < Arreglo.size(); ++j)
		{
			//Ago la comparacion para ver cual es el elemento mas Chico
			// de la parte no Organizada .
			if (ElementoMasChico > Arreglo[j]) {
				ElementoMasChico = Arreglo[j];
				IndiceDelElementoMasChico = j;
			}
		}

		//asigno el Valor mas Chico al lugar donde deberia esta en el arreglo 
		Arreglo[IndiceParaElementoMasChico] = Arreglo[IndiceDelElementoMasChico];

		// este if es para que no cambie un valor que necesita cambiar
		// si el ElementoMasChico esta en el inicio no veo razon para 
		// cambiarlo .
		if (!(IndiceParaElementoMasChico == IndiceDelElementoMasChico)) {
		Arreglo[IndiceDelElementoMasChico] = ElementoACambiar;

		}
		
		// cuando todos los demas pasos se cumplan
		// no tender que ver todo el arreglo de nuevo
		// por esa razon avanso un espacio .
		IndiceParaElementoMasChico++;

	}

}

void BorbujaSort(std::vector<int> &Arreglo) {
	
	int Temporarl = 0;

	// uso este boliano para ver si
	// el arreglo ya esta sortiado.
	bool Sorted = false;

	// todo lo que hace este algorimo en es
	// checa todo el arreglo Compararndo
	// cada elemento individual y moviendo
	// el mas grande hasta el frente del Arreglo 

	for (int i = 0; i < Arreglo.size(); ++i) {
		Sorted = true;

		for (int j = 0; j < Arreglo.size() - 1 - i; ++j) {

			if (Arreglo[j] > Arreglo[j + 1])
			{
				Temporarl = Arreglo[j + 1];
				Arreglo[j + 1] = Arreglo[j];
				Arreglo[j] = Temporarl;
				Sorted = false;
			}

		}

		if (Sorted == true){

			break;
		}
	}

}

void quickSort(std::vector<int> &Arreglo)
{

	int Pivote = 0;

	int IndiceL = 0;
	int IndiceR = 0;

	int ValorEnR = 0;
	int ValorEnL = 0;


	(Arreglo.size() % 2 == 1) ? Pivote = (Arreglo.size() / 2) + 1 : Pivote = (Arreglo.size() / 2);

	IndiceR = Arreglo.size() - 1;
	while (IndiceL >= Pivote || IndiceR > Pivote )
	{
		if (Arreglo[IndiceL] > Arreglo[Pivote]) {
			// lo que hace este codigo en intercabiar dos elementos .
			ValorEnL = Arreglo[IndiceL];
			Arreglo[IndiceL] = Arreglo[IndiceR];
			Arreglo[IndiceR] = ValorEnL;
		}
		++IndiceL;
		if(Arreglo[IndiceR] < Arreglo[Pivote])
		{
			ValorEnR = Arreglo[IndiceR];
			Arreglo[IndiceR] = Arreglo[IndiceL];
			Arreglo[IndiceL] = ValorEnR;
		
		}
		--IndiceR;

		if (IndiceR == IndiceL) {
			ValorEnL = Pivote;
			Pivote = IndiceL;
			IndiceL = ValorEnL;

		}

	}


}



void ArregloAlitorio() {
	int usuarioValor;// <- el valor que va a ingresar el usario .
	std::vector<int> ValoresAlitorios;

	cout << "ingresa un numero porfavor :) \n";
	cin >> usuarioValor;
	std::cout << "Antes \n";

	ValoresAlitorios.resize(usuarioValor);

	for (int i = 0; i < usuarioValor ; ++i)
	{
		ValoresAlitorios[i] = rand();

	}

	for (int valor : ValoresAlitorios) {
		cout << valor << ", ";
	}

	quickSort(ValoresAlitorios);
	std::cout << "\n-------------Despues---------------\n";
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