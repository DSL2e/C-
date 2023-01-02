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

// ���� �帧
 // 1. �ߴ� 2. �ݺ� 3. ���� 4. ���� �б� 5. ���� ó��

// �ߴ� - 1. return 0; 2. <cstdlib> ���̺귯�� - exit(0)

// ���ǹ� if
// ���ǻ���1 : if���� �߰�ȣ�� ��� �ִ� �Ͱ� ���� ���۵ǹǷ� ��������ó�� �����
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
// ���ǻ���2 : if(x = 0)�̶�� �Ǹ� x = 0�� �����ϰ� false�� �Ǿ� if�� ���� X

// switch ... case��
 // ���ǻ���1 - ���� ������ ������ �ʱ�ȭ�� case�� ���������� �� �� ����
 // case�ȿ��� ������ �ظ� case �ۿ��� ������ ������ ��� case ��� ����
 // 1. �׳� switch �ٷ� ������ ���� �����ϴ°� ���� 2. case�� �߰�ȣ�� ���θ� �ش� case������ ����ϰ� �ʱ�ȭ ����


// �ݺ��� while
 // ������ �����ϴ°��, unsigned int ����ϴ� ���� ��õ���� ����, (overflow)
 // but, unsigned ����� signed ���� �����ٴ� ������ ����. �뵵�� ���� ����

// �ݺ��� do - while
 // while�� ���ǿ� ���� �ѹ� ���� �ȵ� �� ������, do-while�� ������ ����
 // do { ... } while(����); ��

// �ݺ��� for
 // �ΰ��� ������ ��� ���� : for (int i=0, j=0; i < 10; ++i, --j)
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

// ���� �����
 // ����
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
 // <cstdlib>���̺귯�� - std::radn(), std::srand(seed�ѹ�)
 // �ַ� <ctime>���̺귯�� ���- std::srand(static_cast<unsigned int>(std::time(0))); �� ���
 // ����� �Ҷ��� ������ seed�� ����ϴ� ���� ����.
 /* m,n ���̿� ���� ��� - ����( rnad()% 4 + 5 -> �� ������ ������ ��찡 ���� )
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

 // <random> ���̺귯�� - �� ������ ���̺귯���� ���
 /*
	int main(void)
	{
		std::random_device rd;
		std::mt19937 mersenne(rd()); // ���ڸ� ������.
		std::uniform_int_distribution<> dice(1, 6); // 1 ~ 6�� ���� Ȯ���� ����
	
		for (int i = 1; i <= 20; i++)
			cout << dice(mersenne) << endl;
		return 0;
	}
 */

// cin �� ����ϱ�
 // ���ۺ��� - std::ignore(32767, '\n')	
 /* �߸��� �Է����� ������ �߻��Ͽ��� ��
 * 
 if(std::cin.fail()) // �����ߴ��� ���� �Լ�
 {
  std::cin.clear();
  std::ignore(32767, '\n');
 }

 */