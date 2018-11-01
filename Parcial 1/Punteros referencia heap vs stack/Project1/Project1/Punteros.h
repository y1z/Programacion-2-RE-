#pragma once

void Arreglo() {

	//esto crea un arreglo 
	int *arr = new int[5];

	// esto crea solo un valor 
	int *var = new int(5);

	// este se usa cuando solo tenemos un valor para borrar
	//(tambien conosido como liberar la memoria )
	delete var;

	// este se usa cuand tenemos arrreglo para borrar
	//(tambien conosido como liberar la memoria )
	delete[] arr;


}
