#include "Cola.h"



Cola::Cola()
{
}

Cola::Cola(int x)
{
	AumentarCola(x);
}

Cola::~Cola()
{
}

void Cola::Push() 
{
	std::string Name, Apellido;
	int day, month, year;

	std::cout << "porfavor ingresa un Nombre ,Apellido y fecha de nacimiento\n" << "en el siguente formato dd/mm/yyyy ";
	std::cin >> Name;
	std::cin >> Apellido;
	std::cin >> day >> month >> year;

	Nodo* nuevoNodo = new Nodo(Name.c_str(),Apellido.c_str(),day,month,year);
	if (M_Elementos == 0)
	{
		ptr_FirstNodo = nuevoNodo;
	}
	else {
		this->ptr_FirstNodo->PushDouble(nuevoNodo);
	}


	M_Elementos++;
}

void Cola::Pop()
{
	// si no se complie la condicion 
	// borro los datos del primer Nodo 
	if (M_Elementos > 1) {
		// creo 2 nodo temprales 
		Nodo* temp1 = ptr_FirstNodo;
		Nodo* temp2 = nullptr;
		// muevo el puntero del primer nodo para el 
		// nodo siguente 
		ptr_FirstNodo = ptr_FirstNodo->GetNext();
		//quito el nodo que de la Cola 
		temp1->NextNodo = nullptr;
		// Enlaso en nodo temp2 con temp1 
		// para hacer le Pop.
		temp2 = temp1;
		temp2->Pop();
		temp1 = nullptr;
		temp2 = nullptr;
	}
	else {
		delete ptr_FirstNodo;
		ptr_FirstNodo = nullptr;
	}
	M_Elementos--;
}

void Cola::pull(const std::string &Valor) {

}

void Cola::AumentarCola(int x) {

	for (int i = 0; i < x; ++i) {
		this->Push();
	}
}


void Cola::PrintList()
{
	if (M_Elementos > 0)
	ptr_FirstNodo->PrintList();
	else {
		std::cout << "no exite elemento en esta Cola\n";
	}
}

void Cola::BuscarValor() {
	std::cout << "dime el valor que quires ";
	std::string Valor;
	std::cin >> Valor;

	// para cuando tengo el mismo nombre 
	// en mulpiles lugares 
	bool IsRepetido = false;

	bool IsEncontrado = false;
	// primero voy al Primer 
	// elemento de la cola 
	Nodo*Comparar = ptr_FirstNodo;
	Nodo *Copia = Comparar;

	Persona * ptr_persona = nullptr;
	for (int i = 0; i < M_Elementos; ++i)
	{
		if (Comparar->M_Valor == Valor)
		{
			ptr_persona = &Comparar->M_Valor;
			if (IsRepetido == false) {
				std::cout << "aqui el usario qu bucaba \n\n";
				ptr_persona->Print();
				IsRepetido = true;
				IsEncontrado = true;
			}
			else
			{
				std::cout << " ," << i;
			}
		}
		// para consiguir el proximo nodo 
		Comparar = Comparar->GetNext();

		// para verificar que si cambio de nodo 
		if (Copia == Comparar)
		{
			if (IsEncontrado == false)
			{
				std::cout << "no Encontramos a [" << Valor << "] en la lista ";
			}
			break;
		}
		Copia = Comparar;
	}
	if (IsEncontrado == false) {
		std::cout << "no Pudimos encontrar el [" << Valor << "] en la Cola \n";
	}

}



