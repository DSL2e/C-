#pragma once

#include <iostream>
using namespace std;

class Resource
{
public:
	int* m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource()
	{
		cout << "Resource constructed" << endl;
	}

	Resource(unsigned length)
	{
		cout << "Resource length constructed" << endl;
		this->m_data = new int[length];
		this->m_length = length;
	}

	Resource(const Resource& res)
	{
		cout << "Resource copy constructed" << endl;

		Resource(res.m_length);

		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];
	}

	~Resource()  // ¼Ò¸êÀÚ
	{
		cout << "Resource destroyed" << endl;
	}

	Resource& operator = (Resource& res)
	{
		cout << "Resource copy assignment" << endl;

		if (&res == this) return *this;

		if (this->m_data != nullptr) delete[] m_data;

		m_length = res.m_length;

		m_data = new int[m_length];
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];

		return *this;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	void setAll(const int &value)
	{
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = value;
	}
};