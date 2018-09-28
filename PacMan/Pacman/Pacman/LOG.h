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
	const int M_LogSeguro = 3;

	int M_LogLevel = 0;
public:

	void info(const char* mensage);

	void Warn(const char* mensage);

	void error(const char* mensage);

	void ShowLogLevel();

	void setLevel(int i);




};
