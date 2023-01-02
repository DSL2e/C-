#include<iostream>
#include<limits>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	int length;

	cin >> length;


	// 0���� �ڵ����� �ʱ�ȭ��. {11,12,13,14 ,...} �ʱ�ȭ�� ����. �������� 0���� �ʱ�ȭ��
	int* array = new int[length];

	for (int i = 0; i < length; i++)
		cout << array[i] << endl;

	delete[] array;

	return 0;
}

// �迭�� �⺻���� �����
// C�� ũ�� �ٸ����ʾƼ� ����

// ���� ������ �迭
 // �޸� �ּҸ� ���� 1���� �迭ó�� �����Ǿ�����.
 // ���� ��������
// row-major , column-major
/*
int array[row][column] =
{
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15}
};
*/

// ���ڿ� �迭 ó��
// c��Ÿ�� - scanf�� ���ڿ� �޴� �� 
// strcpy(dest, source) - �Ҵ�ȵ� �޸𸮿� ������ ���ɼ��־� ����
// strcat(dest, source) - dest �ڿ��ٰ� source ���ڿ� �ռ� (dest�� ����ٸ� source �����ϰ� �ڿ� source ����)
// strcmp() - �� ���ڿ� �� (������ 0 , �ٸ��� -1 ����)


// �������� �⺻���� ����
// int *x_pointer = &x 

// �������� (modern c++)
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
 // (uintptr_t)name - �������ּҸ� int������ ���
 // c��Ÿ�� ���ڿ� ��� : const char *name = "Jack Jack";

// �޸� �����Ҵ�
// os���� int�� ���� ���� �޸� �Ҵ�
/*
	int* ptr = new int{ 7 };
	cout << ptr << endl;
	cout << *ptr << endl;
*/

/*
	delete ptr; // os �޸𸮸� ������
	ptr = nullptr; // �޸� ���� ��, nullptr�� �־��־� ������� �ʴ´ٰ� �˷���
*/

// �޸𸮰� �� ����ϰ� ���� �� : �޸� ������ ����� ����
// int* ptr_ = new (std::nothrow) int{ 7 };

// memory leak
  // c/c++ �� ���� ū ���� : new�� delete�� ���� �����ϹǷ� �޸� ������ �ּ�ȭ����
/*
while (true)
{
	int* ptr = new int;
	// deug - window - show diagnostic tools �޸� �����߻��ϴ��� Ȯ��
	delete ptr;
}
return 0;
*/

// �迭 ���� �Ҵ�
/*
int length;
cin >> length;

// 0���� �ڵ����� �ʱ�ȭ��. {11,12,13,14 ,...} �ʱ�ȭ�� ����. �������� 0���� �ʱ�ȭ��
int* array = new int[length]();

delete[] array;
*/


// �����Ϳ� const
/*
 	// case1.
	const int value = 5;
	const int *ptr = &value;

	// case2.
	int value_2 = 5;
	const int* ptr_2 = &value_2; // value_2�ȿ� �ִ� ���� �ȹٲٰڴٴ� �� / ptr_2�� �ٸ� �ּҰ� �ִ� �� ����
	value_2 = 6;

	// case3. 
	int val = 5;
	int *const p = &val; // pointer�� �ּ� ���� �ٲ� �� ����.

	// 1+2+3
	const int* ptr1 = &val;
	int *const ptr2 = &val;
	const int *const ptr3 = &val;
*/

// ���� ����
 // ���� ó�� ����ϴ� ������ ������ �ּҸ� ������ ���� �ƴ� ������ �ٸ� �����̶�� ����
 // �ʱ�ȭ�� ������ �ؾ��ϰ�, �����̹Ƿ� ���ͷ��� ������ ������ ������.
 // ������ �Է� ���� ���ٲٵ��� �ϴ� ���� �߼� - dosomething (const int &n) { ... }
 // �ٸ� ����ü�� ���� ����ü���� ���� �� �� int &v1 = ot.st.v1; v1 = 1;  
 // ���۷��� vs ������ : ��ɻ� ����(but, ���۷����� ������ �ּҸ� ������ ���� �ʴٴ� ������ ����)
 /*
  	int value = 10;
	int& ref = value;
	int* ptr = &value;

	cout << &value << endl;
	cout << &ref << endl;
	cout << &ptr << endl;
	cout << ptr << endl; // �̰͸� �ٸ�

 */

// ������ const
// const int& ó�� const�� ����ϸ� ���ͷ� ����� ���� �� ����.(�޸� ���� ����)
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

//�����Ϳ� ������ ��� ���� ������
/*
	struct Person
	{
		int age;
		double weight;
	};

	int main()
	{
		//1. �Ϲ����� ���
		Person person;
		person.age = 5;

		//2. ����
		Person &ref = person;
		ref.age = 15;

		//3. ������
		Person* ptr = &person;
		//(*ptr).age = 15;
		ptr->age = 30;
		return 0;
	}
*/

// for-each �ݺ���(c++11)
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

//void ������
 // �ڷ����� ������� ����
 // ������ ���� (ex.ptr+1)�� �Ұ��� -> ������ ĳ���� (ex. *static_cast<float*>(ptr))

//���� �����Ϳ� ���� ������ �迭

 /* ���� �Ҵ����� ������ ��� ����
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

	// 1������ 2���� ó�� ���
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
 // ����: size, sort, parameter �� ���� ������ ���̺귯�� ��� ���� / ����: ũ�⸦ �׻� �������־����
 // include<array> -> std::array<type, size> ������

/*

// ���۷����� ����Ͽ� ����Ǵ� ���� ����
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
	// at�� ���� �������� üũ �� �ȵȴٸ� ����ó��
	// cout << my_arr.at(10) << endl;

	// size, ���۷���, std::sort(my_arr.(r)begin(), my_arr.(r)end());
	printLength(my_arr);
	return 0;
}
*/

//std::vector (���� �Ҵ� �迭�� ��������)
/*
	int main()
	{
		// �� ������ ���� �� �˾Ƽ� �����
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