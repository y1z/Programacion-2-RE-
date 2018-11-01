#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;

void Stop() {
	cin.ignore();
	cin.get();
}

class pet {
public:
	virtual void Walk() {
		cout << "Estoy Caminando boyiyiyiyiiy \n";
	}
};

class cat : public pet {
	public:
	void Walk()override {
		cout << " soy un pussy \n";
	}
};

class dog : public pet{
public:
	void Walk()override {
		cout << " soy un prro \n";
	}
};

class Person {
public:
	void makeWalk(pet &pet) {

		pet.Walk();
	}
};

int main() {
	cat kurroMew;
	dog pancho;

	Person thing;
	thing.makeWalk(kurroMew);
	thing.makeWalk(pancho);
	Stop();

	return 0;
}