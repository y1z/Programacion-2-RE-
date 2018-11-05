#include "Stack.h"

Stack::Stack()
{
}

Stack::Stack(int x)
{	
	AumentarElementos(x);
}

Stack::Stack(const char Name[], const char Apellido[], int day, int month, int year) {
	// los nodo contiene una clase persona 
	Nodo *Temp = new Nodo(Name, Apellido, day, month, year);

	//si no tiene elementos el stack 
	//usamos el primer Nodo del stack 
	NextNodo = Temp;
	Temp = nullptr;
	M_Elementos++;
}

Stack::~Stack()
{
	// borro todos los nodos 
	for (int i = 0; i < (M_Elementos - 1); ++i)
	{
		NextNodo->Pop();
	}
	delete NextNodo;
}

void Stack::Push()
{
	// creo al nodo que contiene La Clase Persona

	Nodo* NodoAdicional = new Nodo;

	ptr_Head = NodoAdicional;
	/*Estod dos son para guardar los Nombre y 
	Apellido de la clase Persona */
	std::string Nombre;
	std::string Apellido;

	/*Son para los valores que determinan cuando nacio 
	 la persona en cuestion Y como ,los valores en 
	 cuestion representan dia ,meses y  años
	 sus valore no puede logicamente ser 0 	
	 dado que no existe dia o mes representado por 
	  0*/
	unsigned int Dia = 1;
	unsigned int Mes = 1;
	unsigned int Year = 2000;


	std::cout << "porfavor ingresa un Nombre ,Apellido y fecha de nacimiento\n" << "en el siguente formato dd/mm/yyyy ";
	std::cin >> Nombre;
	std::cin >> Apellido;
	std::cin >> Dia >> Mes >> Year;

	// El nodo contiene la clase persona 
	// uso este metodo para settiar los 
	//valore de la instancia 
	NodoAdicional->M_Valor.SetValor(Nombre.c_str(), Apellido.c_str(), Dia, Mes, Year);

	if (M_Elementos < 1) {
		NextNodo = NodoAdicional;
	}
	else {
		this->NextNodo->PushDouble(NodoAdicional);
	}
	// esto para saber cuantos elementos tengo 
	M_Elementos++;
}

// borro el elemento que esta al final del
// Stack .
void Stack::Pop() {
	if(M_Elementos > 1)
	{
		Nodo* ptr_temp;
		ptr_temp = ptr_Head;
		ptr_temp = ptr_temp->GetPrev();
		ptr_Head->PrevNodo = nullptr;
		ptr_temp->Pop();
		ptr_temp->NextNodo = nullptr;
		ptr_Head = ptr_temp;
	}
	else {
		delete ptr_Head;
		ptr_Head = nullptr;
	}

	M_Elementos--;
}

void Stack::BuscarValor() {
	// para saber que valor esta 
	// buscado el usario 
	std::string Valor;
	/*Este nodo se sera usado para
	ver si lo que */
	Nodo * ptr_temp = ptr_Head;
	Nodo *ptr_Copia = nullptr;
	// para cuando tengo el mismo nombre 
	// en mulpiles lugares 
	bool IsRepetido = false;
	// por si no encontro el nombre o apellido 
	// por ningun lugar en la lista 
	bool IsEncontrado = false;

	Persona * ptr_Persona = nullptr;

	std::cout << "\nDame un nombre o apellido a buscar \n";
	std::cin >> Valor;

	for (int i = M_Elementos; i > 0; --i)
	{
		if(ptr_temp->M_Valor == Valor)
		{
			ptr_Persona = &ptr_temp->M_Valor;

			if (IsRepetido == false) {
				std::cout << "aqui el usario qu bucaba \n\n";
				ptr_Persona->Print();
				IsRepetido = true;
				IsEncontrado = true;
			}
			else
			{
				ptr_Persona->Print();
			}
		}
		ptr_Copia = ptr_temp;
		ptr_temp = ptr_temp->GetPrev();
	}

	if (IsEncontrado == false) {
		std::cout << "no Pudimos encontrar el [" << Valor << "] en la Pila \n";
	}
}

// solo llama la fucion push x cantidad 
// de veces 
void Stack::AumentarElementos(int x)
{
	for (int i = 0; i < x; ++i) {
		this->Push();
	}
}

void Stack::PrintList()
{
	if(M_Elementos > 0)
	{
		Nodo *tem = ptr_Head;
		for (int i = 0; i < M_Elementos; ++i)
		{
			tem->PrintValue();
			tem = tem->GetPrev();
		}
		tem = nullptr;
	}
	else{
		std::cout << "No hay elementos en la Pila \n";
	}
}

void Stack::BusquedaBinariaNombre()
{
	std::string ValorParaBuscar;
	std::cout << "Digame que es el nombre que quiere buscar \n Aqui -->";
	std::cin >> ValorParaBuscar;
	// uso punteros hacia los valores originales 
	// para consumir menos memoria 
	std::vector <Persona*> ArregloTemp;
	// para hacer espacio para tanto,preintivamente 
	ArregloTemp.resize(M_Elementos);

	Nodo* Temp = ptr_Head;

	for (int i = 0; i < M_Elementos; ++i)
	{
		ArregloTemp[i] = &Temp->M_Valor;
		Temp = Temp->GetPrev();
	}
	Sort(ArregloTemp, 0, ArregloTemp.size() - 1);

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
		printf("Aqui el usario que buscaba\n ");
		ArregloTemp[Id]->Print();
	}
	else {
		printf("lo que esta buscando [%s] no existe \n",ValorParaBuscar.c_str());
	}

	std::cin.get();
}

void Stack::Sort(std::vector<Persona*> &vec,int bajo, int alto) {
	if(bajo < alto)
	{
		int pivote = Particion(vec, bajo, alto);

		Sort(vec, bajo, pivote - 1);
		Sort(vec, pivote + 1, alto);
	}
}

int Stack::Particion(std::vector<Persona*> &vec, int bajo, int alto)
{
	// este es una referencia a un puntero 
	Persona*& Pivote = vec[alto];
	int ElementosMenoresAlPivote = bajo - 1;
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

/*



a>o>v>r

vector = new Vector();
sort (vector);
10

int init = 0;
int fin =  vector.size();
int id = fin / 2;

if(vector[id] < str)

init = id + 1
id = init + (fin - init) / 2; // 8

vector.size()


a
o
r
v





*/