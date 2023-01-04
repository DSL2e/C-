#include<iostream>

using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id;  }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{}
};

int main(void)
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();
	return 0;
}

//TIP	
 // class�� header���Ϸ� �и��ؼ� ����ϴ� ���� ����
 // ����Ǵ� �ڵ�� �������ִ� ���� �������� ����

// 11.1-2.����� �⺻ Inheritance(is -a relationship)
 // ����� �κ��� �̾Ƴ��� �Ϲ�ȭ�ϴ� ���� ���� -> �ڵ� �ܼ�ȭ
 // child�� ������ ��, parent class�� �⺻�����ڸ� ȣ���Ѵ�.
 // child�� ����� ���� �ִµ�, ���� å���� parent class�� ���� -> �������� ������ ����
 // private: child class�� ������ �� ����.
 // protected: private�� ����� �����ϸ鼭 child���� ���� ����. 
/*
	class Mother
	{
	private:
		int m_i;

	public:
		//Mother()
		//	: m_i(0)
		//{
		//}
		Mother(const int& i_in)
			: m_i(i_in)
		{
			cout << "Mother constructor" << endl;
		}

		void setValue(const int& i_in)
		{
			m_i = i_in;
		}

		int getValue()
		{
			return m_i;
		}

	};

	class Child : public Mother // derived class
	{
	private:
		double m_d;

	public:
		Child(const int& i_in, const double& d_in)
			: Mother(i_in), m_d(d_in)
		{
		}

		void setValue(const double& i_in,const double& d_in)
		{
			Mother::setValue(i_in);
			m_d = d_in;
		}

		double getValue()
		{
			return m_d;
		}
	};


	int main(void)
	{
		Mother mother(10);
		mother.setValue(1024);
		cout << mother.getValue() << endl;

		Child child(1024, 128);
		cout << child.Mother::getValue() << endl;
		cout << child.getValue() << endl;

		return 0;
	}
*/

// 11.3 ������ Ŭ�������� ���� ����
 // �׻� default �����ڴ� ȣ���̵�
 // public���� �ֵ� ������ �̴ϼȸ���Ʈ�� �Ұ���
 // Mother -> Child ������ ������ -> mother�� m_val�� ������ �̴ϼȸ���Ʈ�� �Ұ����� ��.

// 11.4 ������ Ŭ�������� ������ �ʱ�ȭ
 // ����: A-B-C / �Ҹ�: C-B-A
/*
class A
{
public:
	A(int a)
	{
		cout << "A: " << a << endl;
	}
	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "B: " << b << endl;
	}
	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a,b)
	{
		cout << "C: " << c << endl;
	}
	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main(void)
{
	C c(1024, 3.14, 'a');
	return 0;
}
*/

// 11.5 ��Ӱ� ���� ������
 // �� ������ ���� ����.
/*
class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived : private Base
{
public:
	Derived()
	{
		// (x) m_private = 123;
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		// derived�ȿ����� private�� �۵�. Derived::m_public;
	}
};
int main(void)
{
	Base base;

	base.m_public = 123;

	return 0;
}
*/

// 11.6 ������ Ŭ������ ���ο� ��� �߰��ϱ�
 // 1. private�� ���¿��� public���� getvalue���� �Լ� ��� -> ���� class�� ��ġ�Ƿ� �ӵ� ����
 // 2. protected�� �ٲپ� ��� -> ����ϰ� ���� ��쿡�� protected�� ����

// 11.7 ��ӹ��� �Լ��� �������̵� �ϱ�
/*
class Base
{
private:
	int m_i;

public:
	Base(int value = 0)
		: m_i(value)
	{
	}

	void print()
	{
		cout << "I'm base " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}

	void print()
	{
		Base::print();
		cout << "I'm derived " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& b)
	{
		cout << static_cast<Base>(b);
		out << "This is derived output" << endl;
		return out;
	}
};

int main(void)
{
	Base base(5);
	cout << base;

	Derived derived(7);
	cout << derived;
	return 0;
}
*/

// 11.8 ��ӹ��� �Լ��� ���߱�
/*
class Base
{
protected:
	int m_i;

public:
	Base(int value = 0)
		: m_i(value)
	{
	}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}

	// m_i�� �ۿ����� ����� �� �ְ���.
	using Base::m_i;

// �ۿ��� ������� ���ϵ��� ����.
private:
	//1. using Base::print;
	void print() = delete;
};

int main(void)
{
	Derived derived(7);

	derived.m_i = 1024;
	// derived.print();
}
*/

// 11.9 ���� ���
// �߸� ����ϸ� ������ �� ����.
/*
class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id;  }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{}
};

int main(void)
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();
	return 0;
}
*/