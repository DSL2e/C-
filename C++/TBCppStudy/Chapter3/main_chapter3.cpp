#include <iostream>
#include <cmath>
#include <bitset>
#include <limits>
int main(void)
{

	return 0;
}

/* ������ */
 // sizeof - sizeof(float), sizeof ����;
 
/*comma ������ : for������ ���� ���*/
 // ���� ���� - z = a, b �϶� =�� �켱 ���� ���Ƽ� z = a�� ��
 /*�ڵ� (x = 4, y = 15 , z = 14)
	using namespace std;

	int x = 3;
	int y = 10;
	int z = (x++, y = x + y++);

	cout << x << " " << y << " " << z << endl;
 */

/* ���� ������ */
  // ex. const int price = ((onSale == true) ? 10 : 100;) -> ��ȣ�� ġ�� ���� : �켱 ����

/* ���� ������ */
  // �ε��Ҽ� �������� ��� ���� ���� �̼��ϰ� �ٸ� �� ����
  /* �ڵ�
   	using namespace std;

	double d1(100 - 99.99); // 0.001 
	double d2(10 - 9.99); // 0.001;

	if (d1 == d2)
		cout << "equal" << endl;
	else
		cout << "Not equal" << endl;

	const double epsilon = 1e-10;
	cout << "����: " << std::abs(d1 - d2) << endl;

	if(std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;
  */

/*�� ������*/
  // XOR - false true ó�� ���� �޶�� true
  // �켱 ���� : && > ||

/* ������ */
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

   ii) ���� ū �ڸ� ������ ã��

  -5 (binary)
   0000 0101
   ���� complement
   1111 1010
   ������ +1 (���ϴ� ���� : ���� ���� 0�� ���� ���� 0�� ���� �ϱ����ؼ�)
   1111 1011 = -5

 signed vs unsigned : ���̰� ŭ
  1001 1110 -> -��ȣ  -> 0110 0010 -> 98 -> -98 
  1001 1110 -> 2^7 + 2^4 + 2^3 + 2^2 + 2^1 = 128+16+8+4+2
 */

/* ��Ʈ���� ������ */
  // 1. �޸𸮸� �Ƴ������ؼ� 2. ��� �ӵ��� ����
  // shift������ : << : *2 , >> : /2
  // ~(not : ����), & (�Ѵ� 1�϶� true), | (�� �� �ϳ��� 1�� �� true), ^ (�� ��Ʈ�� ���� �ٸ� ��� true)

/* ��Ʈ �÷���*/
  // �����̶�� �����ϸ� 8�� boolŸ���� ����� ���� �ƴ϶� unsigned char�� ��ü ����
  /* �ڵ�
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

/* ��Ʈ ����ũ */
  // ex. �÷� ���̺�
  /* �ڵ�
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