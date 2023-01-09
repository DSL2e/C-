#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int main(void)
{
	// assign(constructor���� �ε��� �ο� ����),append: �ڱ� �ڽ��� &�� ����
	{
		string str1("one");
		string str2;

		str2 = str1;
		str2 = "two";
		str2.assign("two").append(" ").append("three ").append("four");
		cout << str2 << endl;

	}
	// swap
	{
		string str1("one");
		string str2("two");

		cout << str1 << " " << str2 << endl;
		
		std::swap(str1, str2);

		cout << str1 << " " << str2 << endl;

		str1.swap(str2);

		cout << str1 << " " << str2 << endl;
	}
	// insert
	{
		string str("aaaa");

		str.insert(2, "bbb");

		cout << str << endl;
	}

	return 0;
}

// 17.1 std::string�� �����ڵ�� ����ȯ
 // https://cplusplus.com/reference/string/string/
 /*
template<typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;
	osstream << x;
	return osstream.str();
}

template<typename T>
bool FromString(const std::string &str, T& x)
{
	std::istringstream isstream(str);

	return (isstream >> x) ? true : false;
}

int main(void)
{
	// string ������(.., +container)
	{
		std::string my_string("my string");

		std::vector<char> vec;
		for (auto e : "Today is good day.")
			vec.push_back(e);

		//std::string scend_string(vec.begin(), vec.end()); // output: Today is good day.

		//std::string scend_string(my_string, 3, 2); // output: st

		//std::string scend_string(10, 'A'); // output: AAAAAAAAAA

		//std::string scend_string(vec.begin(),std::find(vec.begin(),vec.end(),'g')); // output: Today is
	}

	// ��ȯ: ���� <-> ����
	{
		std::string my_str(std::to_string(1004));

		my_str += std::to_string(128);
		std::cout << my_str << std::endl;

		int i = std::stoi(my_str);
		std::cout << i << std::endl;

		std::string my_str_2(ToString(3.141592)); // ����� ���ڷ� ��ȯ
		std::cout << my_str_2 << std::endl;

		double d; // ���ڸ� ���ڷ� ��ȯ
		if (FromString(my_str_2, d))
			std::cout << d << std::endl;

		else
			std::cout << "Cannot covert string to double" << std::endl;
	}

	return 0;
}
 */

// 17.2 std::string�� ���̿� �뷮
 // string�� class�̹Ƿ� ���� '\0'�� ����.(��ü������ length�� ������ ����)
 // vector�� ���������� new, delete�� �ϱ� �Ⱦ��Ͽ� ������ ������ ������ ����.
/*
using namespace std;

int main(void)
{
	string my_str("01234567");
	my_str.reserve(1000);
	//cout << my_str.size() << endl;

	cout << std::boolalpha;
	//cout << my_str.empty() << endl;
	cout << my_str.length() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl;
	cout << my_str.max_size() << endl;

	return 0;
}
*/

// 17.3 std::string ���� �����ϱ�� �迭���� ��ȯ
/*
int main(void)
{
	string my_str("abcdefg");

	//try
	//{
	//	//my_str[100] = 'X'; -> ����ó���� �ȵ� (�ӵ��� �߿��� ���)
	//	my_str.at(100) = 'X';
	//}
	//catch (std::exception &e)
	//{
	//	cout << e.what() << endl;
	//}

	// c-style ��� -> '\0'�� �߰���
	 // 1. ~~c_str()
	cout << my_str.c_str() << endl;
	const char* arr = my_str.c_str();

	cout << arr[6] << endl;

	 // 2. ~~.copy(char,������,offset)
	char buf[20];
	my_str.copy(buf, 5, 2);
	buf[5] = '\0';
	cout << buf << endl;

	return 0;
}
*/

// 17.4 std::string ���(����, ��ȯ, �����̱�, ����)
/*
	// assign(constructor���� �ε��� �ο� ����),append: �ڱ� �ڽ��� &�� ����
	{
		string str1("one");
		string str2;

		str2 = str1;
		str2 = "two";
		str2.assign("two").append(" ").append("three ").append("four");
		cout << str2 << endl;

	}
	// swap
	{
		string str1("one");
		string str2("two");

		cout << str1 << " " << str2 << endl;

		std::swap(str1, str2);

		cout << str1 << " " << str2 << endl;

		str1.swap(str2);

		cout << str1 << " " << str2 << endl;
	}
	// insert
	{
		string str("aaaa");

		str.insert(2, "bbb");

		cout << str << endl;
	}

	return 0;
*/