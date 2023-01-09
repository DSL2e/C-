#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // exit()
#include<sstream>
using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);
		
		for (char i = 'a'; i <= 'z'; i++)
			ofs << i;
		ofs << endl;
	}

	// read the file
	//{
	//	ifstream ifs("my_file.txt");

	//	// 5byte �̵� �� �б�
	//	ifs.seekg(5); // ifs.seekg(5, ios::beg)
	//	cout << (char)ifs.get() << endl;

	//	// ���� ��ġ���� 5byte �̵� �� �б�
	//	ifs.seekg(5, ios::cur);
	//	cout << (char)ifs.get() << endl;

	//	//// �Ųٷ� / tellg() -> ���� ��ġ
	//	//ifs.seekg(-5, ios::end);
	//	//cout << ifs.tellg() << endl;
	//	//

	//	string str;
	//	getline(ifs, str);

	//	cout << str << endl;
	//}

	// read and write
	{
		fstream iofs(filename);
		iofs.seekg(5);

		cout << (char)iofs.get() << endl;

		iofs.seekg(5);
		iofs.put('A'); // �����
	}
	return 0;
}

// 18.1 istream���� �Է¹ޱ�
 // �߿��� ����? file stream���� �����ϰ� ����� ����� �� ����. ���� ������ ���� ���˵��� �о�帱 �� ����
 // setw(n): buffer�κ��� �ش��ϴ� ���� ��ŭ �����´�.
 // cin: ��ĭ�� ���ְ� �޾���
 // cin.get(����,'ũ����������'): ��ĭ�� �޾��ش�.
 // cin.getline(����,'ũ����������'): '\n'���� �о��
 // cin.gcount(): ����� �о��µ� �˷���
 // cin.ignore('number'): number��ŭ ������.
 // cin.peek(): ���ۿ��� ������ ù��°�� ������
 // cin.unget(): ���ۿ��� ���������� ���� ���� �ٽ� ���� �־���.
 // cin.putback('����'): ���ۿ� �ش� ���ڸ� �־���
/*
#include<string>
#include<iomanip> // input//output manipulators

using namespace std;

int main(void)
{
	{
		char buf[10];
		// setw(n): buffer�κ��� �ش��ϴ� ���� ��ŭ �����´�.
		cin >> setw(5) >> buf;
		cout << buf << endl;
	}

	{
		char buf[5];

		cin.get(buf, 3);
		cout << cin.gcount() << " "<< buf << endl;

		cin.getline(buf, 100);
		cout << cin.gcount() << buf << endl;
	}

	// ���� ������ ������ϰ� �޾ƾߵ�
	{
		string buf;
		getline(cin, buf);
		cout << cin.gcount() << buf << endl;
	}

	{
		char buf[1024];

		cin.ignore();

		cin >> buf;
		cout << buf << endl;
	}

	{
		cout << (char)cin.peek() << endl;
		cin.unget();
	}
	return 0;
}
*/

// 18.2 ostream���� ����ϱ�
/*
#include<iomanip> // input//output manipulators

using namespace std;

int main(void)
{
	//cout.setf('flag') ��� flag�� ����
	{
		cout.setf(std::ios::showpos);
		cout << 108 << endl; // output: 106

		cout.unsetf(std::ios::showpos);
		cout << 109 << endl; // output: 109

		// cout.unsetf(std::ios::dec);
		cout.setf(std::ios::hex, std::ios::basefield);
		// cout << std::hex; - #include<iomanip>���� setf�Ⱦ��� ����ϴ� ���
		cout << 108 << endl; // output: 6c
		cout << std::dec;
		cout << 110 << endl;

		cout.setf(std::ios::uppercase);
		cout << "ac" << endl;

		cout << std::boolalpha;
		cout << true << " " << false << endl;

	}

	 setprecision
	{
		// cout << std::defaultfloat;
		// cout << std::fixed; // �Ҽ��� �ڸ��� ����
		// cout << std::scientific << std::uppercase;
		cout << std::showpoint; // �Ҽ����� �Ⱥ��϶� ������
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
	}

	{
		cout << -12345 << endl;
		cout.fill('*');
		cout << std::setw(10) << -12345 << endl;
		cout << std::setw(10) << std::left <<-12345 << endl;
		cout << std::setw(10) << std::right <<-12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl;
	}
	return 0;
}
*/

// 18.3 string stream
/*
#include<sstream>
using namespace std;

int main(void)
{
	stringstream os;
	{
		os << "Hello, world"; // << : insertion operator, >> : extraction operator
		os << " Hello, world" << endl; // append
		//os.str("Hello, world\n"); // �����

		string str;

		str = os.str();

		cout << str << endl;
	}

	{
		// ���鹮�ڿ� ���� ������ �����
		os << "12345 67.89";
		string str1;
		string str2;

		os >> str1 >> str2;
		cout << str1 << "|" << str2;

		int i2;
		double d2;

		os >> i2 >> d2;

		cout << i2 << "|" << d2 << endl;

		// stringstream ����
		os.str("");
		os.clear();
		cout << os.str() << endl;
	}

	return 0;
}
*/

// 18.4 stream ���¿� �Է� ��ȿ�� ����
 // https://cplusplus.com/
 // printStates: stream.good(), stream.fail(), stream.eof(), stream.bad() 
 // #include <ctype.h>: isalpha, isblank, islower, ... ���� ���� �Լ����� �����Ǿ� ����(���۷��� ����)
