#include<iostream>
#include<vector>
#include<string>
#include<cassert>
#include<initializer_list>
#include <typeinfo>

using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length)
		: m_length(length)
	{
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int> &list)
		: IntArray(list.size()) // list[index] : ���� ���� �ο�x
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	IntArray& operator = (const IntArray& source)
	{
		if (this == &source)
			return *this;

		delete[] m_data;

		
		if (source.m_data != nullptr)
		{
			m_length = source.m_length;
			m_data = new int[m_length + 1];

			for (int i = 0; i <= m_length; ++i)
			{
				m_data[i] = source.m_data[i];
			}
		}
		else m_data = nullptr;

		return *this;

	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};

int main(void)
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int* my_arr2 = new int[5] {1, 2, 3, 4, 5};
	
	auto il = { 10,20,30 };

	IntArray int_array = { 1,2,3,4,5,6,7,8,9,10 };
	IntArray copy = {1,2,3,4,5};
	cout << int_array << copy <<endl;
	copy = int_array;
	cout << int_array << copy << endl;
	return 0;
}

// tip
// �ֱٿ� parameter�� �޴� �� ����, return���� �޴� ���� ����
//  subscript operator�� ����� ���� assert�� ����ϴ� ���� �߿�

// 9.1 ��� ������ �����ε� �ϱ�
 // ���: 1. �Ϲ����� �Լ��� �����ε� 2. friend �Լ��� �����ε� 3. ��� func�� ����
 // ���� ���� (�ȵǴ� �͵�): 1. ?:(���⿬����) 2. sizeof 3. ::(������ ������) 4. ���(.) 5. ��� ������ 
  // ������ �켱������ �ٲ� �� ���� -> �������� �͵鸸 ����ϱ�
  // ^�� �켱������ ���⶧����, ���ϴ� �� ����
 /*
	using namespace std;

	class Cents
	{
	private:
		int m_cents;

	public:
		Cents(const int& cents = 0) { m_cents = cents;  }
		int getCents() const { return m_cents;  }
		int& getCents() { return m_cents;  }

		Cents operator + (const Cents& c2)
		{
			return Cents(this->m_cents + c2.getCents());
		}

	};

	int main(void)
	{
		Cents cents1(6);
		Cents cents2(8);

 		// cout << add(cents1, cents2).getCents() << endl;
		cout << (cents1 + cents2 + Cents(6) + Cents(100)).getCents() << endl;

		return 0;
	}

 */
 
// 9.2 ����� ������ �����ε� �ϱ�
 // out, in 
 // ����: 1. ����� ������ �ʰ� ����. 2. ���� ����� ��Ʈ���� ��
 /*
	class Point
	{
	private:
		double m_x, m_y, m_z;

	public:
		Point(double x = 0.0, double y = 0.0, double z = 0.0)
			: m_x(x), m_y(y), m_z(z)
		{}

		double getX() { return m_x; }
		double gety() { return m_y; }
		double getZ() { return m_z; }

		//void print()
		//{
		//	cout << m_x << " " << m_y << " " << m_z << endl;
		//}

		friend std::ostream& operator << (std::ostream& out, const Point& point)
		{
			out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";

			return out;
		}

		friend std::istream& operator >> (std::istream& in, Point& point)
		{
			in >> point.m_x >> point.m_y >> point.m_z;

			return in;
		}
	};

	int main(void)
	{
	
		Point p1, p2;
	
		cin >> p1 >> p2;

		cout << p1 << " " << p2 << endl;
		return 0;
	}
 */

// 9.3 ���� ������(+,-,!) �����ε� �ϱ�
 /*
	class Cents
	{
	private:
		int m_cents;

	public:
		Cents(const int& cents = 0) { m_cents = cents; }
		int getCents() const { return m_cents; }
		int& getCents() { return m_cents; }

		Cents operator - () const
		{
			return Cents(-m_cents);
		}

		bool operator ! () const
		{
			// !Cents(...)
			return (m_cents == 0) ? true : false;
		}
	
		friend std::ostream& operator<< (std::ostream& out, const Cents& cents)
		{
			out << cents.m_cents << " ";
			return out;
		}
	};

	int main(void)
	{
		Cents cents1(6);
		Cents cents2(8);

		cout << !cents1 << " " << !cents2 << endl;

		cout << cents1 << -cents1 << -Cents(-10) << endl;

		int a = 3;
	
		return 0;
	}
 */

