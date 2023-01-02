#include "Calc.h"


Calc::Calc(const int& val)
	: m_value(val)
{
}

Calc& Calc::add(const int& val)
{
	m_value += val;
	return *this;
}

Calc& Calc::sub(const int& val)
{
	m_value -= val;
	return *this;
}

Calc& Calc::mult(const int& val)
{
	m_value *= val;
	return *this;
}

Calc& Calc::divi(const int& val)
{
	m_value /= val;
	return *this;
}
void Calc::print()
{
	using namespace std;
	cout << m_value << endl;
}
