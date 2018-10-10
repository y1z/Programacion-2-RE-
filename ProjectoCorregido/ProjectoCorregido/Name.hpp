#pragma once

#include <string>

class Name
{
  private:
    std::string m_name;

  public:
    Name(std::string str);
    Name(const char *str);

    std::string getValue();

    void operator=(const char *str);
    bool operator==(Name name);
	bool operator<(Name &name);

    //TODO add your required methods
public:
	int getSize();
	

};

std::ostream &operator<<(std::ostream &str, Name &v);