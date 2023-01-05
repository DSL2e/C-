#include<iostream>
#include<string>
#include<memory>

class Person
{
	std::string m_name;
	// std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p1->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << std::endl;

		return true;
	}
	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}

	const std::string& getName() const
	{
		return m_name;
	}
};

int main(void)
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");
	
	partnerUp(lucy, ricky);
	
	std::cout << lucy->getPartner()->getName() << std::endl;
	return 0;
}

//15-1 '�̵�'�� �ǹ̿� ����Ʈ ������ �Ұ�
 // RAII(Resource acquisition is initialization): �����Ҵ� ���� ������ �����ؾ��Ѵٴ� ����
 // dull pointer: �������� ����������ϴ� ������
 // auto pointer: �ڵ����� ��������(����� ���x)
  // ����: ���� ����ϴ� auto pointer�� parameter�� �ѱ�� move�ǰ� �Լ��� ������ �ش� address�� destroy��
 // copy constructor�� member�� �� ����� -> �ϳ��� �����Ǹ� error �߻� -> ��� �ذ�?? move semantics
 // move semantics: �޸� �ּҿ� ���� �������� �Ѱ��ش�.
 // syntax vs semantic: semantic -> ex. string + string

// 15-2 ������-�� ����
 // move semantics�� ����ؾ����� ������ �Ǵ�
 /*
using namespace std;

int getResult()
{
	return 100 * 100;
}

void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

void doSomething(int&& ref)
{
	cout << "R-value ref" << endl;
}

int main(void)
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value references
	int& lr1 = x; // modifiable l-values
	// int& lr2 = cx; // (x)Non-modifiable l-values
	//int &lr3 = 5; // (x)R-values

	const int& lr4 = x; // modifiable l-values
	const int& lr5 = cx; // Non-modifiable l-values
	const int& lr6 = x; // R-values

	// R-value references

	// int &&rr1 = x; // modifiable l-values
	// int &&rr2 = cx; // Non-modifiable l-values
	int&& rr3 = 5; // R-values
	int&& rrr = getResult(); // R-values

	// int &&rr4 = x; // modifiable l-values
	// int &&rr5 = cx; // Non-modifiable l-values
	const int&& rr6 = 5; // R-values

	// L/R-value reference parameters
	doSomething(x);
	doSomething(5);
	doSomething(getResult());

	return 0;
}
 */

// 15.3 �̵� �����ڿ� �̵� ����
 // R-value refence�� ����ϸ� deep copy�� �̷����� ����(�����͸� �Ѱ���)

// 15.4 std::move
 //  L-value�� ����ϴ� ���� R-value�� �������־� R-value Reference�� ����ϴ� move constructor�� �����.
  // ex. res2 = std::move(res1)

// 15.5 std::unique_ptr
 // auto ptr = std::make_unique<type> �ַ� ����ϴ� ���
 // unique_ptr�� deep copy, �� copy construcor(assignment)�� �ȵ�
   // parameter��, 1.(����) L-value reference�� �޴´�. 2. std::move�� �ּ��� �������� �Ѱ��ش� -> �ٽ� ����
 // ���ǻ���: delete�� �� �� �̻� �Ǵ� ��Ȳ�� ������ �ʵ��� ����

// 15.6 std::shared_ptr
 // auto ptr = std::make_shared<typr> 
 // ptr�� �ּҰ� ������ �ǰ� �������� ptr�� �������� ����� �ش� �ּҴ� detory ���� ����.

// 15.7 ��ȯ ������ ������ std::weak_ptr
 // �������� ��ȯ�� �Ǿ� smart pointer�� ������ �ڵ� ������ �ȵǴ� ��찡 �߻�.
 //  std::shared_ptr<�ڷ���> ptr - ��ȯ ���� �ذ�
  // ����: �ش� �ڷ����� ���� ����Ϸ��� lock���� shared_ptr�� �ް� ����ؾ���
/*
class Person
{
	std::string m_name;
	// std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p1->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << std::endl;

		return true;
	}
	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}

	const std::string& getName() const
	{
		return m_name;
	}
};

int main(void)
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	partnerUp(lucy, ricky);

	std::cout << lucy->getPartner()->getName() << std::endl;
	return 0;
