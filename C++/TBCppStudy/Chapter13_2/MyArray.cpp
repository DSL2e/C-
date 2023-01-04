#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < 10; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}
// 
// explicit instantiation
 // 어떤 type인지 모름. 그래서 컴파일러한테 알려줘야함
template class MyArray<char>;
template class MyArray<double>;