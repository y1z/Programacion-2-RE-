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
	// Luego repite eso excepto que pone el 
	// elemento mas Chico que Encuentra 
	// al lado del El elemeto mas Chico Previo. 

	/*Ejemplo
	[9][6][4][7]

	el 4 y 9 Cambian de lugar
	[4][6][9][7]

	se queda igual

	[4][6][9][7]

	el 9 y 7 cambian de lugar


	[4][6][7][9]

	se Termino .
	*/

	// tengo este valor(ElementoACambiar) porque voy a ramplazar
	// este con "ElementoMasChico" y para hacer
	// el seleccion sort voy a tener que intercambiar valores 

	int ElementoACambiar = 0;

	// Este valor me dice cual elemento del Arreglo
	//( menos los que ya fueron Organizados ) Es el MasChico.
	int ElementoMasChico = 0;

	// Este valor me dice la posicion del "ElementoMasChico"
	// dentro del Arreglo 
	int IndiceInicialElementoMasChico = 0;

	// este valor indica a donde ira 
	// el "ElementoMasChico" dentro del 
	// Arreglo Arreglo 
	int IndiceParaIntercambio = 0;


	for (int i = 0; i < Arreglo.size(); ++i)
	{
		// Asigno la variable "ElementoMasChico" al 
		// primer valor del arreglo en el espacio 'i'
		// porque como inicialize la variable "ElementoMasChico"
		// como 0 solo valores menor al 0 se podian asignar 
		// despues y no puedo garantizar que siquiera exista elemento
		// menores que zero . 
		ElementoMasChico = Arreglo[i];

		// reposiciono el Indice ( si no se hace esto todo el arreglo de el sort
		// a veces pone valores en lugares arbirtrarios )
		IndiceInicialElementoMasChico = i;

		// esto es para tener la copia del valor que ahi antes
		// para usarlo despues 
		ElementoACambiar = Arreglo[IndiceParaIntercambio];

		// asigno j a =IndiceParaElementoMasChico porque SelectionSort
		// no Require que vea todo el arreglo cada ciclo. 
		for (int j = IndiceParaIntercambio; j < Arreglo.size(); ++j)
		{
			//Ago la comparacion para ver cual es el elemento mas Chico
			// de la parte no Organizada .
			if (ElementoMasChico > Arreglo[j]) {
				ElementoMasChico = Arreglo[j];
				IndiceInicialElementoMasChico = j;
			}
		}

		//asigno el Valor mas Chico al lugar donde deberia esta en el arreglo 
		Arreglo[IndiceParaIntercambio] = Arreglo[IndiceInicialElementoMasChico];

		// este if es para que no cambie un valor que necesita cambiar
		// si el ElementoMasChico esta en el inicio no veo razon para 
		// cambiarlo .
		if (!(IndiceParaIntercambio == IndiceInicialElementoMasChico)) {
			Arreglo[IndiceInicialElementoMasChico] = ElementoACambiar;

		}

		// cuando todos los demas pasos se cumplan
		// no tender que ver todo el arreglo de nuevo
		// por esa razon avanso un espacio .
		IndiceParaIntercambio++;

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

		if (Sorted == true) {

			break;
		}
	}

}


// eventalmente quiero hacer el quickSort con ciclos pero por ahora 
// solo dejare esta funcion aqui para hacer eso otro dia 
void quickSort(std::vector<int> &Arreglo)
{
	// la parte lo cual deside el valor a compara para L y R 
	// en otras palabras si un valore es menor que el del pivote 
	// deberia estar en la parte de la izquierda del pivote .
	int Pivote = 0;

	// indica que parte del arreglo estan comparando en relacion
	// del pivote .
	int IndiceL = 0;
	int IndiceR = 0;

	// uso estos dos valores para intercambiar valores en los indices 
	// porque necesito una copia del valor antes de hacer el intercambio 
	int ValorEnR = 0;
	int ValorEnL = 0;

	// lo que hace esto aqui abajo es asignar el pivote al lugar del medio
	// del arreglo .
	(Arreglo.size() % 2 == 1) ? Pivote = (Arreglo.size() / 2) + 1 : Pivote = (Arreglo.size() / 2);

	IndiceR = Arreglo.size() - 1;

	//	while (IndiceL)

}

