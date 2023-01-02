#include "Calc.h"

int main(void)
{
	Calc cal(10);

	cal.add(10).sub(5).mult(2).divi(10).print();
}


// 8.1 객체지향 프로그래밍과 클래스
 // Object: 데이터와 기능이 묶여있는 것
  // 사용 시 장점? 가독성이 좋아져 코드를 간결하게 해주어 시간과 실수할 확률을 줄여줌
 // 구조체 : 일반적으로 데이터를 묶을 때 사용
 // class : 기능을 넣을 때 사용
  // access specifier (pubilc, private, protected)
  // instanciation,instance : 메모리를 차지하도록 정의하는 것 (ex. Friend jj{"jack", ...})
  /*
	class Friend
	{
	public: // access specifier (pubilc, private, protected)
		string m_name;
		string m_address;
		int    m_age;
		double m_height;
		double m_weight;

		// 데이터를 공유하고 있음.
		void print()
		{
			cout << m_name << " " << m_address << " " << m_age << " " << m_height << " " << m_weight << endl;
		}
	};

	void print(const string& name, const string& address, const int& age, const double& height, const double& weight)
	{
		cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
	}

	int main(void)
	{
		Friend jj{ "Jack","Uptown",2,170,70 };

		// 장점: 가독성이 휠씬 편해짐
		jj.print();

		vector<Friend> my_friends;
		my_friends.resize(2);

		for (auto& ele : my_friends)
			ele, print();

		//vector<string> name_vec;
		//vector<string> addr_vec;
		//vector<int> age_vec;
		//vector<double> height_vec;
		//vector<double> weight_vec;

		return 0;
	}
  */
  
// 8.2 Encapsulation(캡슐화를 위한 도구: Access Specifiers, Accesss Functions)
 // Access Specifiers(pubilc, private, protected) : 기본이 private로 설정되어 접근 불가능
  // private: access func를 사용해서 접근
  /*
	class Date
	{
		int m_month;
		int m_day;
		int m_year;

	public:
		void setDate(const int& month_input, const int& day_input, const int& year_input)
		{
			m_month = month_input;
			m_day = day_input;
			m_year = year_input;
		}
		void setMonth(const int& month_input)
		{
			m_month = month_input;
		}
		const int& getDay() // getters: 주로 const type&로 변경안되게 막음. setters
		{
			return m_day;
		}
		void copyFrom(const Date& original)
		{
			m_month = original.m_month;
			m_day = original.m_day;
			m_year = original.m_year;
		}
	};

	int main(void)
	{
		// 무엇을 하는지 눈에 딱 들어옴
		Date today;
		today.setDate(8, 4, 2025);
		today.setMonth(10);

		cout << today.getDay() << endl;

		// 복사 -> 다른 instance에 private data접근이 가능?? -> 같은 class라면 사용 가능
		Date copy;
		copy.copyFrom(today);
		return 0;
	}
  */

// 8.3 생성자
  // 생성자: 반환 데이터 타입이 없고, class 명과 동일
  // 선언과 동시에 실행 
  // copy, uniform initialzation도 가능함.(ex. Fraction frac{10,20};)
	/*
		class Fraction
		{
			int m_numberator;
			int m_denominator;

		public:
			Fraction(const int& num_in = 0, const int& den_in = 1)
			{
				m_numberator = num_in;
				m_denominator = den_in;
			}

			void print()
			{
				cout << m_numberator << "/" << m_denominator << endl;
			}
		};
		int main(void)
		{
			Fraction frac;
			frac.print();

			Fraction one_thirds(1,3);
			one_thirds.print();
		}

	*/

// 8.4. 생성자의 멤버 이니셜라이져 리스트
	/*
		class B
		{
		private:
			int m_b;

		public:
			B(const int& m_b_in)
				: m_b(m_b_in)
			{}
		};

		class Something
		{
			// 우선순위는 생성자가 높음
			int     m_i = 100;
			double  m_d = 100.0;
			char    m_c = 'F';
			int     m_arr[5] = {5,4,3,2,1};
			B		m_b{1024};

		public:
			Something()
				: m_i{ 1 }, m_d{ 3.14 }, m_c('a'), m_arr{ 1,2,3,4,5 }, m_b(m_i - 1)
			{

			}
			void print()
			{
				cout << m_i << " " << m_d << " " << m_c <<endl;
				for (const auto& e : m_arr)
					cout << e << " ";
				cout << endl;
			}
		};
		int main(void)
		{
			Something s;
			s.print();
		}
	*/

// 8.5 위임 생성자(Delegatin Constructors)
 // 한 변수를 초기화하는 곳은 한 곳에 있는 것이 좋음.
 // 다른 생성자를 사용 하는 것.
 /* c++11
 public:
	Student(const string &name_in)
		: Student(0, name_in)
	{}
	Student(const string &name_in, const string& name_in)
		: m_id(0), m_name(name_in)
	{}

 */
 // 별도의 Init 함수를 하나 두고, 각각 경우에 따라 Init함수 호출하여 초기화

// 8.6 소멸자(Destructor)
 // instance가 메모리에서 해제될 때, 내부에서 자동으로 호출
 // 용도: delete할 때 깔끔하게 사용 가능.
  /*
	class Simple
	{
	private:
		int m_id;

	public:
		Simple(const int& id_in)
			: m_id(id_in)
		{}

		~Simple()
		{
			cout << "Destructor " << m_id << endl;
		}
	};

	int main(void)
	{
		Simple s{ 5 };

		Simple* s1 = new Simple(0);

		delete s1;
		return 0;
	}
  */

// 8.7 this 포인터와 연쇄 호출
  // 같은 class를 사용하는 instance를 어떻게 구별??
  // 개념적으로 instance의 주소를 넘겨주고 처리 > this 
	/*
	class Calc
	{
	private:
		int m_value;

	public:
		Calc(const int& val)
			: m_value(val)
		{
		}

		Calc& add(const int& val) { m_value += val;  return *this; }
		Calc& sub(const int& val) { m_value -= val; return *this; }
		Calc& mult(const int& val) { m_value *= val; return *this; }
		Calc& divi(const int& val) { m_value /= val; return *this; }
		void print()
		{
			cout << m_value << endl;
		}
	};

	int main(void)
	{
		Calc cal(10);

		cal.add(10).sub(5).mult(2).divi(10).print();
	}
	*/

// 8.8 클래스 코드와 헤더 파일
	// header 파일에 선언, cpp로 바디로 넣는다. (header에 바디에 놔두는 경우도 꽤있음)
	// ch.8-1 코드 참조

