#pragma once
#include <iostream>

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

void LineaExtra(int X) {
	for (int i = 0; i < X; ++i) {
		printf("\n");
	}
}