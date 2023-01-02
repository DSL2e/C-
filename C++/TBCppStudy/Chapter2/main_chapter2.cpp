#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

int main(void)
{
	using namespace std;

	const double gravity{ 9.8 };
	
	return 0;
}

/* 기본 자료형 소개 */
  // auto aValue = 3.141592; > 자동으로 결정됨
  // sizeof - 메모리 공간을 차지하는 양을 알려줌
  // 변수 초기화 : 1. copy initialization - a=123 / 2. direct initialization - a(123) 3. uniform initializtion - a{123} > 가장 엄격함.
  // 최근엔 사용할 변수를 바로 직전에 사용하는 것을 선호 (1. 디버깅을 하기 좋음 2. 변수와 기능을 리팩토링하기 편함)

/* 정수형 */
 // long long : 8byte , sizeof(short)
 // 범위 : 한 비트는 부호를 표현 >> 핵심은 크기의 제한이 있다.
 // overflow : 넘치면 가장 작은 수로 돌아감 -> error가 안잡힘
 // 많이하는 실수 : 정수끼리의 연산은 정수 ex. float i = 22 / 5 -> 4출력됨 (float)붙혀야함.
 /* 코드
	using namespace std;
	short s = 1;
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;
	cout << std::numeric_limits<short>::max()<<endl;
	cout << std::numeric_limits<short>::min()<<endl;

	s = 32767;
	s = s + 1; // 32768
	cout << s << endl; // overflow
	return 0;
 */

/* 고정 너비 정수 */
  // int16_t : 2byte로
  // int8_t : 1byte로 ex. myint = 65; -> a
  // int_fast8_t :  8bit 사이즈 중에 가장 빠른거 
  // int8_least64_t : 적어도 8byte

/* 무치형 (Void, 보이드) */
  /* 코드
   int i = 10;
   void *my_void;
   my_void = (void *)&i;
  */

/* 보동소수점 수 */
  // float , double, Long double
  // 과정 : 부호 / 지수 / 가수
  // 초기화 ; float f = 3.14e2;
  // 소수점제한 : #include <iomanip>
               //  cout << std::steprecision(12) << 1.0 / 3.0 << endl;
  // 주의사항
  /*
  // 1. 정밀도가 날라감
	using namespace std;
	float f(123456789.0f);
	cout << std::setprecision(12);
	cout << f << endl;

  // 2. 가장 가까운 수가 출력됨
	using namespace std;
	float d(0.1);
	cout << std::setprecision(17);
	cout << d << endl;
  
  // 3. 2의 오차 누적
	using namespace std;
	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	cout << std::setprecision(17);
	cout << d1 << endl;
	cout << d2 << endl;

  // 4. 0으로 나눈 것
   double zero = 0.0;
   double = posinf = 5.0 / zero;
   >> 디버깅 #include<cmath> std::isnan -> bool타입으로 알려줌
  */ 

/* 불리언 자료형과 조건문 */
 // bool : true(1) or false(0)
 // cout << std::boolalpha; - true / false로 출력
 // if ~ else : if는 0이 아니라면 true로 판단
 //or(||), and(&&). ==. != , ...
 /*코드
  	using namespace std;
	bool b1 = true;
	bool b2(false);
	bool b3{ true };
	b3 = false;

	cout << std::noboolalpha;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << !b3 << endl;
 */

/* char */
 // c-style casting : cout << (char)65 << endl 
 // cpp-style casting : cout << char(65) << endl
 // (문제 없는 지 체크) static casting : cout << static_cast<char>(65) << endl;
 // wchar_t c , char16(32)_t : 유니코드

/* 리터럴 상수 */
 /* 코드
 	using namespace std;
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e-10;

	// 실용적인 측면
	// Octal : 0 1 2 3 4 5 6 7 10 11 12 13
	// Hexa : 0 12 3 4 5 6 7 8 9 A B C D E F 10

	int x = 012;
	cout << x << endl;

	int y = 0xF;
	cout << y << endl;

	// 바이너리 리터럴
	int z = 0b10101'0101'0111'0101'0101;
	cout << z << endl;

 */

/* 심볼릭 상수 */
 // const ~~ : 매직넘버보다 const로 사용하는 것이 좋음 (+ #define은 cpp에서 잘 안슴) . 
 // 파라미터를 변경하지 못하도록 파라미터가 많이 사용함.
 // constexpr : 컴파일 타임 변수 / ex) const int my_const(123)
 // 런타임 변수 : ex) const int special_number(number)
 // const는 몰아두는 것이 좋음 -> header파일 -> namespace constants ( ~~~~ )
