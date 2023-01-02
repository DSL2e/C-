#include<iostream>
#include<limits>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	int length;

	cin >> length;


	// 0으로 자동으로 초기화됨. {11,12,13,14 ,...} 초기화도 가능. 나머지는 0으로 초기화됨
	int* array = new int[length];

	for (int i = 0; i < length; i++)
		cout << array[i] << endl;

	delete[] array;

	return 0;
}

// 배열의 기본적인 사용방법
// C와 크게 다르지않아서 생략

// 정적 다차원 배열
 // 메모리 주소를 찍어보면 1차원 배열처럼 구성되어있음.
 // 행은 생략가능
// row-major , column-major
/*
int array[row][column] =
{
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15}
};
*/

// 문자열 배열 처라
// c스타일 - scanf로 문자열 받는 것 
// strcpy(dest, source) - 할당안된 메모리에 접근할 가능성있어 조심
// strcat(dest, source) - dest 뒤에다가 source 문자열 합성 (dest가 비었다면 source 복사하고 뒤에 source 붙힘)
// strcmp() - 두 문자열 비교 (같으면 0 , 다르면 -1 리턴)


// 포인터의 기본적인 사용법
// int *x_pointer = &x 

// 널포인터 (modern c++)
/*
	double* ptr = nullptr; // 0

	if (ptr != nullptr)
	{
		// do someting useful
	}
	else
	{
		// do noting with ptr
	}
*/
 // (uintptr_t)name - 포인터주소를 int형으로 출력
 // c스타일 문자열 상수 : const char *name = "Jack Jack";

// 메모리 동적할당
// os한테 int형 공간 만듬 메모리 할당
/*
	int* ptr = new int{ 7 };
	cout << ptr << endl;
	cout << *ptr << endl;
*/

/*
	delete ptr; // os 메모리를 돌려줌
	ptr = nullptr; // 메모리 해제 후, nullptr를 넣어주어 사용하지 않는다고 알려줌
*/

// 메모리가 다 사용하고 있을 때 : 메모리 공간이 생기면 실행
// int* ptr_ = new (std::nothrow) int{ 7 };

// memory leak
  // c/c++ 의 가장 큰 장점 : new와 delete를 직접 제어하므로 메모리 누수를 최소화가능
/*
while (true)
{
	int* ptr = new int;
	// deug - window - show diagnostic tools 메모리 누수발생하는지 확인
	delete ptr;
}
return 0;
*/

// 배열 동적 할당
/*
int length;
cin >> length;

// 0으로 자동으로 초기화됨. {11,12,13,14 ,...} 초기화도 가능. 나머지는 0으로 초기화됨
int* array = new int[length]();

delete[] array;
*/


// 포인터와 const
/*
 	// case1.
	const int value = 5;
	const int *ptr = &value;

	// case2.
	int value_2 = 5;
	const int* ptr_2 = &value_2; // value_2안에 있는 값을 안바꾸겠다는 뜻 / ptr_2에 다른 주소값 넣는 건 가능
	value_2 = 6;

	// case3. 
	int val = 5;
	int *const p = &val; // pointer의 주소 값을 바꿀 수 없음.

	// 1+2+3
	const int* ptr1 = &val;
	int *const ptr2 = &val;
	const int *const ptr3 = &val;
*/

// 참조 변수
 // 별명 처럼 사용하는 것으로 별도의 주소를 가지는 것이 아닌 변수의 다른 별명이라고 생각
 // 초기화를 무조건 해야하고, 참조이므로 리터럴은 못들어가고 변수가 들어가야함.
 // 요즘은 입력 값은 못바꾸도록 하는 것이 추세 - dosomething (const int &n) { ... }
 // 다른 구조체의 값을 구조체에서 접근 할 때 int &v1 = ot.st.v1; v1 = 1;  
 // 레퍼런스 vs 포인터 : 기능상 동일(but, 레퍼런스는 별도의 주소를 가지고 있지 않다는 장점이 있음)
 /*
  	int value = 10;
	int& ref = value;
	int* ptr = &value;

	cout << &value << endl;
	cout << &ref << endl;
	cout << &ptr << endl;
	cout << ptr << endl; // 이것만 다름

 */

// 참조와 const
// const int& 처럼 const를 사용하면 리터럴 상수로 담을 수 있음.(메모리 절약 가능)
/*
	void doSomething(const int& x)
	{
		cout << x << endl;
	}
	int main(void)
	{

		int a = 1;
		doSomething(a);
		doSomething(1);
		doSomething(a + 3);

	}
*/

//포인터와 참조의 멤버 선택 연산자
/*
	struct Person
	{
		int age;
		double weight;
	};

	int main()
	{
		//1. 일반적인 방법
		Person person;
		person.age = 5;

		//2. 참조
		Person &ref = person;
		ref.age = 15;

		//3. 포인터
		Person* ptr = &person;
		//(*ptr).age = 15;
		ptr->age = 30;
		return 0;
	}
*/

// for-each 반복문(c++11)
/*
	int main()
	{
		int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

		// change array values
		for (auto &number : fibonacci)
			number = 10;

		// output
		for (const auto &number : fibonacci)
			cout << number << " ";
		cout << endl;
	}
*/

//void 포인터
 // 자료형과 상관없이 저장
 // 포인터 연산 (ex.ptr+1)은 불가능 -> 강제로 캐스팅 (ex. *static_cast<float*>(ptr))

//이중 포인터와 동적 다차원 배열

 /* 동적 할당으로 이차원 행렬 구현
	const int col = 5;
	const int row = 3;

	const int s2da[row][col] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
	};

	int **matrix = new int *[row];

	for (int r = 0; r < row; r++)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[r][c] = s2da[r][c];
	
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	//delete
	for (int r = 0; r < row; r++)
		delete[] matrix[r];
	
	delete[] matrix;

	// 1차원을 2차원 처럼 사용
	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[c + col * r] = s2da[r][c];
	
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[c + col * r] << " ";
		cout << endl;
	}
 */

//std::array
 // 장점: size, sort, parameter 등 여러 유용한 라이브러리 사용 가능 / 단점: 크기를 항상 지정해주어야함
 // include<array> -> std::array<type, size> 변수명

/*

// 레퍼런스를 사용하여 낭비되는 것이 방지
void printLength(const array<int, 5>& my_arr)
{
	cout << my_arr.size() << endl;
}

int main()
{
	array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 0,1,2,3,4 };
	my_arr = { 0,1,2, };

	// cout << my_arr[10] << endl;
	// at는 접근 가능한지 체크 후 안된다면 예외처리
	// cout << my_arr.at(10) << endl;

	// size, 레퍼런스, std::sort(my_arr.(r)begin(), my_arr.(r)end());
	printLength(my_arr);
	return 0;
}
*/

//std::vector (동적 할당 배열의 상위버전)
/*
	int main()
	{
		// 블럭 밖으로 나갈 때 알아서 사라짐
		int *my_arr = new int[5];

		std::vector<int> arr = { 1,2,3,4,5 };

		arr.resize(10);

		for (auto& itr : arr)
			cout << itr << " ";
		cout << endl;

		cout << arr.size() << endl;
		cout << arr[1] << endl;
		cout << arr.at(1) << endl;

		return 0;
	}
*/