#include<iostream>
#include<cmath>
#include<vector>
#include<array>
#include<tuple>
#include<functional>
#include<cassert>
#include<string>
#include<cstdarg>
using namespace std;

double findAverage(int count, ...)
{
	double sum = 0;
	va_list list;

	va_start(list, count);

	// type�� �̸� ���ص־���.
	for (int arg = 0; arg < count; arg++)
	{
		sum += va_arg(list, int);
	}
	va_end(list);

	return sum / count;
}

int main(int argc, char* argv[])
{
	array<int, 5> my_array{ 1,2,3,4,5 };

	cout << findAverage(5, my_array) << endl;
}

//���� ���� �μ� ����(Call by value)
 /* ���� �����ϴ� �� -> ���ΰ� �Լ������� �ּҰ� �ٸ�
	void doSomething(int y)
	{
		cout << "In func " << y << " " << &y <<endl;
	}
	int main(void)
	{
		int x{6};

		cout << "In main " << x << " " << &y << endl;
	
		doSomething(x); // x : argument (=actual parameters)
		doSomething(x+1);

		return 0;
	}
 */

// ���ҿ� ���� �μ� ����(Call by Reference)
 // ��ȣ�ϴ� ���. ����?? ���ͷ� ����� �־��� �� ���� -> const int &x (but, �ȿ��� ���� �Ұ���)
 // 
 /* ���� ��ü�� �ѱ�� ��� -> ���ΰ� �Լ������� �ּҰ� ����
	void addOne(int &y)
	{
		cout << "In func " << y << " " << &y << endl;
		y = y + 1;
	}

	int main(void)
	{
		int x{5};

		cout << "In main " << x << " " << &x << endl;
		addOne(x);
		cout << "In main " << x << " " << &x << endl;
		return 0;
	}
 */
/* ������ 
	void addOne(int* &y)
	{
		(*y)++;
		cout << "In func " << *y << " " << &y << endl;
	}

	int main(void)
	{
		int x{ 5 };
		int* ptr;

		ptr = &x;

		cout << "In main " << *ptr << " " << &ptr << endl;
		addOne(ptr);
		cout << "In main " << *ptr << " " << &ptr << endl;
		return 0;
	}
*/
/* �迭
	void foo(vector<int> &arr)
	{
		for (auto &n : arr)
			n++;
	}
	int main(void)
	{
		vector<int> arr{ 1,2,3,4 };
		for (const int& n : arr)
			cout << n << " ";
		cout << endl;
		foo(arr);
		for (const int& n : arr)
			cout << n << " ";
		cout << endl;
		return 0;
	}
*/

// �ּҿ� ���� �μ� ����(Call by Address)

// �پ��� ��ȯ ���� (��, ����, �ּ�, ����ü, Ʃ��)
 // 1. ���� �޴´� -> �����ؼ� ���Ƿ� �ӵ��� �帲

 // 2. �ּҸ� ���� -> �Լ����� ������ �Ѿ�� ������Ƿ� ���� ����

 // 3. ���۷����� ���� -> �޸� ������ �����ϰ� ��Ƶΰ� ���۷����� ���� �۾�

 // 4. ���� ���� ����
	/* 1. ����ü
		S getStrct()
		{
			S my_s{ 1,2,3,4 };
			return my_s;
		}

		int main(void)
		{
			S my_s = getStrct();
			cout << my_s.a << endl;
		}
	*/

	/*	2. Ʃ��
		std::tuple<int, double> getTuple()
		{
			int a = 10;
			int d = 3.14;
			return std::make_tuple(a, d);
		}

		int main(void)
		{
			std::tuple<int, double> my_tp = getTuple();
			cout << std::get<0>(my_tp) << endl; // a
			cout << std::get<1>(my_tp) << endl; // d

			// c++ 17
			auto [a, d] = getTuple();
			cout << a << endl;
			cout << d << endl;
			return 0;
		}
	*/

// �ȶ��� �Լ�
 // cout << (5 > 6 ? 6 : 5) << endl; ó�� ������ �ܰ迡�� ���� ������ ó���ϰ� ��. 
 // �����Ϸ����� �ش޶�� ��û�ϴ� ���̰� �����Ϸ��� inline�� ������ �� ����
/*
	inline int min(int x, int y)
	{
		return ((x > y) ? y : x);
	}

	int main(void)
	{
		cout << min(5, 6) << endl;
		cout << min(3, 2) << endl;
	}
*/

// �Լ� �����ε�
 // ������ �Լ��� ������ ����� ��
 // ������ �Ű������� �ٸ��� �Լ� ����� ����� �� �ַ� ��� 
 // ������ �� ��, ���� �´� � �Լ��� ������ �� ���� (return type�δ� ���� x. argument�� parameter�� ����)
 /*
	int add(int x, int y)
	{
		return x + y;
	}

	double add(double x, double y)
	{
		return x + y;
	}

	int main(void)
	{
		add(1, 2);
		add(3.0, 4.0);
		return 0;
	}
 */