// 9.4 �� ������(==, !=, >, >=) �����ε� �ϱ�
 /*
	class Cents
	{
	private:
		int m_cents;

	public:
		Cents(const int& cents = 0) { m_cents = cents; }
		int getCents() const { return m_cents; }
		int& getCents() { return m_cents; }

		friend bool operator == (const Cents& c1, const Cents& c2)
		{
			return (c1.m_cents == c2.m_cents ? true : false);
		}



		friend std::ostream& operator<< (std::ostream& out, const Cents& cents)
		{
			out << cents.m_cents << " ";
			return out;
		}
	};

	int main(void)
	{
		Cents cents1(0);
		Cents cents2(0);
		if (cents1 == cents2) cout << "Equal" << endl;
	
		return 0;
	}
 */

// 9.5. ���� ������ �����ε��ϱ�
/*
	using namespace std;

	class Digit
	{
	private:
		int m_digit;
	public:
		Digit(int digit = 0) : m_digit(digit) {}


		//prefix
		Digit& operator ++()
		{
			++m_digit;

			return *this;
		}

		// post: dummy�� �ϳ� ��(pre�� ����)
		Digit operator ++ (int)
		{
			Digit temp(m_digit);
			++(*this);

			return temp;
		}

		friend ostream& operator << (ostream& out, const Digit& d)
		{
			out << d.m_digit;
			return out;
		}
*/

// 9.6. subscript operator(÷�� ������) �����ε��ϱ�
// ��ȣ ������ �����ε��� �Լ� ��ü
 /*
class IntList
{
private:
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	int& operator [] (const int index)
	{
		assert(index < 10);
		assert(index >= 0);

		return m_list[index];
	}

	const int& operator [] (const int index) const
	{
		assert(index < 10);
		assert(index >= 0);

		return m_list[index];
	}
};

int main(void)
{
	const IntList my_list;
	// my_list[3] = 10;
	
	cout << my_list[3] << endl;
}
 */

// 9.7. parenthesis(��ȣ) ������ �����ε��� �Լ���ü(Functor)
/*
	class Accmulator
	{
	private:
		int m_counter = 0;

	public:
		int operator()(int i) { return (m_counter += i); }

	};

	int main(void)
	{
		Accmulator acc;
		cout << acc(10) << endl;
		cout << acc(20) << endl;

		return 0;
	}
*/

// 9.8. static_cast(typecast(����ȯ)) �����ε��ϱ�
/*
	using namespace std;

	class Cents
	{
	private:
		int m_cents;

	public:
		Cents(const int& cents = 0) { m_cents = cents; }
		int& getCents() { return m_cents; }

		void setCents(int cents) { m_cents = cents; }

		operator int()
		{
			cout << "cast here" << endl;
			return m_cents;
		}
	};

	class Dollar
	{
	private:
		int m_dollars = 0;

	public:
		Dollar(const int& input) : m_dollars(input) {}

		operator Cents()
		{
			return Cents(m_dollars * 100);
		}
	};

	void printInt(const int& value)
	{
		cout << value << endl;
	}

	int main(void)
	{
		Dollar dol(2);
		Cents cents = dol;

		printInt(cents);
		return 0;
	}
*/

// 9.9. ���������, �����ʱ�ȭ, RVO(Return Value Optimization)
/*
	class Fraction
	{
	private:
		int m_numerator;
		int m_denominator;

	public:
		Fraction(int num = 0, int den = 1)
			: m_numerator(num), m_denominator(den)
		{
			assert(den != 0);
		}

		Fraction(const Fraction& fraction) // copy cnstructor
			: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
		{
			cout << "Copy constructor called" << endl;
		}

		friend std::ostream& operator << (std::ostream& out, const Fraction& f)
		{
			cout << f.m_numerator << "/" << f.m_denominator << endl;
			return out;
		}
	};

	int main(void)
	{
		Fraction frac(3, 5);

		Fraction fr_copy(frac); // fr_copy = frac

		cout << frac << " " << fr_copy << endl;
		return 0;
	}
*/