/*
void printStates(const std::ios& stream)
{
	cout << std::boolalpha;		// boolalpha option ON
	cout << "Good() = " << stream.good() << '\n';	// ��� error state flag�� 0�� �� flag�� true�� �ȴ�.
	cout << "eof() = " << stream.eof() << '\n';		// stream�� end of file�� �����ϸ� flag�� true�� �ȴ�.
	cout << "fail() = " << stream.fail() << '\n';	// error state flag�� �ϳ��� 1�� ��� flag�� true�� �ȴ�.
	cout << "bad() = " << stream.bad() << '\n';		// �����͸� �аų� �� �� ������ �߻��� �� flag�� true�� �ȴ�.
}

void printCaracterClassification(const char& input)
{
	cout << std::boolalpha;
	cout << "isalpha = " << bool(std::isalpha(input)) << '\n';	// �Է¹��� �� ��������?
	cout << "isalnum = " << bool(std::isalnum(input)) << '\n';	// �Է¹��� �� ���� �Ǵ� ��������?
	cout << "isblank = " << bool(std::isblank(input)) << '\n';	// �Է¹��� �� ��������?
	cout << "isdigit = " << bool(std::isdigit(input)) << '\n';	// �Է¹��� �� ��������?
	cout << "islower = " << bool(std::islower(input)) << '\n';	// �Է¹��� �� �ҹ�������?
	cout << "isupper = " << bool(std::isupper(input)) << '\n';	// �Է¹��� �� �빮������?
}

bool isAllDigit(const string& str)
{
	bool ok_flag = true;

	for (auto e : str)
		if (!bool(std::isdigit(e)))
		{
			ok_flag = false;
			break;
		}
	return ok_flag;
}

int main()
{
	while (true)
	{
		char i;
		cin >> i;

		printStates(cin);
		printCaracterClassification(i);
		cout << isAllDigit("123345") << endl;

		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
	}

	return 0;
}
*/

// 18.5 ���� ǥ���� �Ұ�
 // �Է¹ްų� �о�� �����͸� �Ǻ��ϱ� ���� ����ϴ� ���� ǥ����
/*
int main()
{
	regex re("\\d"); // ���� �Ǻ�, +: �Ѱ��̻�, *: �Է� �ȹ޾Ƶ� ������
	//regex re("ab");
	//regex re("[[:digit:]]{3}"); // \d = [[:digit:]]
	//regex re("[A-Z]+");
	//regex re("[A-Z]{1,5}");
	//regex re("([0-9]{1})([-]?)([0-9]{1,4})");

	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No match" << endl;

		// print matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();

			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
*/

// 18.6 �⺻���� ���� �����
/*
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // exit()
#include<sstream>
using namespace std;

int main()
{
	// ASCII (�ӵ� ���� ����)
	if (false)
	{
		{//writing
			if (false)
			{
				ofstream ofs("my_first_file.dat"); // mode- ios::app, ios::binary, ios::append
				// ofs.opn("�����̸�");

				if (!ofs)
				{
					cerr << "Couldn't open file " << endl;
					exit(1);
				}

				ofs << "Line 1" << endl;
				ofs << "Line 2" << endl;

				//ofs.close(); not necessary
			}

			//reading
			if (true)
			{
				ifstream ifs("my_first_file.dat");

				if (!ifs)
				{
					cerr << "Connot open file" << endl;
					exit(1);
				}

				while (ifs)
				{
					std::string str;
					getline(ifs, str);

					std::cout << str << endl;
				}
			}
		}
	}

	// binary
	 // �������� ������� �̸� �˰� �־����.
	if (false)
	{
		{//writing
			if (true)
			{
				ofstream ofs("my_first_file.dat"); // ios::app, ios::binary
				// ofs.oepn("�����̸�");

				if (!ofs)
				{
					cerr << "Couldn't open file " << endl;
					exit(1);
				}

				const unsigned num_data = 10;
				ofs.write((char*)&num_data, sizeof(num_data));

				for (int i = 0; i < num_data; ++i)
					ofs.write((char*)&i, sizeof(i));
			}

			//reading
			if (true)
			{
				ifstream ifs("my_first_file.dat");

				if (!ifs)
				{
					cerr << "Connot open file" << endl;
					exit(1);
				}

				unsigned num_data = 0;
				ifs.read((char*)&num_data, sizeof(num_data));

				for (unsigned i = 0; i < num_data; ++i)
				{
					int num;
					ifs.read((char*)&num, sizeof(num));

					std::cout << num << endl;
				}
			}
		}

		//��� ������ ���ڿ��� �����ϰ� ���Ͽ� �ֱ�
		{
			stringstream ss;
			ss << "Line 1" << endl;
			ss << "Line 2" << endl;
			string str = ss.str();

			unsigned str_length = str.size();
			ofs.write((char*)&str_length, sizeof(str_length));
			ofs.write(str.c_str(), str_length);

			//read
			unsigned str_len = 0;
			ifs.read((char*)str_len, sizeof(str_len));

			string str;
			str.resize(str_len);
			ifs.read(&str[0], str_len);

			cout << str << endl;
		}
	}
	return 0;
}
*/

// 18.7 ������ ���� ��ġ �����ϱ�
/*
int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; i++)
			ofs << i;
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs("my_file.txt");

		// 5byte �̵� �� �б�
		ifs.seekg(5); // ifs.seekg(5, ios::beg)
		cout << (char)ifs.get() << endl;

		// ���� ��ġ���� 5byte �̵� �� �б�
		ifs.seekg(5, ios::cur);
		cout << (char)ifs.get() << endl;

		//// �Ųٷ� / tellg() -> ���� ��ġ
		//ifs.seekg(-5, ios::end);
		//cout << ifs.tellg() << endl;
		//

		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	// read and write
	{
		fstream iofs(filename);
		iofs.seekg(5);

		cout << (char)iofs.get() << endl;

		iofs.seekg(5);
		iofs.put('A'); // �����
	}
	return 0;
}
*/