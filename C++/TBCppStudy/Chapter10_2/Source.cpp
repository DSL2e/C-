#include<iostream>
#include<cassert>
#include<string>
#include<vector>
#include "Monster.h"

using namespace std;

int main(void)
{
	Monster mon1("Sanson", Position2D(0, 0));

	cout << mon1 << endl;

	//while (1)
	{
		// event
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}

	return 0;
}

// 10.1 按眉甸狼 包拌
 // Composition(part-of), Aggregation(Has-a), Association(Uses-a), Dependency(Depends-on)

// 10.2 备己(Composition) 包拌
