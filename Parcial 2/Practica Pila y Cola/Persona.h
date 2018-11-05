#pragma once
#include <string>
#include <iostream>

class Persona {

public:

	Persona();
	Persona(const char Nombre[], const char Apellido[], int Dia, int Mes, int Year);

	virtual~Persona();

public:// variables
	std::string M_nombre;
	std::string M_apellido;
	int M_DayNacimiento =1;
	int M_MesNacimiento = 1;
	int M_YearNacimiento = 1980;
public:// metodos 
	void Print();
	void SetValor(const char Nombre[], const char Apellido[], int Dia, int Mes, int Year);
	bool CompararNombre(Persona* OtherPersona);
	bool CompararApellido(Persona* OtherPersona);
	//bool CompararNombreYApellido(Persona* OtherPersona);
public:
	// Operadores sobreCagados 
	void operator=(Persona &persona);
	bool operator==(const std::string &persona);

};
