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

//15-1 '이동'의 의미와 스마트 포인터 소개
 // RAII(Resource acquisition is initialization): 동적할당 받은 곳에서 해제해야한다는 개념
 // dull pointer: 수동으로 해제해줘야하는 포인터
 // auto pointer: 자동으로 해제해줌(현재는 사용x)
  // 단점: 현재 사용하는 auto pointer를 parameter로 넘기면 move되고 함수가 끝나면 해당 address가 destroy됨
 // copy constructor시 member가 다 복사됨 -> 하나가 해제되면 error 발생 -> 어떻게 해결?? move semantics
 // move semantics: 메모리 주소에 대한 소유권을 넘겨준다.
 // syntax vs semantic: semantic -> ex. string + string

// 15-2 오른쪽-값 참조
 // move semantics를 사용해야할지 말지를 판단
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

// 15.3 이동 생성자와 이동 대입
 // R-value refence를 사용하면 deep copy가 이러나지 않음(포인터만 넘겨줌)

// 15.4 std::move
 //  L-value를 사용하는 것을 R-value로 리턴해주어 R-value Reference를 사용하는 move constructor이 실행됨.
  // ex. res2 = std::move(res1)

// 15.5 std::unique_ptr
 // auto ptr = std::make_unique<type> 주로 사용하는 방식
 // unique_ptr은 deep copy, 즉 copy construcor(assignment)가 안됨
   // parameter시, 1.(편함) L-value reference로 받는다. 2. std::move를 주소의 소유권을 넘겨준다 -> 다시 리턴
 // 주의사항: delete가 두 번 이상 되는 상황이 나오지 않도록 주의

// 15.6 std::shared_ptr
 // auto ptr = std::make_shared<typr> 
 // ptr의 주소가 공유가 되고 공유받은 ptr이 스코프를 벗어나도 해당 주소는 detory 되지 않음.

// 15.7 순환 의존성 문제와 std::weak_ptr
 // 소유권이 순환이 되어 smart pointer의 강점인 자동 해제가 안되는 경우가 발생.
 //  std::shared_ptr<자료형> ptr - 순환 문제 해결
  // 단점: 해당 자료형의 값을 사용하려면 lock동해 shared_ptr를 받고 사용해야함
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
