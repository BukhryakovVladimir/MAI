#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

static  int MaxId = 1;
int MaxSize = 100;

template <class Type>

class Stack
{
public:
	string StackId;
	char buffer[65];
	Type* ST[100];
public: int top;
public: Stack()
{
	top = 0;
	for (int i = 0; i < MaxSize; i++)
	{
		ST[i] = new Type;
	}
	//		StackId = std::to_string(MaxId);
	_itoa_s(MaxId, buffer, 65, 10); //(MaxId, NULL, 10);
	MaxId++;
	StackId = buffer;
	cout << "Создан стек " << StackId + "!" << endl;
}
public: void push(Type c)
{
	if (top < MaxSize)
		*ST[top++] = c;
	else printf("Стек переполнен!");
}
public: Type pop()
{
	if (top > 0)
		return *ST[--top];
	else
	{
		printf("Стек пуст!");
		return "";
	}
}

};

void main()//int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	string r;
	Stack<string>* stack;
	cout << "Создать стек?" << endl;

	getline(cin, r);
	if (r == "да")
		stack = new Stack<string>();
	else return;


	string s;
	do
	{
		cout << "Что сделать?" << endl;
		getline(cin, s);
		if (s == "заложить")
		{
			cout << "Что?" << endl;
			getline(cin, r);
			stack->push(r);
		};
		if (s == "достать")
		{
			cout << stack->pop() << endl;
		};
	} while (s != "Х");
}