// 9.10. ��ȯ ������, explicit, delete
 // delete: ������ ���� �ڹ�
 // explicit: ��Ȯ�ϰ� �ۼ��ϵ��� ���� ���
/*
class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction) // copy cnstructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		cout << f.m_numerator << "/" << f.m_denominator << endl;
		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main(void)
{
	Fraction frac(7);

	// delete: ������ ���� �ڹ�
	 // Fraction frac('c');
	// explicit: ��Ȯ�ϰ� �ۼ��ϵ��� ���� ���
	 // doSomething(7);
}
*/

// 9.11. ���� ������ �����ε�, ���� ����(Deep copy) vs ���� ����(Shallow copy)

 // shallow copy: deafalut�� �⺻ ���� �����ڷ� ���� �����Ѵ�.
 // Deep copy: �޸� ������ ���� �Ҵ� �޾� ���� �����ؿ��� ��.
 // copy constructor(MyString str1 = hello) vs Assignment operator(str1 = hello) 
 // shallow copy�� ���� ����å? delete�� ���´�. (Class(const class &source) = delete)
/*
	class MyString
	{
	//private:
	public:
		char* m_data = nullptr;
		int m_length = 0;

	public:
		MyString(const char* source = "")
		{
			assert(source);

			m_length = std::strlen(source) + 1;
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source[i];

			m_data[m_length - 1] = '\0';
		}

		MyString(const MyString& source)
		{
			cout << "Copy constructor" << endl;

			m_length = source.m_length;

			if (source.m_data != nullptr)
			{
				m_data = new char[m_length];
				for (int i = 0; i < m_length; ++i)
					m_data[i] = source.m_data[i];
			}
			else
				m_data = nullptr;
		}

		MyString& operator = (const MyString& source)
		{
			// shallow copy
			 // this->m_data = source.m_data;
			 // this->m_length = source.m_length;

		cout << "Assignment operator" << endl;

		if (this == &source) // prevent self self-assignment
			return *this;
	
		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
		m_data = nullptr;

		return *this;
		}

		~MyString()
		{
			delete[] m_data;
		}

		char* getString() { return m_data; }
		int getLength() { return m_length; }
	};
*/

// �̴ϼȶ����� ����Ʈ(std::initializer_list)
/*
	using namespace std;

	class IntArray
	{
	private:
		unsigned m_length = 0;
		int* m_data = nullptr;

	public:
		IntArray(unsigned length)
			: m_length(length)
		{
			m_data = new int[length];
		}

		IntArray(const std::initializer_list<int> &list)
			: IntArray(list.size()) // list[index] : ���� ���� �ο�x
		{
			int count = 0;
			for (auto& element : list)
			{
				m_data[count] = element;
				++count;
			}
		}

		IntArray& operator = (const IntArray& source)
		{
			if (this == &source)
				return *this;

			delete[] m_data;


			if (source.m_data != nullptr)
			{
				m_length = source.m_length;
				m_data = new int[m_length + 1];

				for (int i = 0; i <= m_length; ++i)
				{
					m_data[i] = source.m_data[i];
				}
			}
			else m_data = nullptr;

			return *this;

		}

		~IntArray()
		{
			delete[] this->m_data;
		}

		friend ostream& operator << (ostream& out, IntArray& arr)
		{
			for (unsigned i = 0; i < arr.m_length; ++i)
				out << arr.m_data[i] << " ";
			out << endl;
			return out;
		}
	};

	int main(void)
	{
		int my_arr1[5] = { 1,2,3,4,5 };
		int* my_arr2 = new int[5] {1, 2, 3, 4, 5};

		auto il = { 10,20,30 };

		IntArray int_array = { 1,2,3,4,5,6,7,8,9,10 };
		IntArray copy = {1,2,3,4,5};
		cout << int_array << copy <<endl;
		copy = int_array;
		cout << int_array << copy << endl;
		return 0;
	}
*/