void quickSort(std::vector<int> &Arreglo, int Comienzo, int Final)
{
	/*
	Los valor Comienzo y Final son para hacer Recurcion ( en otras palabras eligen
	la parte del arreglo que vamos a trabajar) .
	*/

	// Este valor elige un lugar en el arreglo y el valor que se ubica
	// en es parte del arreglo se usa para hacer compararciones para
	// ver si 
	int Pivote = 0;

	// indica que parte del arreglo estan comparando en relacion
	// del pivote .
	int IndiceL = Comienzo;
	int IndiceR = Final ;

	// este valor solo es para tener una copia de 
	int ValorDeIntercambio = 0;
	//el pivote copia el valor que esta en el medio para luego ser comparado
	// con los valores en IndiceL y IndiceR
	Pivote = Arreglo[(Comienzo + Final) / 2];

	while (IndiceL <= IndiceR) {

		// este while verifica que si los valores que esta a la 
		// izquierda del Pivote son mas pequños que el mismo Pivote
		while (Arreglo[IndiceL] < Pivote)
		{
			IndiceL++;
		}

		// este while verifica que si los valores que esta a la 
		// Derecha del Pivote son mas grande que el mismo Pivote   
		while (Arreglo[IndiceR] > Pivote)
		{
			IndiceR--;
		}

		//cuando estos dos previos while dejen de ser ciertos 
		// significa que se debe hacer un intercambio 
		if (IndiceL <= IndiceR) {

			ValorDeIntercambio = Arreglo[IndiceL];
			Arreglo[IndiceL] = Arreglo[IndiceR];
			Arreglo[IndiceR] = ValorDeIntercambio;

			IndiceL++;

			IndiceR--;
		}

	}

	if (Comienzo < IndiceR)
	{
		quickSort(Arreglo, Comienzo, IndiceR);
	}

	if (IndiceL <Final)
	{
		quickSort(Arreglo, IndiceL,Final);
	}

}

// Original 
void InsertionSort(std::vector<int> &Arreglo) 
{
	/* EL InsertionSort Toma una Variable , Compara con una segunda Variable que esta delante de la Primera
	   y si la Primera Variable es mas Grande que la Segunda intercambian lugares , sigue haciendo eso hasta 
	   que una de dos cosas pasen .
	   1) la Variable llego al final del arreglo .
	   2) La Variable que esta adelante en el arreglo
	      es mas grande .


	Ejemplo de como funciona insertionSort 
	[3][2][5][8][4]
	          ^    
	mueve el 8 al final de la fila 
	
	[3][5][2][4][8]
	          ^
    Deja el 4 donde esta 

	[3][5][2][4][8]
	       ^
	Deja el 2 donde esta 

	[3][5][2][4][8]
	    ^ 
	Mueve el 5 al lugar del 2  

	[3][2][5][4][8]
		   ^	
	Mueve 5 al lugar del 4 

	[3][2][4][5][8]
	           ^
	Deja el 5 donde esta 

	[3][2][4][5][8]
	 ^
	 Mueve el 3 en el lugar del 2 

	 [2][3][4][5][8]

	*/


	// Esto determina las Areas que ya estan organizadas del arreglo 
	int LugarOrganizado = Arreglo.size() -2 ;

	// necesito una copia para ver dentro de la parte del arreglo, 
	// que Organize para ver donde deberia ir la variable que estoy moviendo .
	int CopiaLugarOrganizado;

	// un valor que uso para intercambiar valores de un lugar en el arreglo,
	// a otro lugar dentro del mismo arreglo 
	int Temporal; 

	for (int i = Arreglo.size() -1; i > 0; --i)
	{
		
		CopiaLugarOrganizado = LugarOrganizado;

		while (Arreglo[CopiaLugarOrganizado] > Arreglo[CopiaLugarOrganizado + 1]) {
			Temporal = Arreglo[CopiaLugarOrganizado + 1];
			Arreglo[CopiaLugarOrganizado + 1] = Arreglo[CopiaLugarOrganizado];
			Arreglo[CopiaLugarOrganizado] = Temporal;
			// incremento esta variable para ver donde deberia ir 
			// la varible dentro del arreglo .
			++CopiaLugarOrganizado;

			// Este if es para No salirse del rango del Arreglo 
			if (CopiaLugarOrganizado == Arreglo.size() - 1) {
				break;
			}


		}
		// El InsertionSort Comiza desde el Final de un arreglo , hasta 
		// el inicio por esa razon le resto a esta varible .
		--LugarOrganizado;
	}


}

