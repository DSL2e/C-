#include<iostream>
#include<cstdlib>
#include<random>
using namespace std;

int main(void)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	cout << fraction << endl;
	for (int i=0; i<20;i++)
		cout << (std::rand() * fraction) << endl;
}

// 제어 흐름
 // 1. 중단 2. 반복 3. 점프 4. 조건 분기 5. 예외 처리

// 중단 - 1. return 0; 2. <cstdlib> 라이브러리 - exit(0)

// 조건문 if
// 주의사항1 : if에서 중괄호가 없어도 있는 것과 같이 실핼되므로 지역변수처럼 사라짐
/* 
	int x;
	cin >> x;


	if (1)
		int x = 5;
	else
	{
		int x = 6;
	}

	cout << x << endl;
	return 0;
*/
// 주의사항2 : if(x = 0)이라고 되면 x = 0을 대입하고 false로 되어 if문 실행 X

// switch ... case문
 // 주의사항1 - 변수 선언은 되지만 초기화는 case문 다음에서만 할 수 있음
 // case안에서 선언을 해면 case 밖에서 선언한 것으로 모든 case 사용 가능
 // 1. 그냥 switch 바로 직전에 변수 선언하는게 좋음 2. case를 중괄호로 감싸면 해당 case에서만 사용하고 초기화 가능


// 반복문 while
 // 조건이 감소하는경우, unsigned int 사용하는 것은 추천하지 않음, (overflow)
 // but, unsigned 계산이 signed 보다 빠르다는 장점이 있음. 용도에 따라 쓰자

// 반복문 do - while
 // while은 조건에 따라 한번 실행 안될 수 있지만, do-while은 무조건 실행
 // do { ... } while(조건); 꼴

// 반복문 for
 // 두가지 변수도 사용 가능 : for (int i=0, j=0; i < 10; ++i, --j)
 /*
 	for (int i = 0, j = 0, z = 10; i < 10; ++i, --j, z++)
	{
		cout << "i: " << i << endl;
		cout << "j: " << j << endl;
		cout << "z: " << z << endl;
		cout << "\n";
	}
 */

// break, continue

// 난수 만들기
 // 원리
  /*
  unsigned int PRNG()
  {
		static unsigned int seed = 5523;

		seed = 82537529 * seed + 2396403;

		return seed % 32768;
  }

  int main(void)
  {
		for (int i = 1; i <= 100; ++i)
		{
			cout << PRNG() << "\t";

			if (i % 5 == 0) cout << endl;
		}

		return 0;
  }
  */
 // <cstdlib>라이브러리 - std::radn(), std::srand(seed넘버)
 // 주로 <ctime>라이브러리 사용- std::srand(static_cast<unsigned int>(std::time(0))); 로 사용
 // 디버깅 할때는 고정된 seed로 사용하는 것이 좋음.
 /* m,n 사이에 숫자 출력 - 원리( rnad()% 4 + 5 -> 한 쪽으로 몰리는 경우가 있음 )
	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (RAND_MAX + 1.0);
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}

	int main(void)
	{
		for (int i = 1; i <= 100; ++i)
		{
			cout << getRandomNumber(3,8) << "\t";

			if (i % 5 == 0) cout << endl;
		}

		return 0;
	}
 */

 // <random> 라이브러리 - 위 과정을 라이브러리로 사용
 /*
	int main(void)
	{
		std::random_device rd;
		std::mt19937 mersenne(rd()); // 숫자를 꼬아줌.
		std::uniform_int_distribution<> dice(1, 6); // 1 ~ 6이 나올 확률이 같음
	
		for (int i = 1; i <= 20; i++)
			cout << dice(mersenne) << endl;
		return 0;
	}
 */

// cin 잘 사용하기
 // 버퍼비우기 - std::ignore(32767, '\n')	
 /* 잘못된 입력으로 오류가 발생하였을 때
 * 
 if(std::cin.fail()) // 실패했는지 묻는 함수
 {
  std::cin.clear();
  std::ignore(32767, '\n');
 }

 */