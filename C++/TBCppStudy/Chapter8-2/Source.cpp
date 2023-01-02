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
//  논리오류와 코딩 실수 줄이는법: const는 쓸 수 있는 곳에 다 쓰는 것이 좋다!
// 현재 sw기법은 재활용을 잘하는 것이 중요. -> 복잡한 것들을 캡슐화하는 것이 중요
// 캡슐화에서 data를 private로하고 setters, getters를 구현하는 이유 - 만약 변수 이름을 바꾸면 클래스 내에서 해결 가능.
// 생성자의 파라미터가 하나도 없다면() 생략
// 생성자 없을 때는 파라미터가 없는 기본 생성자가 생성됨. but, 생성자가 있다면 기본 생성자를 생성안함
  // 파라미터 있는 생성자 있을때, 문제 해결  1. 기본생성자 만들기 2. parameter default 값 지정(overload문제가 발생할 수 있음)
// parameter가 여러 개 일떄, 가장 오른쪽 parameter에 default값이 없다면 다른 parameter에 default값 지정 불가능
// header에서는 using namespace 같은 건 사용하지 않는 것이 좋음(사용하는 구역에만)
// class에서 func에서 const를 넣을 수 있는 func는 다 넣어주는 것이 좋음.



//8.9 클래스와 const
 // instance 자체를 const로 만들면 member val도 const가 적용됨
 // member func가 const라는 것은 member val를 const인 것을 고려하고 코딩을 하겠다는 선언 
 // copy constructor: 기본적으로 있는 생성자로 복사시에 호출됨. -> overhead가 발생하는 원인 -> 그래서 레퍼런스 사용
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

	// copy constructor이 호출됨.
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

//8.10 정적 멤버 변수
 // static member val는 initialization 불가능
 // 주의사항: 분리 시, header에 두면 컴파일 error, define in cpp(중복 선언 문제) 
 // constructor로 초기화(x) -> inner class로 static member val 주로 초기화함.
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

		// 같은 주소와 같은 값이 출력됨 / st1, st2가 선언하기 전에도 접근 가능함.
		cout << &st1.m_val << " " << st1.m_val << endl;
		cout << &st2.m_val << " " << st1.m_val << endl;

		return 0;
	}
 */

// 8.11 정적 멤버 함수
 // static int fuc() { ... } : 특정 instance 없이 private 멤버를 접근하기위해서 사용
 // 당연히, this포인터는 사용(x)
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

// 8.12 friend 함수와 클래스
 // 접근을 허락해주는 개념으로 캡슐화를 잘하기위해 사용
 // friend class B : B가 class에 모든 접근을 허락 
 // friend void B::doSomething(A& a): B에서 특정 func를 쓸 때만 접근 허락. -> error -> B::doB::doSomething(A& a) body를 밖에 선언
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

// 8.13 익명 객체
 // 재사용을 하지 않을 필요가 없을 때 사용.
 // class명() 이러한 방식으로 사용
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


// 8.14 클래스 안에 포함된 자료형
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
	
	// 접근
	Fruit apple(Fruit::Fruit::FruitType::APPLE);
*/

// 8.15 실행 시간 측정하기
 // 라이브러리: #include<chrono>
 // 주의사항: 1. Release 모드가 실제 시간 