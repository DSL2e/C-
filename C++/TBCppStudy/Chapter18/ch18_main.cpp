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

	//	// 5byte 이동 후 읽기
	//	ifs.seekg(5); // ifs.seekg(5, ios::beg)
	//	cout << (char)ifs.get() << endl;

	//	// 현재 위치에서 5byte 이동 후 읽기
	//	ifs.seekg(5, ios::cur);
	//	cout << (char)ifs.get() << endl;

	//	//// 거꾸로 / tellg() -> 현재 위치
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
		iofs.put('A'); // 덮어쓰기
	}
	return 0;
}

// 18.1 istream으로 입력받기
 // 중요한 이유? file stream에서 동일하게 기능을 사용할 수 있음. 여러 복잡한 파일 포맷들을 읽어드릴 수 있음
 // setw(n): buffer로부터 해당하는 숫자 만큼 가져온다.
 // cin: 빈칸을 없애고 받아줌
 // cin.get(변수,'크기지정가능'): 빈칸도 받아준다.
 // cin.getline(변수,'크기지정가능'): '\n'까지 읽어옴
 // cin.gcount(): 몇글자 읽었는데 알려줌
 // cin.ignore('number'): number만큼 무시함.
 // cin.peek(): 버퍼에서 꺼내올 첫번째를 보여줌
 // cin.unget(): 버퍼에서 마지막으로 꺼낸 것을 다시 버퍼 넣어줌.
 // cin.putback('문자'): 버퍼에 해당 문자를 넣어줌
/*
#include<string>
#include<iomanip> // input//output manipulators

using namespace std;

int main(void)
{
	{
		char buf[10];
		// setw(n): buffer로부터 해당하는 숫자 만큼 가져온다.
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

	// 버퍼 사이즈 고려안하고 받아야됨
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

// 18.2 ostream으로 출력하기
/*
#include<iomanip> // input//output manipulators

using namespace std;

int main(void)
{
	//cout.setf('flag') 출력 flag를 지적
	{
		cout.setf(std::ios::showpos);
		cout << 108 << endl; // output: 106

		cout.unsetf(std::ios::showpos);
		cout << 109 << endl; // output: 109

		// cout.unsetf(std::ios::dec);
		cout.setf(std::ios::hex, std::ios::basefield);
		// cout << std::hex; - #include<iomanip>에서 setf안쓰고 사용하는 방식
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
		// cout << std::fixed; // 소수점 자리가 고정
		// cout << std::scientific << std::uppercase;
		cout << std::showpoint; // 소수점이 안보일때 보여줌
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
		//os.str("Hello, world\n"); // 덮어쓰기

		string str;

		str = os.str();

		cout << str << endl;
	}

	{
		// 공백문자에 따라 나누어 저장됨
		os << "12345 67.89";
		string str1;
		string str2;

		os >> str1 >> str2;
		cout << str1 << "|" << str2;

		int i2;
		double d2;

		os >> i2 >> d2;

		cout << i2 << "|" << d2 << endl;

		// stringstream 비우기
		os.str("");
		os.clear();
		cout << os.str() << endl;
	}

	return 0;
}
*/

// 18.4 stream 상태와 입력 유효성 검증
 // https://cplusplus.com/
 // printStates: stream.good(), stream.fail(), stream.eof(), stream.bad() 
 // #include <ctype.h>: isalpha, isblank, islower, ... 많은 검증 함수들이 구현되어 있음(레퍼런스 참고)
/*
void printStates(const std::ios& stream)
{
	cout << std::boolalpha;		// boolalpha option ON
	cout << "Good() = " << stream.good() << '\n';	// 모든 error state flag가 0일 때 flag가 true가 된다.
	cout << "eof() = " << stream.eof() << '\n';		// stream의 end of file에 도달하면 flag가 true가 된다.
	cout << "fail() = " << stream.fail() << '\n';	// error state flag가 하나라도 1일 경우 flag가 true가 된다.
	cout << "bad() = " << stream.bad() << '\n';		// 데이터를 읽거나 쓸 때 에러가 발생할 때 flag가 true가 된다.
}

void printCaracterClassification(const char& input)
{
	cout << std::boolalpha;
	cout << "isalpha = " << bool(std::isalpha(input)) << '\n';	// 입력받은 게 문자인지?
	cout << "isalnum = " << bool(std::isalnum(input)) << '\n';	// 입력받은 게 문자 또는 숫자인지?
	cout << "isblank = " << bool(std::isblank(input)) << '\n';	// 입력받은 게 공백인지?
	cout << "isdigit = " << bool(std::isdigit(input)) << '\n';	// 입력받은 게 숫자인지?
	cout << "islower = " << bool(std::islower(input)) << '\n';	// 입력받은 게 소문자인지?
	cout << "isupper = " << bool(std::isupper(input)) << '\n';	// 입력받은 게 대문자인지?
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

// 18.5 정규 표현식 소개
 // 입력받거나 읽어온 데이터를 판별하기 위해 사용하는 정규 표현식
/*
int main()
{
	regex re("\\d"); // 숫자 판별, +: 한개이상, *: 입력 안받아도 괜찮다
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

// 18.6 기본적인 파일 이출력
/*
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // exit()
#include<sstream>
using namespace std;

int main()
{
	// ASCII (속도 정말 느림)
	if (false)
	{
		{//writing
			if (false)
			{
				ofstream ofs("my_first_file.dat"); // mode- ios::app, ios::binary, ios::append
				// ofs.opn("파일이름");

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
	 // 데이터의 저장양을 미리 알고 있어야함.
	if (false)
	{
		{//writing
			if (true)
			{
				ofstream ofs("my_first_file.dat"); // ios::app, ios::binary
				// ofs.oepn("파일이름");

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

		//출력 데이터 문자열에 저장하고 파일에 넣기
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

// 18.7 파일의 임의 위치 접근하기
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

		// 5byte 이동 후 읽기
		ifs.seekg(5); // ifs.seekg(5, ios::beg)
		cout << (char)ifs.get() << endl;

		// 현재 위치에서 5byte 이동 후 읽기
		ifs.seekg(5, ios::cur);
		cout << (char)ifs.get() << endl;

		//// 거꾸로 / tellg() -> 현재 위치
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
		iofs.put('A'); // 덮어쓰기
	}
	return 0;
}
*/