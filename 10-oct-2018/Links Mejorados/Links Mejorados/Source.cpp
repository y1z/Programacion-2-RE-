#include <iostream>
class Node;

class Node
{
	int valor;
	Node *M_NodeNext = nullptr;
public:
	Node(int Value)
		:valor(Value)
	{}
	
	~Node(){
		std::cout << "estoy muerto :( " << valor << std::endl;
		delete M_NodeNext;
		M_NodeNext = nullptr;
	}

	void pushBack(int Value)
	{
		if (M_NodeNext == nullptr)
			M_NodeNext = new Node(Value);
		else
			M_NodeNext->pushBack(Value);
	}

	Node *getNextNode() {return M_NodeNext;}

	int getValue() {return valor;}

	void print() {
		std::cout << valor << std::endl;
		if (M_NodeNext != nullptr) {
		M_NodeNext->print();
		}
	}

	void printAll() {
		if (M_NodeNext != nullptr)
		{
		
		}
	}
};

class List {
	virtual void PushBack(int) = 0;
};

class SingleList :public List
{
	Node *M_NodoStart;
public:
	~SingleList() 
	{
		Clear();
	}
public:
	void PushBack(int Value)
	{
		if(M_NodoStart == nullptr)
		{
			M_NodoStart = new Node(Value);
		}
		else
		{
			M_NodoStart->pushBack(Value);
		}
	}

	void PrintAll() {
		if(M_NodoStart != nullptr)
		{
			M_NodoStart->print();
		}
	}

	void Clear() 
	{
		delete M_NodoStart;
		M_NodoStart = nullptr;

	}
};


int main() {

	SingleList list;

	list.PushBack(2);
	list.PushBack(5);

	list.PrintAll();



	return 0;
}