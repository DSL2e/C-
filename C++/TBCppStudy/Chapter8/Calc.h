#pragma once
#include<iostream>

class Calc
{
private:
	int m_value;

public:
	Calc(const int& val);

	Calc& add(const int& val);
	
	Calc& sub(const int& val);
	
	Calc& mult(const int& val);

	Calc& divi(const int& val);
	
	void print();
};