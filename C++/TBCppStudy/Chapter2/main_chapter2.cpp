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

/* �⺻ �ڷ��� �Ұ� */
  // auto aValue = 3.141592; > �ڵ����� ������
  // sizeof - �޸� ������ �����ϴ� ���� �˷���
  // ���� �ʱ�ȭ : 1. copy initialization - a=123 / 2. direct initialization - a(123) 3. uniform initializtion - a{123} > ���� ������.
  // �ֱٿ� ����� ������ �ٷ� ������ ����ϴ� ���� ��ȣ (1. ������� �ϱ� ���� 2. ������ ����� �����丵�ϱ� ����)

/* ������ */
 // long long : 8byte , sizeof(short)
 // ���� : �� ��Ʈ�� ��ȣ�� ǥ�� >> �ٽ��� ũ���� ������ �ִ�.
 // overflow : ��ġ�� ���� ���� ���� ���ư� -> error�� ������
 // �����ϴ� �Ǽ� : ���������� ������ ���� ex. float i = 22 / 5 -> 4��µ� (float)��������.
 /* �ڵ�
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

/* ���� �ʺ� ���� */
  // int16_t : 2byte��
  // int8_t : 1byte�� ex. myint = 65; -> a
  // int_fast8_t :  8bit ������ �߿� ���� ������ 
  // int8_least64_t : ��� 8byte

/* ��ġ�� (Void, ���̵�) */
  /* �ڵ�
   int i = 10;
   void *my_void;
   my_void = (void *)&i;
  */

/* �����Ҽ��� �� */
  // float , double, Long double
  // ���� : ��ȣ / ���� / ����
  // �ʱ�ȭ ; float f = 3.14e2;
  // �Ҽ������� : #include <iomanip>
               //  cout << std::steprecision(12) << 1.0 / 3.0 << endl;
  // ���ǻ���
  /*
  // 1. ���е��� ����
	using namespace std;
	float f(123456789.0f);
	cout << std::setprecision(12);
	cout << f << endl;

  // 2. ���� ����� ���� ��µ�
	using namespace std;
	float d(0.1);
	cout << std::setprecision(17);
	cout << d << endl;
  
  // 3. 2�� ���� ����
	using namespace std;
	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	cout << std::setprecision(17);
	cout << d1 << endl;
	cout << d2 << endl;

  // 4. 0���� ���� ��
   double zero = 0.0;
   double = posinf = 5.0 / zero;
   >> ����� #include<cmath> std::isnan -> boolŸ������ �˷���
  */ 

/* �Ҹ��� �ڷ����� ���ǹ� */
 // bool : true(1) or false(0)
 // cout << std::boolalpha; - true / false�� ���
 // if ~ else : if�� 0�� �ƴ϶�� true�� �Ǵ�
 //or(||), and(&&). ==. != , ...
 /*�ڵ�
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
 // (���� ���� �� üũ) static casting : cout << static_cast<char>(65) << endl;
 // wchar_t c , char16(32)_t : �����ڵ�

/* ���ͷ� ��� */
 /* �ڵ�
 	using namespace std;
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e-10;

	// �ǿ����� ����
	// Octal : 0 1 2 3 4 5 6 7 10 11 12 13
	// Hexa : 0 12 3 4 5 6 7 8 9 A B C D E F 10

	int x = 012;
	cout << x << endl;

	int y = 0xF;
	cout << y << endl;

	// ���̳ʸ� ���ͷ�
	int z = 0b10101'0101'0111'0101'0101;
	cout << z << endl;

 */

/* �ɺ��� ��� */
 // const ~~ : �����ѹ����� const�� ����ϴ� ���� ���� (+ #define�� cpp���� �� �Ƚ�) . 
 // �Ķ���͸� �������� ���ϵ��� �Ķ���Ͱ� ���� �����.
 // constexpr : ������ Ÿ�� ���� / ex) const int my_const(123)
 // ��Ÿ�� ���� : ex) const int special_number(number)
 // const�� ���Ƶδ� ���� ���� -> header���� -> namespace constants ( ~~~~ )
