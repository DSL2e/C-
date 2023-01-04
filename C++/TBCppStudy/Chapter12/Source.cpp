#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

class Base
{
public:
	Base() {}

	// friend�� ����� �ƴ϶� directly overriding�� �Ұ���
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
 // virtual func��� ���� class �ش� ��� func virtual�� �����ִ� ���� ����.
 // parameter�� �ٸ��� override�� �ȵ�.
 // vector�� referance�� ��� x
 // �Ϲ������� ����,���� ĳ������ ������� �ʴ� ���� ����.

// 12.1 �������� �⺻ ����
 // mother class pointer val�� adresss of chilid class val�� ������ ��� �۵�?? -> mother�ΰ� ó�� ���
 // mother class pointer val�� clild class�� ��� �ڵ� ĳ�����ص� mother�� �ν��ϰ� �۵�
 // mother class member func�� virtual�� ������ clild class val�� �ּҸ� ��� �����ϸ� child�� ��ó�� ����
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

// 12.2 ���� �Լ�(Virtual Functions)�� ������(Polymorphism)
 // virtual func: �θ� Ŭ�������� �������̵��ϴ� �� 
 // ȣ�� ���? virtual table���� ã�ư��� ��� -> ������ -> ȣ���� ����� �Լ���� ���x
 // return type�� ���ƾ���.
 // ���� ���� class�� virtual�̸� �������� virtualó�� �۵�
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

// 12.3 override, final, ����(coveriant) ��ȯ��
 // override�� func�� �����༭ �Ǽ��� �ּ�ȭ�ϴ� ���� ����
 // final: override�ؼ� ����� �� ������ ���� ���
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

// 12.4 ���� �Ҹ���
 // ���� �Ҹ���: virtual ~class��()�� ����ϸ� �̸��� �޶� override�� ��
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

// 12.5 ���� Binding�� ���� Binding
 // static binding (early binding): ���������� ����Ǿ� ������ ������� ������ ������
 // Dynamic binding (late binding): ���������� ã�ư��� ������� runtime�� ������(�Լ� �����͸� ���İ��� ����)
 // ����: �ӵ�?? static binding�� ����. ���� ���ε��� ������.

// 12.6 Virtual Tables
 // virtual�� �����ϸ� Dynamic binding ������� virtual table���� ã�ư��� ���

// 12.7 ���� ���� �Լ�, �߻� �⺻ Ŭ����, �������̽� Ŭ����
 // � ���� �����ϰ� �ϴ� ��� (���踦 �����ϵ��� ������)
 // pure virtual function: parent class�� �������� �𸣰�, child class���� �ݵ�� �����ؾ��ϴ� �Լ�
  // praent class�� ���� �Ұ���, pure virtual�� override���� �ʴ´ٸ� ���� �Ұ���
    // ex. virtual void speak() const = 0; // pure virtual function
 // interface class: pure virtual func�� ������ �ִ� ������ �����ϴ� �Լ��� ���� class
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

// 12.8 ���� �⺻ Ŭ������ ���̾Ƹ�� ����
  // ���� �� ȣ�� �Ǵ� ���� virtual public class������ �����Ͽ� �ϳ��� �ּ� ������ ����ϵ����Ͽ� �ذ�
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
		Copier cop(1, 2, 3); //������ ȣ��

		cout << &cop.Scanner::PoweredDevice::m_i << endl;
		cout << &cop.Printer::PoweredDevice::m_i << endl;

		return 0;
	}
	*/

// 12.9 ��ü �߸��� reference_wrapper
 // b = d, ���� ���Խ� child class func ���࿡ �ʿ��� �͵��� ©�������鼭 �������� �ȵ�.
 // pointer or reference ����ؾ� ��������.
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

// 12.10 ���� ����ȯ
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
	// base -> d1�� �޸𸮿� �����Ƿ� ��. base -> d2�� �Ұ���
	// static cast�� �Ǹ� ������ ����
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl;

	return 0;
}
*/

//12.11 ���� Ŭ�������� ��� ������ ����ϱ�.
 // override�� �Ұ���?? ��� ���?
 // ����� ���� ���� ���� �Լ��� override�� ó�� ����ϱ� ����, ����� ���ӹ��� �Ϲ� �Լ��� ���� ����
/*
class Base
{
public:
	Base() {}

	// friend�� ����� �ƴ϶� directly overriding�� �Ұ���
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
