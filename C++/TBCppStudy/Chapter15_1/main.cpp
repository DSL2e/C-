#include<iostream>
#include"Resource.h"
#include"AutoPtr.h"

using namespace std;

void doSomething()
{
	try
	{
		AutoPtr<Resource> res(new Resource);


		//delete res;

	}

	catch (...)
	{

	}
}

int main(void)
{
	doSomething();

	AutoPtr<Resource> res1(new Resource);
	AutoPtr<Resource> res2;

	cout << std::boolalpha;

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	res2 = res1; // member copy

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	return 0;
}