// �Ű������� �⺻��
 // �Ű������� �⺻���� ���� argument �Է��� �����ϴ� ���
 // �ַ� header���� �⺻ ������ ����. (�Ѵٴ� x)
 /*
	void print(int x = 10, int y =20, int z = 30)
	{
		cout << x << " " << y << " " << z << endl;
	}

	int main(void)
	{
		print(100);
		print(100, 200);
		print(100, 200, 300);
	}
 */

// �Լ� ������
 // �Լ��� �����ͷ� �ּҸ� ������ �ְ� �ش� ������ ó���ϴ� ��
 /*
	int func()
	{
		return 5;
	}

	int goo()
	{
		return 10;
	}
	int main(void)
	{
		int(*fcnptr)() = func;
		cout << fcnptr() << endl;

		fcnptr = goo;
		cout << fcnptr() << endl;

		// functional ���
		std::function<bool(const int&)> fcnptr;

		return 0;
	}
 */

//std::vector�� ����ó�� ����ϱ�
 // ���ο� new�� delete�� ���� ȣ���ϵ��� �ϴ� ���� �߿�
 /*

	std::vector<int> v{ 1,2,3 };
	std::vector<int> stack;

	v.resize(2);

	// size: ��� ��� , capacity: ������ �ִ� �޸�

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl; // 2 ,3���� ��µ�

	// v.reserve(number) - �޸� ���� �̸� Ȯ�� >> capacity�� ���̰� �ø� �ʿ䰡 ��� ȿ���� ����(���� ���� ���� ����)
	stack.push_back(3);
	stack.push_back(5);
	stack.push_back(7);
	stack.pop_back();
	stack.pop_back();
	stack.pop_back();
 */

// ����� �Լ� ȣ��

// ����� ���α׷����� ����
 // syntax error
 // semantic errors(���α׷��Ӱ� �Ű����ϴ� �κ�)	
 // violated assumption
 /* Runtime ���� -> �޸� �＼���� ������ ������ �������ش�.
   string hello = "Hello, my name is Jack jack"
   int ix;
   cin >> ix; // 1004 �Է�
   cout << hello[ix] << endl;
 */

// �ܾ��ϱ� assert #include<cassert>
 // �����Ϸ��� ������ �޴� ��
 /*
	void printValue(const array<int, 5> &my_array, const int &ix)
	{
		// Debug mode������ ����
		// Runtime error�� �߻��ϱ� ������, ��� ������ �߻��ߴ��� �� �� ����.
		assert(ix >= 0);
		assert(ix <= my_array.size() - 1);
	}

	int main(void)
	{

		array<int, 5> my_array{ 1,2,3,4,5 };
		printValue(my_array, 100);

		// static_assert(����+����, "����") - ������ ��, ������ �߻�
	}
 */

// ����� �μ�
	/*
	int main(int argc, char* argv[])
	{
		for (int count = 0; count < argc; ++count)
		{
			std::string argv_single = argv[count];

			if (count == 1)
			{
				int input_number = std::stoi(argv_single);
				cout << input_number << endl;
			}
			cout << argv_single << endl;
		}
	}
	*/

// ������ȣ Ellipsis (#include<cstdarg>)
 // ������ �¾ƾ��ϰ� va_arg���� type�� �̸� �����ؾ��� 
 // �Ű������� ������ �������ʰ� ���
 /*
	double findAverage(int count, ...)
	{
		double sum = 0;
		va_list list;

		va_start(list, count);

		// type�� �̸� ���ص־���.
		for (int arg = 0; arg < count ; arg++)
			sum += va_arg(list, int);

		va_end(list);

		return sum / count;
	}

	int main(int argc, char* argv[])
	{
		cout << findAverage(1, 1, 2, 3, "Hello", "c") << endl;
		cout << findAverage(3, 1, 2, 3) << endl;
		cout << findAverage(5, 1, 2, 3, 4 ,5) << endl;
		cout << findAverage(10, 1, 2, 3, 4, 5) << endl; // ������ �߸��Ǿ� ����
	}
 */

// tip
// ���ҿ� ���� �μ� ����(Call by Reference)
  // �Է� ���� const�� �տ�, ��� ���� �ڿ� ���´�. ex. void getSinCos(const double degrees, double &sin_out, double &cos_out) 
  // ��� �ϴ� ���� const�� ���� ���� + ȣ���� �� ���� �Ͽ� �ϴ� ���� static���� ���� ex. static const double pi = 3.141592;
  // �Է� ���� const int &x�� ���� ������ ��� (why? ���ͷ� ����� ���� �� �ְ� �޸� ���� ���� ����)
  // typedef int* pint; -> �̷�������� �ַ� �����ؼ� ���