#include <iostream>
#include <string>

#define LOG(x) std::cout<<x<<std::endl;

// se asegura que algo 
#ifndef NOMBRE_RARO
#define NOMBRE_RARO
void test() {

}

#endif // !1


// se asegura que algo solo se incluye 
// una sola vez 
#pragma once 



void Stop() {
	std::cin.ignore();
	std::cin.get();
}

class Person {
private:
	// determina el primer nombre de nuestra persona 
	std::string M_name;
	// determina el a
	std::string M_lastName;
	short M_age;
public:
	Person(std::string Name, std::string LastName, short age) 
		:M_name(Name),M_lastName(LastName),M_age(age)
	{

	}
public:

	std::string GetString() {
		return M_name + " " + M_lastName + " edad " + std::to_string(M_age) +"\n";
	}
public:
	short operator -(Person &person) 
	{
		return (M_age - person.M_age);

	}

	short operator -(short i)
	{
		return (M_age - i);

	}

};

std::ostream& operator << (std::ostream& stream, Person& person)
{
	return stream << person.GetString();
}

int main() {
	LOG("Overrding Operators");
	Person Daniiel("Daniel", "juan", 20);
	Person Bob("Bob", "gaytan", 18);

	std::cout << Bob;
	std::cout << Daniiel;

	std::cout << "La Diferencia de edad es " << (Daniiel - Bob)<<"\n";

	std::cout << "La Diferencia de edad es " << (Daniiel - 30) << "\n";

	Stop();

	return 0;
}