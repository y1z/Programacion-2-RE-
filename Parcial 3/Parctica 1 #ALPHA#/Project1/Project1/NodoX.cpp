#include "NodoX.h"

NodoX::NodoX()
{
}

NodoX::NodoX(const char Name[], const char Apellido[], int day, int month, int year)
{
	this->M_Persona.SetValor(Name, Apellido, day, month, year);
}

NodoX::~NodoX()
{
}

// dicta a donde ira el valor 
// en el arbol binario 
bool NodoX::CompararPersona(Persona &persona)
{
	// Compara los valores 'M_nombre' 
	if (this->M_Persona > persona)
	{return true;}

	return false;
}

void NodoX::CrearPersona() 
{this->M_Persona.CrearPersona();}

// funcion recursiva 
void NodoX::Push(NodoX *NuevoNodo) 
{
	// compara las personas 
	bool IsMayor = CompararPersona(NuevoNodo->M_Persona);

	// si el valor que comparamos es mayor que el 
	// nodo actual entonces vamos a mover
	switch (IsMayor)
	{
		// Cuando el valor es Mayor al Nodo actual 
	case (true) :
		if(ptr_Mayor == nullptr)
		{
			ptr_Mayor = NuevoNodo;
		}
		else {
			ptr_Mayor->Push(NuevoNodo);
		}
		break;
		// Cuando el valor es Menor al Nodo actual 
	case (false):
		if (ptr_Menor == nullptr) {
			ptr_Menor = NuevoNodo;
		}
		else {
			ptr_Menor->Push(NuevoNodo);
		}
		break;
	default:
		fprintf(stderr, "ERROR con la Incercion de Nodos");
		break;
	}
}

// funcion recursiva
// pre-Orden 
bool NodoX::Seach(const char Buscar[]) {
	bool IsEncontrado = false;

	if(this->M_Persona == Buscar)
	{
		std::cout << "El Idividuo que busca \n"
			<< "--------------------------------\n";
		M_Persona.Print();
		std::cout<< "---------------------------------\n";
		IsEncontrado = true;
		return IsEncontrado;
	}
	else if (!(this->M_Persona > Buscar) && ptr_Menor != nullptr) {
		IsEncontrado =  this->ptr_Menor->Seach(Buscar);
	}
	else if (this->M_Persona > Buscar && ptr_Mayor != nullptr) {
		IsEncontrado = this->ptr_Mayor->Seach(Buscar);
	}

	return IsEncontrado;
}

// funcion recursiva 
// pre-Orden
bool NodoX::SeachForPop(std::vector<NodoX*> &Camino, const std::string &Buscar)
{
	bool IsEncontrado = false;
	NodoX* temp = this;
	if(this->M_Persona == Buscar)
	{
		Camino.emplace_back(this);
		IsEncontrado = true;
	}
	else if (!(this->M_Persona > Buscar) && ptr_Menor != nullptr){
		Camino.emplace_back(this);
		// verifica si el valor que estamos buscando esta 
		// en algun otro nodo 
		IsEncontrado = 	temp->ptr_Menor->SeachForPop(Camino, Buscar);
	}
	else if (this->M_Persona > Buscar && ptr_Mayor != nullptr) {
		Camino.emplace_back(this);
		// verifica si el valor que estamos buscando esta 
		// en algun otro nodo 
		IsEncontrado = temp->ptr_Mayor->SeachForPop(Camino, Buscar);
	}
	return IsEncontrado;
}

// funcion recursiva 
// post-orden
void NodoX::PopAll()
{
	/*Cuando un Nodo llama esta funcion 
	se va a borra a si mismo y a todo nodo 
	Conectado a el */

	if (ptr_Mayor != nullptr) {
		ptr_Mayor->PopAll();
		ptr_Mayor = nullptr;
	}

	if (ptr_Menor != nullptr) {
		ptr_Menor->PopAll();
		ptr_Menor = nullptr;
	}
	
	 delete this;
}

// solo verifica si tiene 2 hijos el nodo 
// actual 
bool NodoX::VerificarHijos(NodoX *ptr_nodo)
{
	// si tiene 2 hijos entoces regersar true 
	if(ptr_nodo->ptr_Mayor != nullptr && ptr_nodo->ptr_Menor != nullptr)
	{
		return true;
	}
	return false;
}

