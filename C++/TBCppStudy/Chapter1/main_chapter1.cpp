
// �ּ� �� �ٴ� ���
// � �Լ����� � �� �Ѵ�. ���� �� �ϴ��� ���°� ����(1. ..... 2. ..... )
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

/* ���� */
 //��ü(Object) : ��� �������� �޸𸮿� ������ ���� ��ü��� ������.
 //����(Variables) : �����ּ� ��ſ� �̸��� �����ִ� ��.
 //L(eft)-values �� R(ight)-values : L-values > �޸� �ּҸ� ������ �ִ� ��. R-values > �ӽ� ��(�����ϴ� ��) 
 //�ʱ�ȭ�� ���� : int x = 123; (initialization) / x = 5; (assignment)  release > �ڵ����� �ʱ�ȭ ���� > ��� �������� ã�� ���� ����
 //�ʱ�ȭ�� ������ ���� ������ : Runtime Error > �޸𸮿� ������ �� ����� ����. Garbage���� ���� 


/* ����� ��Ʈ�� */
 // ������� : <iostream> ,<cstdio> : prinf
 // std�ȿ� ���� �Ǿ� ����
 // cin : 
 // cout : std::cout << "I love this lecture" << std::endl;
  /* �ڵ�
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


/* �Լ� */
 /* �ڵ�
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


/* Ű����� �ĺ���(identifier) �̸�����*/
 // �ȵǴ� �� : �����, ���ڷ� ����X, Ư�����ڷ� ����X
 // �ʹ� ���� �����鼭 ���� �� �� �ִ� �� (EX. n_apples)
 // indentifier > �빮�� : ��ũ�η� ���� ��� 
 // �ܾ� ������ : _�� �ܾ� ���� / ù���� �빮�ڷ� ����
 // �Լ� �̸� : �ַ� ����+��� (ex. getNumber())
 // �Լ� ���� ��� ���� : ª�� ���� �ּ����� ����
 // class member : m_~~, _~~ ó�� ����
 

/* ���׿����� */
 /* �ڵ�
  int x = 2;
  int y = (x>0) ? 1 : 2;
 */


 /* �⺻ ���� ���߱� */
 // �⺻������ ���� ��������
 // �� �ٹٲ� ��, operater�� ���ܵδ� ����
 // �Լ��� �߰�ȣ, �ε���(tab : space 4��)
 // �ϵ� �ڵ� : ��Ű�� ���� ���� ������

/* ��� ���� ����� */
 // ���뼺 ���̱� ���ؼ� ���
 // Header Files�� ~~.h ����
 // main�Լ��� #include "~~.h"
 // �ַ� �ϴ� �� : header�� ���� �ϰ� �Լ��� �ٵ�� cpp���� ���� ���� �и��ϴ� ���� ����(ex. add�� 2���� ������ �ۼ�)

/* ��ŷ error : ��� ���� */
 // #pragma once > �ߺ��� ��� �ѹ��� �ϸ� �ȴٰ� �˷���

 /* namespace */
  /*�ڵ�
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