#include "Sort.h"

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
	int IndiceR = Final;

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
		quickSort(Arreglo, IndiceL, Final);
	}

}

void BorbujaSort(std::vector<int> &Arreglo)
{

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

void SelectionSort(std::vector<int> &Arreglo){
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
	int LugarOrganizado = Arreglo.size() - 2;

	// necesito una copia para ver dentro de la parte del arreglo, 
	// que Organize para ver donde deberia ir la variable que estoy moviendo .
	int CopiaLugarOrganizado;

	// un valor que uso para intercambiar valores de un lugar en el arreglo,
	// a otro lugar dentro del mismo arreglo 
	int Temporal;

	for (int i = Arreglo.size() - 1; i > 0; --i)
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

void BorbujaSort(int *Arreglo,unsigned short size) {
	// este bool es para asegurarse que el Arreglo 
	// no este ya sortiado 
	bool isSorted = true;
	// uso esta variable para intercambiar, la posicion 
	// de valores dentro del arreglo .
	int Intercambio = 0;

	for (int i = 0; i < size; i++) 
	{
		isSorted = true;
		for (int i = 0; i < size - 1; ++i) 
		{
			if (Arreglo[i] > Arreglo[i + 1])
			{
			Intercambio = Arreglo[i];
			Arreglo[i] = Arreglo[i + 1];
			Arreglo[i + 1] = Intercambio;
			isSorted = false;
			}
		}

		if (isSorted == true) 
		{
			break;
		}

	}

}

void InsertionSort(int *Arreglo, unsigned short size) {
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

	// esta variable determina la seccion que 
	// ya fue sortiada 
	unsigned short SeccionSorted = size - 2;

	// esta variable se usa para , llevar la variable
	//que esta siendo intertando a su lugar debido en el 
	// arreglo 
	unsigned short CopiaSeccion = 0;

	// uso esta variable para intercambiar valores de un 
	// lugar a otro(dentro del arreglo) .
	int Intercambio = 0;
	

	for(int i = 0 ; i <size - 1 ; ++i)
	{
		//esto es para reiniciar el lugar de donde voy a empezar 
		// a hacer comparaciones 
		CopiaSeccion = SeccionSorted;

		while (Arreglo[CopiaSeccion] > Arreglo[CopiaSeccion + 1]) 
		{
			Intercambio = Arreglo[CopiaSeccion + 1];

			Arreglo[CopiaSeccion + 1] = Arreglo[CopiaSeccion];

			Arreglo[CopiaSeccion] = Intercambio;
			//incremento esta varible par avansar dontro del arreglo 
			++CopiaSeccion;

			// Este if es para No salirse del rango del Arreglo 
			if (CopiaSeccion == (size - 1) ) {
				break;
			}
		}
		// El InsertionSort Comiza desde el Final de un arreglo , hasta 
		// el inicio por esa razon le resto a esta varible .
		SeccionSorted--;
	}

}

void SelectionSort(int *Arreglo, unsigned short size) {
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


	for (int i = 0; i < size; ++i)
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
		for (int j = IndiceParaIntercambio; j < size; ++j)
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



