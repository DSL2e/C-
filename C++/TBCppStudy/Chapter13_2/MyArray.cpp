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
 // � type���� ��. �׷��� �����Ϸ����� �˷������
template class MyArray<char>;
template class MyArray<double>;