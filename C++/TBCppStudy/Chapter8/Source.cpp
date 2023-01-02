#include "Calc.h"

int main(void)
{
	Calc cal(10);

	cal.add(10).sub(5).mult(2).divi(10).print();
}


// 8.1 ��ü���� ���α׷��ְ� Ŭ����
 // Object: �����Ϳ� ����� �����ִ� ��
  // ��� �� ����? �������� ������ �ڵ带 �����ϰ� ���־� �ð��� �Ǽ��� Ȯ���� �ٿ���
 // ����ü : �Ϲ������� �����͸� ���� �� ���
 // class : ����� ���� �� ���
  // access specifier (pubilc, private, protected)
  // instanciation,instance : �޸𸮸� �����ϵ��� �����ϴ� �� (ex. Friend jj{"jack", ...})
  /*
	class Friend
	{
	public: // access specifier (pubilc, private, protected)
		string m_name;
		string m_address;
		int    m_age;
		double m_height;
		double m_weight;

		// �����͸� �����ϰ� ����.
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

		// ����: �������� �پ� ������
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
  
// 8.2 Encapsulation(ĸ��ȭ�� ���� ����: Access Specifiers, Accesss Functions)
 // Access Specifiers(pubilc, private, protected) : �⺻�� private�� �����Ǿ� ���� �Ұ���
  // private: access func�� ����ؼ� ����
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
		const int& getDay() // getters: �ַ� const type&�� ����ȵǰ� ����. setters
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
		// ������ �ϴ��� ���� �� ����
		Date today;
		today.setDate(8, 4, 2025);
		today.setMonth(10);

		cout << today.getDay() << endl;

		// ���� -> �ٸ� instance�� private data������ ����?? -> ���� class��� ��� ����
		Date copy;
		copy.copyFrom(today);
		return 0;
	}
  */

// 8.3 ������
  // ������: ��ȯ ������ Ÿ���� ����, class ��� ����
  // ����� ���ÿ� ���� 
  // copy, uniform initialzation�� ������.(ex. Fraction frac{10,20};)
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

// 8.4. �������� ��� �̴ϼȶ����� ����Ʈ
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
			// �켱������ �����ڰ� ����
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

// 8.5 ���� ������(Delegatin Constructors)
 // �� ������ �ʱ�ȭ�ϴ� ���� �� ���� �ִ� ���� ����.
 // �ٸ� �����ڸ� ��� �ϴ� ��.
 /* c++11
 public:
	Student(const string &name_in)
		: Student(0, name_in)
	{}
	Student(const string &name_in, const string& name_in)
		: m_id(0), m_name(name_in)
	{}

 */
 // ������ Init �Լ��� �ϳ� �ΰ�, ���� ��쿡 ���� Init�Լ� ȣ���Ͽ� �ʱ�ȭ

// 8.6 �Ҹ���(Destructor)
 // instance�� �޸𸮿��� ������ ��, ���ο��� �ڵ����� ȣ��
 // �뵵: delete�� �� ����ϰ� ��� ����.
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

// 8.7 this �����Ϳ� ���� ȣ��
  // ���� class�� ����ϴ� instance�� ��� ����??
  // ���������� instance�� �ּҸ� �Ѱ��ְ� ó�� > this 
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

// 8.8 Ŭ���� �ڵ�� ��� ����
	// header ���Ͽ� ����, cpp�� �ٵ�� �ִ´�. (header�� �ٵ� ���δ� ��쵵 ������)
	// ch.8-1 �ڵ� ����

