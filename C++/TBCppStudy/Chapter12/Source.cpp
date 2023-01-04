#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

class Base
{
public:
	Base() {}

	// friend는 멤버가 아니라 directly overriding은 불가능
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main(void)
{
	Base b;
	cout << b << '\n';

	Derived d;
	cout << d << '\n';

	Base &bref = d;
	cout << bref << '\n';

	return 0;
}

//tip
 // virtual func라면 하위 class 해당 모든 func virtual를 적어주는 것이 좋음.
 // parameter가 다르면 override가 안됨.
 // vector는 referance가 사용 x
 // 일반적으로 정적,동적 캐스팅을 사용하지 않는 것이 좋음.

// 12.1 다형성의 기본 개념
 // mother class pointer val에 adresss of chilid class val를 담으면 어떻게 작동?? -> mother인것 처럼 기능
 // mother class pointer val에 clild class를 담아 자동 캐스팅해도 mother로 인식하고 작동
 // mother class member func에 virtual를 붙히면 clild class val의 주소를 담고 실행하면 child인 것처럼 실행
/*
class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const
	{
		cout << m_name << " ??? " << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

int main(void)
{
	Cat cats[] = { Cat("c1"),Cat("c2"),Cat("c3") ,Cat("c4") ,Cat("c5") };
	Dog dogs[] = { Dog("d1"),Dog("d2")};


	Animal* my_animals[] = { &cats[0],&cats[1], &cats[2], &cats[3], &cats[4],
							&dogs[0],&dogs[1] };

	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();

	return 0;
}
*/

// 12.2 가상 함수(Virtual Functions)와 다형성(Polymorphism)
 // virtual func: 부모 클래스에서 오버라이딩하는 것 
 // 호출 방법? virtual table에서 찾아가는 방식 -> 느리다 -> 호출이 빈번한 함수라면 사용x
 // return type이 같아야함.
 // 가장 상위 class가 virtual이면 나머지도 virtual처럼 작동
/*
class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	virtual void print() { cout << "D" << endl; }
};

int main(void)
{
	A a;
	B b;
	C c;
	D d;

	A& ref = b;
	ref.print();

	return 0;
}
*/

// 12.3 override, final, 공변(coveriant) 반환형
 // override인 func는 적어줘서 실수를 최소화하는 것이 좋음
 // final: override해서 사용할 수 없도록 막는 방법
/*
class A
{
public:
	virtual void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	}
};

class B : public A
{
public:
	virtual void print() override { cout << "B" << endl; }
	virtual B* getThis()
	{
		cout << "B::getThis()" << endl;
		return this;
	}
};

int main(void)
{
	A a;
	B b;

	A& ref = b;

	b.getThis()->print();
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;
	return 0;
}
*/

// 12.4 가상 소멸자
 // 가상 소멸자: virtual ~class명()를 사용하면 이름이 달라도 override를 함
/*
class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main(void)
{
	// Derived derived(5);

	Derived* derived = new Derived(5);
	Base* base = derived;

	delete base;
	return 0;
}
*/

// 12.5 동적 Binding과 정적 Binding
 // static binding (early binding): 직접적으로 연결되어 정리된 방식으로 모든것이 결정됨
 // Dynamic binding (late binding): 간접적으로 찾아가는 방식으로 runtime에 결정됨(함수 포인터를 거쳐가는 구조)
 // 차이: 속도?? static binding이 빠름. 동적 바인딩은 유연함.

// 12.6 Virtual Tables
 // virtual를 선언하면 Dynamic binding 방식으로 virtual table에서 찾아가는 방식

// 12.7 순수 가상 함수, 추상 기본 클래스, 인터페이스 클래스
 // 어떤 것을 강제하게 하는 방식 (설계를 유용하도록 도와줌)
 // pure virtual function: parent class는 무엇인지 모르고, child class에선 반드시 구현해야하는 함수
  // praent class는 생성 불가능, pure virtual를 override하지 않는다면 생성 불가능
    // ex. virtual void speak() const = 0; // pure virtual function
 // interface class: pure virtual func만 가지고 있는 무엇을 강제하는 함수만 가진 class
/*
class Animal
{
protected:
	string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const = 0; // pure virtual function
};

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name)
	{}

	virtual void speak() const
	{
		cout << m_name << " Moooo " << endl;
	}
};

int main(void)
{
	Cow cow("hellow");

	cow.speak();
	return 0;
}
*/

// 12.8 가상 기본 클래스와 다이아몬드 문제
  // 여러 번 호출 되는 것을 virtual public class명으로 지정하여 하나의 주소 공간을 사용하도록하여 해결
	/*
	class PoweredDevice
	{
	public:
		int m_i;

		PoweredDevice(int power)
		{
			cout << "PoweredDevice: " << power << "\n";
		}
	};

	class Scanner : virtual public PoweredDevice
	{
	public:
		Scanner(int scanner, int power)
			:PoweredDevice(power)
		{
			cout << "Scanner: " << scanner << "\n";
		}
	};

	class Printer : virtual public PoweredDevice
	{
	public:
		Printer(int printer, int power)
			: PoweredDevice(power)
		{
			cout << "Printer: " << printer << "\n";
		}
	};

	class Copier : public Scanner, public Printer
	{
	public:
		Copier(int scanner, int printer, int power)
			: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
		{}

	};

	int main()
	{
		Copier cop(1, 2, 3); //생성자 호출

		cout << &cop.Scanner::PoweredDevice::m_i << endl;
		cout << &cop.Printer::PoweredDevice::m_i << endl;

		return 0;
	}
	*/

// 12.9 객체 잘림과 reference_wrapper
 // b = d, 복사 대입시 child class func 실행에 필요한 것들이 짤려나가면서 다형성이 안됨.
 // pointer or reference 사용해야 다형성됨.
/* 
#include<functional>
class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main(void)
{
	Base b;
	Derived d;
	//	== std::vector<Base&> my_vec;
	std::vector<std::reference_wrapper<Base>> my_vec;
	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto& ele : my_vec)
		ele.get().print();

	return 0;
}
*/

// 12.10 동적 형변환
/*
class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main(void)
{
	Derived1 d1;
	Base* base = &d1;

	//(x) base->m_j
	// base -> d1는 메모리에 있으므로 됨. base -> d2는 불가능
	// static cast는 되면 무조건 해줌
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl;

	return 0;
}
*/

//12.11 유도 클래스에서 출력 연산자 사용하기.
 // override이 불가능?? 어떻게 사용?
 // 멤버로 만들 수가 없는 함수를 override로 처럼 사용하기 위해, 기능을 위임받은 일반 함수를 통해 만듬
/*
class Base
{
public:
	Base() {}

	// friend는 멤버가 아니라 directly overriding은 불가능
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main(void)
{
	Base b;
	cout << b << '\n';

	Derived d;
	cout << d << '\n';

	Base &bref = d;
	cout << bref << '\n';

	return 0;
}
*/
