#include<iostream>
#include<memory>
#include<string>
#include"Resource.h"

int main(void)
{
  // 사용 안함. (안전하지 못한 방식)
	//Resource* res = new Resource(3);
	//res->setAll(1);
	//std::shared_ptr<Resource> ptr1(res);

	{
		auto ptr1 = std::make_shared<Resource>(3);
		ptr1->setAll(1);
		ptr1->print();

		{
			auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;
		}

		ptr1->print();
		std::cout << "Going out of outer block" << std::endl;
	}

	return 0;
}