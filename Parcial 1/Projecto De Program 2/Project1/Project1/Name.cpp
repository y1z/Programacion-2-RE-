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

bool Name::operator<(Name &name) 
{
	if(this->m_name.size() == name.getSize())
	{
		return this->m_name[0] < name.m_name[0];
	}
	else {
		return this->getSize() < name.getSize();
	}
}

std::ostream &operator<<(std::ostream &str, Name &v)
{
    return str << v.getValue();
}

int Name::getSize()
{
	return m_name.size();
}

