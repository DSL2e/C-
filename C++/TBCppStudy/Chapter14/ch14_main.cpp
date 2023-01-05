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

// 14.1 ���� ó���� �⺻
 // ���� ó���� ������ �ٿ�Ǵ� ������ �� ���� �������� �۾��� ���ӵǵ��� �ϴ� ���
 /* // try, catch, throw
	// ���ǻ���: ����ȯ�� �����ϰ� ��.
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
 // c��Ÿ��(������ �ִ��� ���ִ� ���α׷��� ���): �ӵ��� ����
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


// 14.2 ����ó���� ���� �ǰ���
 // ȣ���� ��� �Լ����� �ǰ����鼭 �ش�Ǵ� catch�� ã��.
 // catch (...) : ��� Ÿ���� ���� �� ����
 // exception specifier: void last() throw(int) int���� ���ܸ� ���� �� �ִ� �Լ���� �˷��ִ� �� 
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

// 14.3 ���� Ŭ������ ���
 // error�ѹ� catch�Ǹ� ��
 // rethrow: error�� ��� �ٽ� ������ ��
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

// 14.4 std::exception �Ұ�
 // exception�� ������ �ڽ� Ŭ������ ���� �θ� Ŭ����
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

// 14.5 �Լ� try
 // initialization list���� ���� �߻��ϴ� ���ܸ� ó���ϴµ� ���
 // constructor���� error�� ������ rethrow�� �ϴ� ��ó�� �� �۵�
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

// 14.5 ����ó���� ���輺�� ����
 // 1. �޸� ������ �߻��� �� ����. -> ����Ʈ������::����ũ������ - unique_ptr<type> up_i(i);
 // 2. destructor������ exception�� ���� �� ����.
 // 3. ���� ����ϴ� ������ ����ϸ� �ӵ��� ���� ������.
 // -> ������ ��å�� ������ �� ���� ������ ����ϴ� ���� ����.