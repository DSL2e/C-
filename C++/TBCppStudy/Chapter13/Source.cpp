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
 // 함수 템플릿에서 parameter가 있는 경우 해당 type으로 인식함. 아니면 <int> 지정해야함
 // class template에서는 어떤 것인지 지정해야함.

// 13.1 함수 템플릿
 // 사용자 정의 자료형도 가능 (class, struct ,...) -> 연산자 오버로딩이 되있어야함.
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

// 13.2 클래스 템플릿
// explicit instantiation
 // 어떤 type인지 모름. 그래서 컴파일러한테 알려줘야함
  // ex.(main) MyArray<double> my_array(10); / (cpp)  template class MyArray<double>;

// 13.3 자료형이 아닌 템플릿 매개변수
 // 템플릿 원리: 사람이 코드가 안해도 int, double, ... 따로 따로 컴파일됨.
 // 매개변수도 컴파일 전에 결정되야함. 변수x
 // header에 모든 코드 다 집어 넣음.
  //explicit instantiation이 어려움. why?  template class MyArray<double,숫자>; 숫자에 다 반영해야함. 

// 13.4 함수 템플릿 특수화
 // 특정한 타입에 대해 처리

// 13.5 클래스 템플릿 특수화
 // template<> class A<char>

// 13.6 템플릿을 부분적으로 특수화하기
 // member func 특수화
  // 템플릿 전체를 특수화하는 것 보단, 상속을 통해 일부만 하는 것이 편함
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

// 13.7 포인터에 대한 템플릿 특수화
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

// 13.8 멤버 함수를 한 번 더 템플릿화히기
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