#include<iostream>
#include<memory>
#include<string>
#include"Resource.h"

auto doSomething()
{
	//return std::unique_ptr<Resource>(new Resource(5));
	return std::make_unique<Resource>(5);
}

// unique_ptr is not copy assignment
//auto doSomething2(std::unique_ptr<Resource> res)
void doSomething2(std::unique_ptr<Resource>& res)
{
	res->setAll(1010);
	//return res;
}

int main()
{
	{
		// Resource* res = new Resource(10000000);

		// std::unique_ptr<Resource> res(new Resource(10000000));
	}

	//{
	//	std::unique_ptr<int> upi(new int);
	//	
	//	// initialization
	//	// 1. std::unique_ptr<Resource> res1(new Resource(5));
	//	// 2. auto res1 = std::make_unique<Resource>(5);
	//	auto res1 = doSomething();

	//	res1->setAll(5);
	//	res1->print();

	//	std::unique_ptr<Resource> res2;
	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	// copy가 안됨
	//	res2 = std::move(res1);

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) res2->print();
	//}

	//{
	//	auto res1 = std::make_unique<Resource>(5);
	//	res1->setAll(1);
	//	res1->print();
	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;

	//	doSomething2(res1);
	//	// res1.get() -> 내부적으로 가지고 있는 Resource 주소를 가져옴

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	res1->print();
	//}

}