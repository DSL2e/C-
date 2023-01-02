#include<iostream>
#include<string>
#include<vector>
#include<chrono>
using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};


int main(void)
{

	return 0;
}

//tip
//  �������� �ڵ� �Ǽ� ���̴¹�: const�� �� �� �ִ� ���� �� ���� ���� ����!
// ���� sw����� ��Ȱ���� ���ϴ� ���� �߿�. -> ������ �͵��� ĸ��ȭ�ϴ� ���� �߿�
// ĸ��ȭ���� data�� private���ϰ� setters, getters�� �����ϴ� ���� - ���� ���� �̸��� �ٲٸ� Ŭ���� ������ �ذ� ����.
// �������� �Ķ���Ͱ� �ϳ��� ���ٸ�() ����
// ������ ���� ���� �Ķ���Ͱ� ���� �⺻ �����ڰ� ������. but, �����ڰ� �ִٸ� �⺻ �����ڸ� ��������
  // �Ķ���� �ִ� ������ ������, ���� �ذ�  1. �⺻������ ����� 2. parameter default �� ����(overload������ �߻��� �� ����)
// parameter�� ���� �� �ϋ�, ���� ������ parameter�� default���� ���ٸ� �ٸ� parameter�� default�� ���� �Ұ���
// header������ using namespace ���� �� ������� �ʴ� ���� ����(����ϴ� ��������)
// class���� func���� const�� ���� �� �ִ� func�� �� �־��ִ� ���� ����.



//8.9 Ŭ������ const
 // instance ��ü�� const�� ����� member val�� const�� �����
 // member func�� const��� ���� member val�� const�� ���� ����ϰ� �ڵ��� �ϰڴٴ� ���� 
 // copy constructor: �⺻������ �ִ� �����ڷ� ����ÿ� ȣ���. -> overhead�� �߻��ϴ� ���� -> �׷��� ���۷��� ���
 /*
    class Something 
	{
	public:
		int m_val = 0;

		void setVal(int val)
		{
			m_val = val;
		}
		int getVal() const
		{
			return m_val;
		}

	};

	// copy constructor�� ȣ���.
	void print(const Something &st)
	{
		cout << st.getVal() << endl;
	}

	int main(void)
	{
		const Something something;

		// (error) something.setVal(3); 
	
		print(something);
	
		// (error) cout << something.getVal() << endl;

		return 0;
	}
 */

//8.10 ���� ��� ����
 // static member val�� initialization �Ұ���
 // ���ǻ���: �и� ��, header�� �θ� ������ error, define in cpp(�ߺ� ���� ����) 
 // constructor�� �ʱ�ȭ(x) -> inner class�� static member val �ַ� �ʱ�ȭ��.
 /*
	class Something
	{
	public:
		static int m_val;

	};

	int Something::m_val = 1;


	int main(void)
	{
		cout << &Something::m_val << " " << Something::m_val << endl;

		Something st1;
		Something st2;

		st1.m_val = 2;

		// ���� �ּҿ� ���� ���� ��µ� / st1, st2�� �����ϱ� ������ ���� ������.
		cout << &st1.m_val << " " << st1.m_val << endl;
		cout << &st2.m_val << " " << st1.m_val << endl;

		return 0;
	}
 */

// 8.11 ���� ��� �Լ�
 // static int fuc() { ... } : Ư�� instance ���� private ����� �����ϱ����ؼ� ���
 // �翬��, this�����ʹ� ���(x)
 /*
	class Something
	{
	public:

		class _init
		{
		public:
			_init()
			{
				m_val = 1234;
			}
		};

	private:
		static int m_val;
		int m_d;

		static _init s_initializer;

	public:
	
		Something()
			: m_d(1024)
		{
		}
		static int getValue()
		{
			return m_val;
		}
	};

	int Something::m_val;
	Something::_init Something::s_initializer;

	int main(void)
	{
		cout << Something::getValue() << endl;

		Something st1;

		cout << st1.getValue() << endl;
		// cout << st1.m_val << endl;
		return 0;
	}
 */

// 8.12 friend �Լ��� Ŭ����
 // ������ ������ִ� �������� ĸ��ȭ�� ���ϱ����� ���
 // friend class B : B�� class�� ��� ������ ��� 
 // friend void B::doSomething(A& a): B���� Ư�� func�� �� ���� ���� ���. -> error -> B::doB::doSomething(A& a) body�� �ۿ� ����
 /*
	// forward declaration
	class A;

	class B
	{
	private:
		int m_value = 2;

	public:
		void doSomething(A& a);
	};

	class A
	{
	private:
		int m_value = 1;

		friend void B::doSomething(A& a);

	};

	void B::doSomething(A& a)
	{
		cout << a.m_value << endl;
	}

	int main(void)
	{

		return 0;
	}// forward declaration
	class A;

	class B
	{
	private:
		int m_value = 2;

	public:
		void doSomething(A& a);
	};

	class A
	{
	private:
		int m_value = 1;

		friend void B::doSomething(A& a);

	};

	void B::doSomething(A& a)
	{
		cout << a.m_value << endl;
	}

	int main(void)
	{

		return 0;
	}
 */

// 8.13 �͸� ��ü
 // ������ ���� ���� �ʿ䰡 ���� �� ���.
 // class��() �̷��� ������� ���
 /*
	class A
	{
	public:
		int m_val;
	
		A(const int& input)
			: m_val(input)
		{
			cout << this << ":" <<"constructor" << endl;
		}
		~A()
		{
			cout << this<<":" << "destructor" << endl;
		}
		void print() const
		{
			cout << m_val << endl;
		}
	};


	int main(void)
	{
		A a(1);
		a.print();

		A(5).print();

		return 0;
	}
 */


// 8.14 Ŭ���� �ȿ� ���Ե� �ڷ���
/*
	class Fruit
	{
	public:
		enum class FruitType
		{
			APPLE, BANANA, CHERRY,
		};
		class InnerClass
		{
		....
		};

		struct InnerStruct
		{
		...
		};
	};
	
	...
	
	// ����
	Fruit apple(Fruit::Fruit::FruitType::APPLE);
*/

// 8.15 ���� �ð� �����ϱ�
 // ���̺귯��: #include<chrono>
 // ���ǻ���: 1. Release ��尡 ���� �ð� 