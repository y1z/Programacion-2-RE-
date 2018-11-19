#pragma once
#include<iostream>

class LOG
{
public:
	LOG();

	~LOG();

	// Niveles de log 
	const int M_LogError = 1;
	const int M_LogAvertencia = 2;
	const int M_LogInfo = 3;

	int M_LogLevel = 0;
public:

	void info(const char* mensage);

	void Warn(const char* mensage);

	void error(const char* mensage);

	template<class _T>
	void Informar(const char* mensage, _T Dato1, _T Dato2)
	{
		if(M_LogLevel == M_LogInfo)
		std::cout << mensage<<' ' << Dato1 << ' ' << Dato2<<'\n';
	}

	void ShowLogLevel();

	void setLevel(int i);


};