void NodoX::Pop() {
	// aqui gradamos el valor que busca el usario
	std::string ValorABuscar;
	// voy a contener todos los nodo que voy 
	// a mover para la operacion Pop .
	std::vector<NodoX*> Camino;
	// este sera el valor que debo quitar del arbol 
	NodoX* ptr_ParaEliminar = nullptr;
	// esto sera para los nodo anteriories 
	NodoX* ptr_Ayacientes = nullptr;
	std::cout << "Porfavor Ingresa el valor que desa quitar \n";
	std::cin >> ValorABuscar;

	// buscamos el valor que no pide el usario 
	if(SeachForPop(Camino, ValorABuscar))
	{
		// Consiguimos el valor que desamos quitar del 
		// arbol 
		ptr_ParaEliminar = Camino[Camino.size() - 1];
		// verificamos si es una hoja(no tiene hijo) 
		if (ptr_ParaEliminar->ptr_Mayor == nullptr
			&& ptr_ParaEliminar->ptr_Menor == nullptr) {
			// verificamos que no sea la raiz 
			if (Camino.size() > 1) 
			{
				ptr_Ayacientes = Camino[Camino.size() - 2];
				// quitamos el padre 
				if (ptr_Ayacientes->ptr_Mayor == ptr_ParaEliminar)
				{
					ptr_Ayacientes->ptr_Mayor = nullptr;
				}
				else
				{
					ptr_Ayacientes->ptr_Menor = nullptr;
				}
				// Eliminamos el Nodo desiado 
				delete ptr_ParaEliminar;
				ptr_ParaEliminar = nullptr;
			}
		}
		/*esta condicion verifica que el nodo solo tenga un
		hijo(en este caso seria mayor al actual)  */
	else if (ptr_ParaEliminar->ptr_Mayor != nullptr 
			&& ptr_ParaEliminar->ptr_Menor == nullptr)
		 {
			// consiguimos el nodo anterior para hacer la
			// operacion de borrarlo .
			ptr_Ayacientes = Camino[Camino.size() - 2];
				// hacemos que el Nodo anterior apunte al 
				// hijo del nodo siguente 
			if(ptr_Ayacientes->ptr_Mayor == ptr_ParaEliminar)
			{
				ptr_Ayacientes = ptr_ParaEliminar->ptr_Mayor;
				ptr_ParaEliminar->ptr_Mayor = nullptr;
			}
			else {
				ptr_Ayacientes = ptr_ParaEliminar->ptr_Mayor;
				ptr_ParaEliminar->ptr_Mayor = nullptr;
			}
			delete ptr_ParaEliminar;
			ptr_ParaEliminar = nullptr;
		 }
		/*esta condicion verifica que el nodo solo tenga un
		hijo(en este caso seria el Menor al actual) */
	else if (ptr_ParaEliminar->ptr_Mayor == nullptr
			&& ptr_ParaEliminar->ptr_Menor != nullptr)
		 {
			ptr_Ayacientes = Camino[Camino.size() - 2];
			// hacemos que el Nodo anterior apunte al 
			// hijo del nodo siguente 
			if (ptr_Ayacientes->ptr_Mayor == ptr_ParaEliminar)
			{
				ptr_Ayacientes = ptr_ParaEliminar->ptr_Menor;
				ptr_ParaEliminar->ptr_Menor = nullptr;
			}
			else {
				ptr_Ayacientes = ptr_ParaEliminar->ptr_Menor;
				ptr_ParaEliminar->ptr_Menor = nullptr;
			}
			delete ptr_ParaEliminar;
			ptr_ParaEliminar = nullptr;
		
		 }
		// lo que hacemos cuando el nodo a quitar tien 2 
		// hijos es , crear 2 punteros temporales a los hijos
		// borrar el padre luego unsado nodo Padre (del nodo que 
		// borramos ) usamo la funcion push para desicdir a 
		// donde van a ir los hijos 
	else if (ptr_ParaEliminar->ptr_Mayor != nullptr
				&& ptr_ParaEliminar->ptr_Menor != nullptr)
		 {
			  ptr_Ayacientes = Camino[Camino.size() - 2];
			  NodoX *NodoMayor = ptr_ParaEliminar->ptr_Mayor;
			  NodoX *NodoMenor = ptr_ParaEliminar->ptr_Menor;

			  if(ptr_Ayacientes->ptr_Mayor == ptr_ParaEliminar)
			  {
				  ptr_Ayacientes->ptr_Mayor = nullptr;
			  }
			  else {
				  ptr_Ayacientes->ptr_Menor = nullptr;
			  }
			  ptr_ParaEliminar->ptr_Mayor = nullptr;
			  ptr_ParaEliminar->ptr_Menor = nullptr;
			  
			  ptr_Ayacientes->Push(NodoMenor);
			  ptr_Ayacientes->Push(NodoMayor);
			  
			  delete ptr_ParaEliminar;
			  ptr_ParaEliminar = nullptr;
			  NodoMayor = nullptr;
			  NodoMenor = nullptr;
		 }
 
	}
	else {
		std::cout << "no esta el individuo que buscaba \n";
	}
}

// para navergar el arbol 
NodoX* NodoX::GetMayor()
{
	if (this->ptr_Mayor != nullptr) {
		return this->ptr_Mayor;
	}
	else {
		return this;
	}
}

// para navergar el arbol 
NodoX* NodoX::GetMenor()
{
	if (this->ptr_Menor != nullptr) {
		return this->ptr_Menor;
	}
	else {
		return this;
	}
}

void NodoX::Print() {
	this->M_Persona.Print();
}