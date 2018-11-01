#include "Persona.h"

Persona::Persona() 
{}

// asigno todos los valores de la clase 
Persona::Persona(
	const char Nombre[],
	const char Apellido[],
int Dia,
int Mes, 
int Year) 

	:M_nombre(Nombre),
	M_apellido(Apellido),
	M_DayNacimiento(Dia),
	M_MesNacimiento(Mes),
	M_YearNacimiento(Year)
{}

Persona::~Persona() 
{}


void Persona::Print() {
	std::cout << " [Nombre { " << this->M_nombre << " } " << " Apellido { " << this->M_apellido << " } "
		<< "Fecha de Nacimiento " << this->M_DayNacimiento << "/" << this->M_MesNacimiento <<
		"/" << this->M_YearNacimiento << "] \n";
}

// Uso todos estos valore para hacer 
void Persona::SetValor(const char Nombre[], const char Apellido[], int Dia, int Mes, int Year)
{
	this->M_nombre = Nombre;
	this->M_apellido = Apellido;
	this->M_DayNacimiento = Dia;
	this->M_MesNacimiento = Mes;
	this->M_YearNacimiento = Year;
}



// asigno todos los valore de esta Persona
// para que sean iguales a la otra Persona 
void Persona::operator=(Persona &persona)
{
	this->M_nombre = persona.M_nombre;
	this->M_apellido = persona.M_apellido;
	this->M_DayNacimiento = persona.M_DayNacimiento;
	this->M_MesNacimiento = persona.M_MesNacimiento;
	this->M_YearNacimiento = persona.M_YearNacimiento;
}

bool Persona::operator==(const std::string &persona) {

	if (persona == this->M_nombre || persona == this->M_apellido) {
		return true;
	}
	return false;

}


