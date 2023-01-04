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
 // class는 header파일로 분리해서 사용하는 것이 좋음
 // 공통되는 코드는 제거해주는 것이 귀찮더라도 좋음

// 11.1-2.상속의 기본 Inheritance(is -a relationship)
 // 공통된 부분을 뽑아내어 일반화하는 것이 성속 -> 코드 단순화
 // child가 생성될 때, parent class의 기본생성자를 호출한다.
 // child가 사용할 수는 있는데, 관리 책임은 parent class에 있음 -> 간접적인 접근이 가능
 // private: child class도 접근할 수 없음.
 // protected: private의 기능을 유지하면서 child에서 접근 가능. 
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

// 11.3 유도된 클래스들의 생성 순서
 // 항상 default 생성자는 호출이됨
 // public으로 둬도 생성자 이니셜리스트는 불가능
 // Mother -> Child 순으로 생성됨 -> mother의 m_val를 생성자 이니셜리스트가 불가능한 것.

// 11.4 유도된 클래스들의 생성과 초기화
 // 생성: A-B-C / 소멸: C-B-A
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

// 11.5 상속과 접근 지정자
 // 더 엄격한 쪽을 따라감.
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
		// derived안에서는 private로 작동. Derived::m_public;
	}
};
int main(void)
{
	Base base;

	base.m_public = 123;

	return 0;
}
*/

// 11.6 유도된 클래스에 새로운 기능 추가하기
 // 1. private인 상태에서 public으로 getvalue같은 함수 사용 -> 상위 class를 거치므로 속도 저하
 // 2. protected로 바꾸어 사용 -> 빈번하게 사용될 경우에는 protected가 유리

// 11.7 상속받은 함수를 오버라이딩 하기
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

// 11.8 상속받은 함수를 감추기
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

	// m_i를 밖에서도 사용할 수 있게함.
	using Base::m_i;

// 밖에서 사용하지 못하도록 막음.
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

// 11.9 다중 상속
// 잘못 사용하면 위험할 수 있음.
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