#include"LOG.h"

using std::cout;
using std::endl;

LOG::LOG() 
{}

LOG::~LOG()
{}

void LOG::info(const char* mensage) {
	if (M_LogLevel >= M_LogSeguro)
		cout << "[info]" << mensage << endl;
}

void LOG::error(const char* mensage) {
	if (M_LogLevel >= M_LogError)
		cout << "[ERROR] " << mensage << endl;

}

void LOG::Warn(const char* mensage) {
	if (M_LogLevel >= M_LogAvertencia)
		cout << "[WARN]" << mensage << endl;
}

void LOG::setLevel(int i) {
	M_LogLevel = i;
}

void LOG::ShowLogLevel() {
	cout << M_LogLevel << endl;
}