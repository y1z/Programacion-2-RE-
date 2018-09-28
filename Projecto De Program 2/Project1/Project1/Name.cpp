#include <ostream>
#include "Name.hpp"

Name::Name(std::string str)
{
    m_name = str;
}

Name::Name(const char *str)
{
    m_name = str;
}

std::string Name::getValue()
{
    return m_name;
}

void Name::operator=(const char *str)
{
    m_name = str;
}

bool Name::operator==(Name name)
{
    return m_name == name.getValue();
}



std::ostream &operator<<(std::ostream &str, Name &v)
{
    return str << v.getValue();
}

int Name::getSize()
{
	return m_name.size();
}

int Name::getAlphabeticalValue() 
{
	int Resultado = 0;
	for (int i = 0; i < 2; ++i)
	{
		Resultado += m_name[i];
	}
	return Resultado;
}
