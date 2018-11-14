#include <iostream>
#include <vector>
#include "MisFunciones.h"
#include "Arbol.h"


int main() {

	std::vector<Persona*> Vec;

	 char PirmerCaracter[] = "L";

	for(int i =0; i < 15;++i)
	{
		Persona * tempPer = new Persona(PirmerCaracter, "test", 3, 3, 3);
		PirmerCaracter[0]++;
		Vec.emplace_back(tempPer);
	}

	char SegundoCaracter[] = "K";

	for (int i = 0; i > -11; --i)
	{
		Persona * tempPer = new Persona(SegundoCaracter, "test", 3, 3, 3);
		SegundoCaracter[0]--;
		Vec.emplace_back(tempPer);
	}

	for (Persona *var : Vec) {
		var->Print();
	}

	Arbol arbol;

	arbol.Sort(Vec,0,Vec.size() - 1);

	arbol.CopiarVector(Vec);

	LineaExtra(4);

	for (Persona *var : Vec) {
		var->Print();
	}

	arbol.ConvertirVector(arbol.M_Personas, 0, arbol.M_Personas.size() - 1);
	LineaExtra(4);
	arbol.Print();

	Stop();

	//NodoX * ptr_nodo = new NodoX("D", "tets", 3, 3, 3);

	//for (int i = 0; i < 4; ++i) {
	//	NodoX *ptr_addcional = new NodoX();
	//	ptr_addcional->CrearPersona();
	//	ptr_nodo->Push(ptr_addcional);
	//}
	//ptr_nodo->PrintAll();


	//ptr_nodo->Pop();

	//
	//ptr_nodo->PopAll();
	//ptr_nodo = nullptr;

	for (Persona* var : Vec)
	{
		delete var;
	}



	Stop();

	return 0;
}