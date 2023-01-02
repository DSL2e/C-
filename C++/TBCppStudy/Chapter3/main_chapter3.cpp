#include <iostream>
#include <cmath>
#include <bitset>
#include <limits>
int main(void)
{

	return 0;
}

/* 연산자 */
 // sizeof - sizeof(float), sizeof 변수;
 
/*comma 연산자 : for문에서 많이 사용*/
 // 주의 사항 - z = a, b 일때 =가 우선 순위 높아서 z = a가 들어감
 /*코드 (x = 4, y = 15 , z = 14)
	using namespace std;

	int x = 3;
	int y = 10;
	int z = (x++, y = x + y++);

	cout << x << " " << y << " " << z << endl;
 */

/* 조건 연산자 */
  // ex. const int price = ((onSale == true) ? 10 : 100;) -> 괄호를 치는 이유 : 우선 순위

/* 관계 연산자 */
  // 부동소수 점에서는 계산 값이 서로 미세하게 다를 수 있음
  /* 코드
   	using namespace std;

	double d1(100 - 99.99); // 0.001 
	double d2(10 - 9.99); // 0.001;

	if (d1 == d2)
		cout << "equal" << endl;
	else
		cout << "Not equal" << endl;

	const double epsilon = 1e-10;
	cout << "오차: " << std::abs(d1 - d2) << endl;

	if(std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;
  */

/*논리 연산자*/
  // XOR - false true 처럼 서로 달라야 true
  // 우선 순위 : && > ||

/* 이진수 */
 /*
  148 (decimal to binary)
   i)
   148 / 2 = 74 r0
   74  / 2 = 37 r0
   37  / 2 = 18 r1
   18  / 2 = 9  r0
    9  / 2 = 4  r1
	4  / 2 = 2  r0
	2  / 2 = 1  r0
	1  / 2 = 1  r1
	1001 0100

   ii) 가장 큰 자리 수부터 찾기

  -5 (binary)
   0000 0101
   보수 complement
   1111 1010
   보수에 +1 (더하는 이유 : 음의 정수 0과 양의 정수 0를 갖게 하기위해서)
   1111 1011 = -5

 signed vs unsigned : 차이가 큼
  1001 1110 -> -부호  -> 0110 0010 -> 98 -> -98 
  1001 1110 -> 2^7 + 2^4 + 2^3 + 2^2 + 2^1 = 128+16+8+4+2
 */

/* 비트단위 연산자 */
  // 1. 메모리를 아끼기위해서 2. 계산 속도가 빠름
  // shift연산자 : << : *2 , >> : /2
  // ~(not : 보수), & (둘다 1일때 true), | (둘 중 하나가 1일 때 true), ^ (두 비트가 서로 다른 경우 true)

/* 비트 플래그*/
  // 게임이라고 생각하면 8개 bool타입을 만드는 것이 아니라 unsigned char로 대체 가능
  /* 코드
  using namespace std;

	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;

	unsigned char items_flag = 0;
	cout << bitset<8>(items_flag) << endl;

	// item 3 on
	items_flag |= opt3;
	cout << "Item obtained " << bitset<8>(items_flag) << endl;

	// item 3 lost
	cout << bitset<8>(~opt3) << endl;
	cout << bitset<8>(items_flag) << endl;
	items_flag &= ~opt3;
	cout << "Item3 lost " << bitset<8>(items_flag) << endl;

	// has item 1?
	if (items_flag & opt1)
	cout << "yes" << endl;
	else
	cout << "No" << endl;

	items_flag |= opt2;
	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		items_flag = (items_flag ^= opt2, items_flag ^= opt1);
	}
	cout << bitset<8>(items_flag) << endl;
  */

/* 비트 마스크 */
  // ex. 컬러 테이블
  /* 코드
  	using namespace std;
	
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;
	
	unsigned int pixel_color = 0xDAA520;
	
	cout << std::bitset<32>(pixel_color) << endl;
	
	unsigned char blue = pixel_color & blue_mask;
	unsigned char green = (pixel_color & green_mask) >> 8;
	unsigned char red = (pixel_color & red_mask) >> 16;

	cout << "green " << std::bitset<8>(green) << " " << int(green) << endl;
	cout << "blue " << std::bitset<8>(blue) << " " << int(blue) <<endl;
	cout << "red " << std::bitset<8>(red) << " " << int(red) << endl;

  */