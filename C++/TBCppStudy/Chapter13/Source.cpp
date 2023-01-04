#include<iostream>
using namespace std;


template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{
	}
	
	template<typename TT>
	void doSomething(TT value)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main(void)
{
	A<char> a_char('A');
	a_char.print();

	a_char.doSomething(char());

	return 0;
}

//tip
 // �Լ� ���ø����� parameter�� �ִ� ��� �ش� type���� �ν���. �ƴϸ� <int> �����ؾ���
 // class template������ � ������ �����ؾ���.

// 13.1 �Լ� ���ø�
 // ����� ���� �ڷ����� ���� (class, struct ,...) -> ������ �����ε��� ���־����.
/*
template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main(void)
{
	std::cout << getMax(1, 2) << std::endl;
	std::cout << getMax(3.14, 1.592) << std::endl;
	std::cout << getMax(1.0f, 3.4f) << std::endl;
	std::cout << getMax('a', 'c') << std::endl;
	return 0;
}
*/

// 13.2 Ŭ���� ���ø�
// explicit instantiation
 // � type���� ��. �׷��� �����Ϸ����� �˷������
  // ex.(main) MyArray<double> my_array(10); / (cpp)  template class MyArray<double>;

// 13.3 �ڷ����� �ƴ� ���ø� �Ű�����
 // ���ø� ����: ����� �ڵ尡 ���ص� int, double, ... ���� ���� �����ϵ�.
 // �Ű������� ������ ���� �����Ǿ���. ����x
 // header�� ��� �ڵ� �� ���� ����.
  //explicit instantiation�� �����. why?  template class MyArray<double,����>; ���ڿ� �� �ݿ��ؾ���. 

// 13.4 �Լ� ���ø� Ư��ȭ
 // Ư���� Ÿ�Կ� ���� ó��

// 13.5 Ŭ���� ���ø� Ư��ȭ
 // template<> class A<char>

// 13.6 ���ø��� �κ������� Ư��ȭ�ϱ�
 // member func Ư��ȭ
  // ���ø� ��ü�� Ư��ȭ�ϴ� �� ����, ����� ���� �Ϻθ� �ϴ� ���� ����
/*
template<class T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int count = 0; count < size; ++count)
			std::cout << (*this)[count] << ' ';
		std::cout << std::endl;
	}
};

template<class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

template<int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	void print()
	{
		for (int count = 0; count < size; ++count)
			std::cout << (*this)[count];
		std::cout << std::endl;
	}
};
*/

// 13.7 �����Ϳ� ���� ���ø� Ư��ȭ
/*
template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{
	}

	void print()
	{
		cout << m_value << endl;
	}
};

template<class T>
class A<T*>
{
private:
	T* m_value;

public:
	A(T* input)
		: m_value(input)
	{
	}

	void print()
	{
		cout << *m_value << endl;
	}
};


int main(void)
{
	A<int> a_int(123);

	a_int.print();

	int temp = 456;
	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();

	double temp_d = 3.141592;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();

	return 0;
}
*/

// 13.8 ��� �Լ��� �� �� �� ���ø�ȭ����
/*
template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{
	}

	template<typename TT>
	void doSomething(TT value)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main(void)
{
	A<char> a_char('A');
	a_char.print();

	a_char.doSomething(char());

	return 0;
}
*/