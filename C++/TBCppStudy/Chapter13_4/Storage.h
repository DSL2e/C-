#pragma once

#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;
	
public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		std::cout << m_value << "\n";
	}
};

// header에 몰아 넣는게 주로 많음.
template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}