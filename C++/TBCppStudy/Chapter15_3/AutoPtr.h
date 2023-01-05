#include <iostream>
using namespace std;

template<typename T>
class AutoPtr
{
public:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
		cout << "AutoPtr default constructor" << endl;
	}
	~AutoPtr()
	{
		cout << "AutoPtr destructor" << endl;

		if (m_ptr != nullptr) delete m_ptr;
	}
	AutoPtr(AutoPtr&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // 사라질 것이지만, 해주는 것이 안전.
		cout << "AutoPtr move constructor" << endl; 
	}
	AutoPtr& operator = (AutoPtr&& a) 
	{
		cout << "AutoPtr move assignment" << endl;

		if (&a == this)
			return *this;

		if (m_ptr != nullptr) delete m_ptr;

		// shallow copy
		m_ptr = a.m_ptr;  
		a.m_ptr = nullptr;

		return *this;
	}
	T& operator *() const { return *m_ptr; }
	T* operator ->() const { return m_ptr; }
	bool inNull() const { return m_ptr == nullptr; }
};