void Cola::BusquedaBinariaNombre()
{
	std::string ValorParaBuscar;
	std::cout << "Digame que es el nombre que esta buscando \n Aqui -->";
	std::cin >> ValorParaBuscar;
	// uso punteros hacia los valores originales 
	// para consumir menos memoria 
	std::vector <Persona*> ArregloTemp;
	// para hacer espacio para los elementos antes
	// de intertarlos 
	ArregloTemp.resize(M_Elementos);

	Nodo* Temp = ptr_FirstNodo;
	// consigue todos los Nodo del Stack 
	for (int i = 0; i < M_Elementos; ++i)
	{
		ArregloTemp[i] = &Temp->M_Valor;
		Temp = Temp->GetNext();
	}
	// Organiza por nombre 
	Sort(ArregloTemp, 0, ArregloTemp.size() - 1, true);

	bool IsEncontrado = false;

	// esto dos valor dictan los indices en donde buscaremos 
	// el valor que no pide el usario .
	int InicioDeArreglo = 0;
	int FinalDeArreglo = ArregloTemp.size() - 1;
	// uso esto para indentificar si encontre el valor
	// que esta buscando el usario 
	int Id = ArregloTemp.size() / 2;


	do
	{
		/*Si no encotramos un el valor en el medio , vamos a
		divir la catidad de indices en donde vamos a buscar
		y siguimos haciendo eso hasta encontra el valor */
		if (ArregloTemp[Id]->M_nombre < ValorParaBuscar)
		{
			//si el valor a buscar es mayor tendermos que quitar toda la 
			// mitad con los numero mas 
			InicioDeArreglo = (InicioDeArreglo + FinalDeArreglo) / 2;
		}
		else if (ArregloTemp[Id]->M_nombre > ValorParaBuscar)
		{
			FinalDeArreglo = (InicioDeArreglo + FinalDeArreglo) / 2;
		}

		Id = (InicioDeArreglo + FinalDeArreglo) / 2;


		if (ArregloTemp[Id]->M_nombre == ValorParaBuscar)
		{
			IsEncontrado = true;
			break;
		}

		// buscar en el centro del area dictado por las dos 
		// variables 


		// si una de estas condiciones se cumple, significa que 
		// solo exite dos mas lugares a verificar 
		// asi que los verifco 
		if (InicioDeArreglo + FinalDeArreglo == 1 || FinalDeArreglo - InicioDeArreglo == 1)
		{
			if (ArregloTemp[InicioDeArreglo]->M_nombre == ValorParaBuscar) {
				IsEncontrado = true;
				Id = InicioDeArreglo;
				break;
			}
			else if (ArregloTemp[FinalDeArreglo]->M_nombre == ValorParaBuscar) {
				IsEncontrado = true;
				Id = FinalDeArreglo;
				break;
			}
			break;
		}
	} while (ArregloTemp[Id]->M_nombre != ValorParaBuscar && InicioDeArreglo < FinalDeArreglo);


	if (IsEncontrado) {
		printf("Aqui el Individuo que buscaba\n ");
		ArregloTemp[Id]->Print();
	}
	else {
		printf(">lo que esta buscando [%s] no existe< \n", ValorParaBuscar.c_str());
	}
}

