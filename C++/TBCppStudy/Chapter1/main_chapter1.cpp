
// 주석 잘 다는 방법
// 어떤 함수에서 어떤 걸 한다. 내가 뭘 하는지 적는게 좋음(1. ..... 2. ..... )
#include<iostream>
#include "add.h"
using namespace std;

namespace MySpace2
{
	int doSomething(int x, int y)
	{
		return x + y;
	}
}

int doSomething(int x, int y)
{
	return x * y;
}

int main(void)
{
	int x = 0, y = 0;
	cin >> x >> y;

	cout << doSomething(x, y) << endl;
	cout << MySpace2::doSomething(x, y) << endl;
}

/* 변수 */
 //객체(Object) : 어떠한 정보들을 메모리에 저장한 것을 객체라고 정의함.
 //변수(Variables) : 숫자주소 대신에 이름을 붙혀주는 것.
 //L(eft)-values 과 R(ight)-values : L-values > 메모리 주소를 가지고 있는 것. R-values > 임시 값(대입하는 값) 
 //초기화와 대입 : int x = 123; (initialization) / x = 5; (assignment)  release > 자동으로 초기화 해줌 > 어디서 오류인지 찾을 수가 없음
 //초기화를 안했을 때의 문제점 : Runtime Error > 메모리에 접근할 때 생기는 오류. Garbage값이 생김 


/* 입출력 스트림 */
 // 헤더파일 : <iostream> ,<cstdio> : prinf
 // std안에 정의 되어 있음
 // cin : 
 // cout : std::cout << "I love this lecture" << std::endl;
  /* 코드
    int x = 1024;
	double pi = 3.141592;
	int val;
	
	std::cin >> val;
	std::cout << "your input is " << val << "\n";

	std::cout << "I love this lecture\n";
	std::cout << "x is " << x <<". pi is " << pi << std::endl;
	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "\a";
  */


/* 함수 */
 /* 코드
	int addTwoNumbers(int x, int y)
	{
		int sum = x + y;
		return sum;
	}

	int multiplyTwoNumbers(int x, int y)
	{
		int sum = x * y;
		return sum;
	}
	
    int x = 0 ,y =0;
	cin >> x >> y;
	cout << addTwoNumbers(x, y) << endl;
	cout << multiplyTwoNumbers(x, y) << endl;
 */


/* 키워드와 식별자(identifier) 이름짓기*/
 // 안되는 것 : 예약어, 숫자로 시작X, 특수문자로 시작X
 // 너무 길지 않으면서 뜻을 알 수 있는 것 (EX. n_apples)
 // indentifier > 대문자 : 매크로로 많이 사용 
 // 단어 여러개 : _로 단어 구별 / 첫문자 대문자로 구별
 // 함수 이름 : 주로 동사+명사 (ex. getNumber())
 // 함수 명이 길어 질때 : 짧게 쓰고 주석으로 설명
 // class member : m_~~, _~~ 처럼 붙힘
 

/* 삼항연산자 */
 /* 코드
  int x = 2;
  int y = (x>0) ? 1 : 2;
 */


 /* 기본 서식 맞추기 */
 // 기본적으로 보기 쉬워야함
 // 길어서 줄바꿈 시, operater를 남겨두는 습관
 // 함수도 중괄호, 인덴팅(tab : space 4개)
 // 하드 코딩 : 탭키를 통해 줄을 맞춰줌

/* 헤더 파일 만들기 */
 // 재사용성 높이기 위해서 사용
 // Header Files에 ~~.h 생성
 // main함수에 #include "~~.h"
 // 주로 하는 법 : header에 선언만 하고 함수의 바디는 cpp파일 새로 만들어서 분리하는 것이 좋음(ex. add면 2개로 나누어 작성)

/* 링킹 error : 헤더 가드 */
 // #pragma once > 중복될 경우 한번만 하면 된다고 알려줌

 /* namespace */
  /*코드
	namespace MySpace2
	{
		int doSomething(int x, int y)
		{
			return x + y;
		}
	}

	int doSomething(int x, int y)
	{
		return x * y;
	}

	int main(void)
	{
		int x = 0, y = 0;
		cin >> x >> y;

		cout << doSomething(x, y) << endl;
		cout << MySpace2::doSomething(x, y) << endl;
	}
  */