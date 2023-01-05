#include<iostream>
#include<exception>
#include<string>
#include<memory>
using namespace std;

int main(void)
{
	int i = 10;
	unique_ptr<int> up_i(&i);

	cout << *up_i << endl;

	return 0;
}

// 14.1 예외 처리의 기본
 // 예외 처리는 서버가 다운되는 예측할 수 없는 문제에서 작업이 지속되도록 하는 방법
 /* // try, catch, throw
	// 주의사항: 형변환을 엄격하게 함.
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) throw std::string("Negative input");

		cout << std::sqrt(x) << endl;
	}
	catch (std::string error_message)
	{
		cout << error_message << endl;
	}

	return 0;
 */
 // c스타일(오류를 최대한 없애는 프로그래밍 기법): 속도가 빠름
 /*
int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
	{
		if (string[index] == ch)
			return index;

		return -1; // no match
	}
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}

	success = true;

	return static_cast<double>(x) / y;
}

int main(void)
{
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error oucurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	//std::ifstream input_file("temp.txt");
	//if (!input_file)
	//	std::cerr << "cannot open file" << std::endl;

	return 0;
}
*/


// 14.2 예외처리와 스택 되감기
 // 호출한 모든 함수들을 되감으면서 해당되는 catch를 찾음.
 // catch (...) : 모든 타입을 받을 수 있음
 // exception specifier: void last() throw(int) int형의 예외를 던질 수 있는 함수라고 알려주는 것 
/*
using namespace std;
void last()
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "lsat end " << endl;
}

void third()
{
	cout << "third" << endl;

	last();

	cout << "third end " << endl;
}

void second()
{
	cout << "second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "second caught double exception" << endl;
	}
	cout << "second end " << endl;
}

void first()
{
	cout << "frist" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}
	cout << "frist end " << endl;
}

int main(void)
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}


	cout << "End main" << endl;
	return 0;
}
*/

// 14.3 예외 클래스와 상속
 // error한번 catch되면 끝
 // rethrow: error를 잡고 다시 던지는 것
/*
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};


class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array report" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];
	
public:
	int& operator [] (const int& index)
	{
		if (index < 0 || index >= 5) throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}

	catch (Exception & e)
	{
		e.report();
		//throw e;
		throw;
	}
}

int main(void)
{
	try
	{
		doSomething();
	}
	catch (ArrayException& e)
	{
		e.report();
	}

	catch (Exception& e)
	{
		e.report();
	}
	return 0;
}
*/

// 14.4 std::exception 소개
 // exception은 수많은 자식 클래스를 가진 부모 클래스
/*
using namespace std;

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "custom exception";
	}
};

int main(void)
{
	try
	{
		//std::string s;
		//s.resize(-1);

		//throw std::runtime_error("Bad thing happened");
throw CustomException();
	}

	catch (std::exception& exception)
	{
		std::cout << typeid(exception).name() << std::endl;
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}
*/

// 14.5 함수 try
 // initialization list에서 많이 발생하는 예외를 처리하는데 사용
 // constructor에서 error를 잡으면 rethrow를 하는 것처럼 또 작동
/*
class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};
class B : public A
{
public:
	//B(int x) : A(x)
	//{
	//}

	B(int x) try : A(x)
	{

	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		//throw
	}
};
int main(void)
{
	try
	{
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	return 0;
}
*/

// 14.5 에외처리의 위험성과 단점
 // 1. 메모리 누수가 발생할 수 있음. -> 스마트포인터::유니크포인터 - unique_ptr<type> up_i(i);
 // 2. destructor에서는 exception를 던질 수 없음.
 // 3. 많이 사용하는 루프에 사용하면 속도가 많이 떨어짐.
 // -> 논리적인 대책을 마련할 수 없는 곳에만 사용하는 것이 좋다.