// SobreCarga 
void InsertionSort(int *ptr_Areglo , int Size)
{
	/* EL InsertionSort Toma una Variable , Compara con una segunda Variable que esta delante de la Primera
	y si la Primera Variable es mas Grande que la Segunda intercambian lugares , sigue haciendo eso hasta
	que una de dos cosas pasen .
	1) la Variable llego al final del arreglo .
	2) La Variable que esta adelante en el arreglo
	es mas grande .


	Ejemplo de como funciona insertionSort
	[3][2][5][8][4]
	^
	mueve el 8 al final de la fila

	[3][5][2][4][8]
	^
	Deja el 4 donde esta

	[3][5][2][4][8]
	^
	Deja el 2 donde esta

	[3][5][2][4][8]
	^
	Mueve el 5 al lugar del 2

	[3][2][5][4][8]
	^
	Mueve 5 al lugar del 4

	[3][2][4][5][8]
	^
	Deja el 5 donde esta

	[3][2][4][5][8]
	^
	Mueve el 3 en el lugar del 2

	[2][3][4][5][8]

	*/


	// Esto determina las Areas que ya estan organizadas del arreglo 
	int LugarOrganizado = Size-1;

	// necesito una copia para ver dentro de la parte del arreglo, 
	// que Organize para ver donde deberia ir la variable que estoy moviendo .
	int CopiaLugarOrganizado;

	// un valor que uso para intercambiar valores de un lugar en el arreglo,
	// a otro lugar dentro del mismo arreglo 
	int Temporal;

	for (int i = Size; i > 0; --i)
	{

		CopiaLugarOrganizado = LugarOrganizado;

		while (ptr_Areglo[CopiaLugarOrganizado] > ptr_Areglo[CopiaLugarOrganizado + 1]) {
			Temporal = ptr_Areglo[CopiaLugarOrganizado + 1];
			ptr_Areglo[CopiaLugarOrganizado + 1] = ptr_Areglo[CopiaLugarOrganizado];
			ptr_Areglo[CopiaLugarOrganizado] = Temporal;
			// incremento esta variable para ver donde deberia ir 
			// la varible dentro del arreglo .
			++CopiaLugarOrganizado;

			// Este if es para No salirse del rango del Arreglo 
			if (CopiaLugarOrganizado == Size - 1) {
				break;
			}


		}
		// El InsertionSort Comiza desde el Final de un arreglo , hasta 
		// el inicio por esa razon le resto a esta varible .
		--LugarOrganizado;
	}


}



// esta Funcion usa vectores .
void ArregloAlitorioUsandoVector() {
	int usuarioValor;// <- el valor que va a ingresar el usario .
	std::vector<int> ValoresAlitorios;

	cout << "ingresa un numero porfavor :) \n";
	cin >> usuarioValor;
	std::cout << "Antes \n";

	ValoresAlitorios.resize(usuarioValor);

	for (int i = 0; i < usuarioValor; ++i)
	{
		ValoresAlitorios[i] = rand();

	}

	for (int valor : ValoresAlitorios) {
		cout << valor << ", ";
	}

	InsertionSort(ValoresAlitorios);

	std::cout << "\n-------------Despues---------------\n";
	for (int valor : ValoresAlitorios) {
		cout << '[' << valor << "] ";
	}

	Stop();

}

//Esta Funcion usa Arreglo normales 
void ArregloAlitorioDynamico() {
	int usuarioValor;// <- el valor que va a ingresar el usario .

	cout << "ingresa un numero porfavor :) \n";
	
	cin >> usuarioValor;
	
	std::cout << "Antes \n";

	//crear el arreglo dynamico
	int* ptr_Arreglo = new int[usuarioValor];

	for (int i = 0; i < usuarioValor ; ++i)
	{
		ptr_Arreglo[i] = rand();
	}

	for (int i = 0; i < usuarioValor; ++i)
	{
		cout << ptr_Arreglo[i] << ',';
	}


	InsertionSort(ptr_Arreglo, usuarioValor);

	cout << "\n-------------Despues---------------\n";
	for (int i = 0; i < usuarioValor; ++i)
	{
		cout <<"["<< ptr_Arreglo[i] << "] ";
	}

	delete[] ptr_Arreglo;
	
	Stop();


}

int main() {
	// uso la funcion time(0) para que me de 
	// una semilla aliatoria cada vez que corro 
	// este programa 
	srand(time(0));

	ArregloAlitorioUsandoVector();


	return 0;
}