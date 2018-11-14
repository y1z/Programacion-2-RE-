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

bool Persona::CompararApellido(Persona* OtherPersona)
{
	if(this->M_apellido > OtherPersona->M_apellido)
	{
		return true;
	}
	return false;
}

bool Persona::CompararNombre(Persona &OtherPersona)
{
	if (this->M_nombre > OtherPersona.M_nombre)
	{
		return true;
	}
	return false;
}

void Persona::CrearPersona() {
	std::string Nombre;
	std::string Apellido;
	int Dia = 1;
	int Mes = 1;
	int Year = 1980;

	std::cout << "Porfavor ingresa los datos que pidamos \n"
		<< "Nombre : ";
	std::cin >> Nombre;
	std::cout << "\n Apellido : ";
	std::cin >> Apellido;
	std::cout << "\nahora ingresa la fecha de nacimiento en Orden de \n"
		<< "dd/MM/YYYY : ";
	std::cin >> Dia >> Mes >> Year;
	
	SetValor(Nombre.c_str(), Apellido.c_str(), Dia, Mes, Year);
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

bool Persona::operator==(const std::string &NombreApellido) {

	if (NombreApellido == this->M_nombre) {
		return true;
	}
	return false;
}

bool Persona::operator>(const Persona &persona)
{
	if (this->M_nombre > persona.M_nombre)
	{
		return true;
	}
	return false;
}

bool Persona::operator>(const std::string &persona)
{
	if (this->M_nombre > persona)
	{
		return true;
	}
	return false;
}