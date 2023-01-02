#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

using namespace std;

struct Person
{
	int age;
	double height;
	float weight;
	string name;

	void print()
	{
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}
};
int main(void)
{
	Person me{ 20,173.5,68.4,"Jack Jack" };
	me.print();
	return 0;
}

// ���� ������ ������ ���ӱⰣ
 // ������ ��� ���� �� �ִ� �������� ����
 // namespace �ȿ� namespace ����
 // namespace work1::work11::work111 �̷��� ������� ���� ����

// ���� ����, ���� ����, ���� ����, �ܺ� ����
// ���� ���� - ��� �������� ��밡���� ����
// ��� - ���ι� �ۿ�
// ���� ���� -  static int a / �޸� �ʱ�ȭ�� �ѹ��� ������ -> ���� ��, ������ �ʱ�ȭ �ؾߵ�
// ::value - �������������ڸ� ���� �ٸ� ������ ���� ��밡��

// �ܺο��� - forward declaration > ��� �ְ������ ����
 // extern void doSomething(); extern int a;
 // ���� ����

// ����
/*
	int g_x; // external linkage
	static int g_x // internal linkage
	const int g_x // X
	
	exterrn int g_z;
	exterrn const int g_z;

	int g_y(1);
	static int g_y(1); // �ٸ� cpp���� x
	const int g_y(1); // ���� ���Ͽ�����
	
	extern int g_w(1); 
*/

// Using���� ��ȣ��
 // using namespace std - ���� cout�� ȣ��Ǿ��� �� std���� �ѹ� ã�ƺ�����
 // ��ȣ�� - 1. ������ �ɰ���. 2. ū ������ ���� ����.(�������� ����ϴ°� ���ϴ� ���� ����)
 // ���� ��, ����� �� �ִ� ����� ����
/*
	#include <iostream>

	namespace a
	{
		int my_var = 10;
	}

	namespace b
	{
		int my_var = 20;
	}

	int main(void)
	{
		using namespace std;

		{
			using namespace a;
			cout << my_var << endl; 
		}

		{
			using namespace b;
			cout << my_var << endl;
		}
		return 0;
	}
*/

// Auto Ű����� �ڷ��� �߷�
 // auto : �ʱ�ȭ�� �� �ڵ����� �ڷ����� ������  -> �Լ����� ���� Ÿ���� �ȿܿ����� 
  // �Ķ���Ϳ��� ��� x
  // auto add(int x, int y) -> int; �̷��� ������� ���� ����� ���� (�ڵ� ���䰡 ����)

// �Ͻ��� ����ȯ�� ����� ����ȯ
 // typeid('���� or value').name() - ��� ������Ÿ������ ��°���
 // �Ͻ��� ����ȯ - �����Ϸ��� �ڵ����� ����ȯ
  // 1. ���� �� -> ū �� : ū ������ �ݿ�  2. numeric conversion : �� �� �ִ� �ּ����� ��ǻ�Ͱ� �־��� (���� ����)
  // �켱 ���� : int, unsigned int, long, unsinged long, long long, unsigned long long, float, double, long double
 // ����� ����ȯ
  // ��� 1. int(a) 2. (int)a 3. static_cast<int>a
/*
	using namespace std;

	float a = 1.0f;
	double d = a;

	int i = 30000;
	char c = i;

	cout << static_cast<int>(c) << endl;

	double e = 0.123456789;
	float f = e;
	cout << std::setprecision(12) << f << endl;

	// unsinged�� �켱������ ���Ƽ� error
	cout << 5u - 10u;
*/

// ���ڿ� (#include <string>)
 // string my_hello 
 // std::getline - \n�� ���� �� ���� �Է��� ����. (cin�� ���鹮�ڸ� ������ ���ڶ�� �ν�)
 // std::cin.ignore(32767,'\n') - '\n'�� ������� 32767�� ���ڸ� ����������
 // string ����� ���� ������ ���ڿ� ���� ���� ����
 // a.length() - ���̸� �� �� ����
/*
	using namespace std;
	const string my_hello = "Hello, world";
	const char my_strs[] = "Hello, world"; // ��� �ʱ�ȭ ��� ��밡��

	string my_ID ("123");
	cout << my_hello << endl;

	cout << "Your age ? : ";
	int age;
	cin >> age;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Your name ? : ";
	std::string name;
	std::getline(std::cin, name);

	cout << name << " " << age << endl;
	return 0;
*/

// ������
 // int�� ���� ȣȯ���� �����Ƿ� casting�� ���� ��ȯ�Ͽ� ���
 /*
	enum Color // user-defined data types
	{
		COLOR_BLACK,
		COLOR_RED,
		COLOR_BLUE,
		COLOR_GREEN,
		COLOR_SKYBLUE,
	};

	int main(void)
	{

		using namespace std;

		Color my_color = COLOR_GREEN;
		cout << my_color << endl;
		return 0;
	}
 */

// ���� ���� ������ (������ Ŭ����)
/*
	enum class Color // user-defined data types
	{
		RED,
		BLUE,
	};

	enum class Fruit // user-defined data types
	{
		BANANA,
		APPLE,
	};

	int main(void)
	{
		using namespace std;

		Color color = Color::RED;
		Fruit fruit = Fruit::BANANA;
	
		// if(color == fruit) - enum class ���� �� �� x


		return 0;
	}
*/

// �ڷ������� ���� ������
 // 1. using 2. typedef
/*
	int main(void)
	{
		using namespace std;

		typedef double distance_t; // double�� �Ÿ��� ��� ������ �����ٴ� �ּ� �� �޸� / �ڵ� ���� ���� ����
		//typedef vector<pair<string, int>> pairlist_t;
		using pairlist_t = vector<pair<string, int>>;s

		pairlist_t pairlist1;
		pairlist_t pairlist2;
		double   my_distance;
		distance_t home2work;

		return 0;
	}
*/

// ����ü
 // padding - �������ϱ� ���� btye�� �߰���. �׷���, ������ ����� ���ߴ°� ���α׷��� ������ ����� ���� �߿�
/*
	struct Person
	{
		int age;
		double height;
		float weight;
		string name;

		void print()
		{
			cout << height << " " << weight << " " << age << " " << name;
			cout << endl;
		}
	};
	int main(void)
	{
		Person me{ 20,173.5,68.4,"Jack Jack" };
		me.print();
		return 0;
	}
*/