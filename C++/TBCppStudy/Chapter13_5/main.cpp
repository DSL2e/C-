#include<iostream>
#include<array>
#include"Storage8.h"

using namespace std;

//template<typename T>
//class A
//{
//public:
//	void doSomething()
//	{
//		cout << typeid(T).name() << endl;
//	}
//
//	void test()
//	{}
//
//};

// 문법적으로 다른 클래스 구현한 것.
//template<>
//class A<char>
//{
//public:
//	void doSomething()
//	{
//		cout << "char type specialization" << endl;
//	}
//};

int main(void)
{
	//A<int> a_int;
	//A<double> a_double;
	//A<char> a_char;

	//a_int.doSomething();
	//a_double.doSomething();
	//a_char.doSomething();

	// int형
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		std::cout << intStorage.get(count) << "\n";

	// .... 
	return 0;
}