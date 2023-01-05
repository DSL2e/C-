#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
#include "Timer.h"

AutoPtr<Resource> generateResource() 
{
	AutoPtr<Resource> res(new Resource(10000000));

	return res;
}

int main()
{
	using namespace std;
	streambuf* orig_buf = cout.rdbuf();
	// cout.rdbuf(NULL); 화면에 출력되는 메세지들 끄기

	Timer timer;
	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
	}
	cout.rdbuf(orig_buf);
	timer.elapsed();
}