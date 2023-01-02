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

// 지역 변수의 범위와 지속기간
 // 변수가 살아 남을 수 있는 곳에서만 선언
 // namespace 안에 namespace 가능
 // namespace work1::work11::work111 이러한 방식으로 선업 가능

// 전역 변수, 정적 변수, 내부 연결, 외부 연결
// 전역 변수 - 모든 영역에서 사용가능한 변수
// 방법 - 메인문 밖에
// 정적 변수 -  static int a / 메모리 초기화를 한번만 진행함 -> 선언 시, 무조건 초기화 해야됨
// ::value - 영역지정연산자를 통해 다른 영역의 변수 사용가능

// 외부연결 - forward declaration > 어딘가 있겠지라는 생각
 // extern void doSomething(); extern int a;
 // 주의 사항

// 정리
/*
	int g_x; // external linkage
	static int g_x // internal linkage
	const int g_x // X
	
	exterrn int g_z;
	exterrn const int g_z;

	int g_y(1);
	static int g_y(1); // 다른 cpp에서 x
	const int g_y(1); // 같은 파일에서만
	
	extern int g_w(1); 
*/

// Using문과 모호성
 // using namespace std - 만약 cout이 호출되었을 때 std에서 한번 찾아보게함
 // 모호성 - 1. 영역을 쪼갠다. 2. 큰 영역에 좋지 않음.(전역에서 사용하는건 피하는 것이 좋음)
 // 선언 시, 취소할 수 있는 방법은 없음
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

// Auto 키워드와 자료형 추론
 // auto : 초기화할 때 자동으로 자료형이 결정됨  -> 함수에도 리턴 타입을 안외워도됨 
  // 파라미터에는 사용 x
  // auto add(int x, int y) -> int; 이러한 방식으로 꼬리 남기기 가능 (코드 리뷰가 쉬움)

// 암시적 형변환과 명시적 형변환
 // typeid('변수 or value').name() - 어떠한 데이터타입인지 출력가능
 // 암시적 형변환 - 컴파일러가 자동으로 형변환
  // 1. 작은 것 -> 큰 것 : 큰 것으로 반영  2. numeric conversion : 할 수 있는 최선으로 컴퓨터가 넣어줌 (문제 생김)
  // 우선 순위 : int, unsigned int, long, unsinged long, long long, unsigned long long, float, double, long double
 // 명시적 형변환
  // 방법 1. int(a) 2. (int)a 3. static_cast<int>a
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

	// unsinged가 우선순위가 높아서 error
	cout << 5u - 10u;
*/

// 문자열 (#include <string>)
 // string my_hello 
 // std::getline - \n이 들어올 때 까지 입력을 받음. (cin은 공백문자를 마지막 문자라고 인식)
 // std::cin.ignore(32767,'\n') - '\n'이 오기까지 32767개 글자를 날려버리기
 // string 사용자 정의 변수는 문자열 끼리 덧셈 가능
 // a.length() - 길이를 알 수 있음
/*
	using namespace std;
	const string my_hello = "Hello, world";
	const char my_strs[] = "Hello, world"; // 모든 초기화 방법 사용가능

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

// 열거형
 // int와 완전 호환되진 않으므로 casting을 통해 변환하여 사용
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

// 영역 제한 열거형 (열거형 클래스)
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
	
		// if(color == fruit) - enum class 지정 시 비교 x


		return 0;
	}
*/

// 자료형에게 가명 붙히기
 // 1. using 2. typedef
/*
	int main(void)
	{
		using namespace std;

		typedef double distance_t; // double를 거리를 재는 단위로 쓸꺼다는 주석 겸 메모 / 코드 유지 관리 편함
		//typedef vector<pair<string, int>> pairlist_t;
		using pairlist_t = vector<pair<string, int>>;s

		pairlist_t pairlist1;
		pairlist_t pairlist2;
		double   my_distance;
		distance_t home2work;

		return 0;
	}
*/

// 구조체
 // padding - 컴파일하기 쉽게 btye가 추가됨. 그래서, 순서와 사이즈를 맞추는게 프로그램을 빠르게 만들기 위해 중요
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