void Cola::BusquedaBinariaApellido()
{
	std::string ValorParaBuscar;
	std::cout << "Digame que es el Aepllido que esta buscando \n Aqui -->";
	std::cin >> ValorParaBuscar;
	// uso punteros hacia los valores originales 
	// para consumir menos memoria 
	std::vector <Persona*> ArregloTemp;
	// para hacer espacio para los elementos antes
	// de intertarlos 
	ArregloTemp.resize(M_Elementos);

	Nodo* Temp = ptr_FirstNodo;
	// consigue todos los Nodo del Stack 
	for (int i = 0; i < M_Elementos; ++i)
	{
		ArregloTemp[i] = &Temp->M_Valor;
		Temp = Temp->GetNext();
	}

	// organiza por Apellidos 
	Sort(ArregloTemp, 0, ArregloTemp.size() - 1, false);

	bool IsEncontrado = false;

	// esto dos valor dictan los indices en donde buscaremos 
	// el valor que no pide el usario .
	int InicioDeArreglo = 0;
	int FinalDeArreglo = ArregloTemp.size() - 1;
	// uso esto para indentificar si encontre el valor
	// que esta buscando el usario 
	int Id = ArregloTemp.size() / 2;


	do
	{
		/*Si no encotramos un el valor en el medio , vamos a
		divir la catidad de indices en donde vamos a buscar
		y siguimos haciendo eso hasta encontra el valor */
		if (ArregloTemp[Id]->M_apellido < ValorParaBuscar)
		{
			//si el valor a buscar es mayor tendermos que quitar toda la 
			// mitad con los numero mas 
			InicioDeArreglo = (InicioDeArreglo + FinalDeArreglo) / 2;
		}
		else if (ArregloTemp[Id]->M_apellido > ValorParaBuscar)
		{
			FinalDeArreglo = (InicioDeArreglo + FinalDeArreglo) / 2;
		}

		Id = (InicioDeArreglo + FinalDeArreglo) / 2;


		if (ArregloTemp[Id]->M_apellido == ValorParaBuscar)
		{
			IsEncontrado = true;
			break;
		}

		// buscar en el centro del area dictado por las dos 
		// variables 


		// si una de estas condiciones se cumple, significa que 
		// solo exite dos mas lugares a verificar 
		// asi que los verifco 
		if (InicioDeArreglo + FinalDeArreglo == 1 || FinalDeArreglo - InicioDeArreglo == 1)
		{
			if (ArregloTemp[InicioDeArreglo]->M_apellido == ValorParaBuscar) {
				IsEncontrado = true;
				Id = InicioDeArreglo;
				break;
			}
			else if (ArregloTemp[FinalDeArreglo]->M_apellido == ValorParaBuscar) {
				IsEncontrado = true;
				Id = FinalDeArreglo;
				break;
			}
			break;
		}
	} while (ArregloTemp[Id]->M_apellido != ValorParaBuscar && InicioDeArreglo < FinalDeArreglo);


	if (IsEncontrado) {
		printf("Aqui el Individuo que buscaba\n ");
		ArregloTemp[Id]->Print();
	}
	else {
		printf(">lo que esta buscando [%s] no existe< \n", ValorParaBuscar.c_str());
	}

}


void Cola::Sort(std::vector<Persona*> &vec, int bajo, int alto, bool IsNombre)
{
	if (bajo < alto) {

		int Pivote = Particion(vec, bajo, alto, IsNombre);

		Sort(vec, Pivote + 1, alto, IsNombre);
		Sort(vec, bajo, Pivote - 1, IsNombre);

	}

}

int Cola::Particion(std::vector<Persona*> &vec, int bajo, int alto, bool IsNombre)
{

	// este es una referencia a un puntero 
	Persona*& Pivote = vec[alto];

	int ElementosMenoresAlPivote = bajo - 1;

	// si la condicion es verdad organizar por
	// nombre .
	if (IsNombre)
	{
		for (int i = bajo; i < alto; ++i)
		{
			if (Pivote->CompararNombre(vec[i]))
			{
				ElementosMenoresAlPivote++;
				if (i != ElementosMenoresAlPivote)
				{
					Persona* Temp = vec[i];
					vec[i] = vec[ElementosMenoresAlPivote];
					vec[ElementosMenoresAlPivote] = Temp;
				}
			}
		}
		Persona* Temp = Pivote;
		Pivote = vec[ElementosMenoresAlPivote + 1];
		vec[ElementosMenoresAlPivote + 1] = Temp;

		return ElementosMenoresAlPivote + 1;
	}
	// si la otra condicion del 'if' no se 
	// cumple entonces organizo por apellido
	else {

		for (int i = bajo; i < alto; ++i)
		{
			if (Pivote->CompararApellido(vec[i]))
			{
				ElementosMenoresAlPivote++;
				if (i != ElementosMenoresAlPivote)
				{
					Persona* Temp = vec[i];
					vec[i] = vec[ElementosMenoresAlPivote];
					vec[ElementosMenoresAlPivote] = Temp;
				}
			}
		}
		Persona* Temp = Pivote;
		Pivote = vec[ElementosMenoresAlPivote + 1];
		vec[ElementosMenoresAlPivote + 1] = Temp;

		return ElementosMenoresAlPivote + 1;

	}
}