#include<bits/stdc++.h>
using namespace std;

class Cost
{
private:
	int A;
	int B;
	int C;
	int sum = 0;

public:
	Cost()
	{
		A = 0;
		B = 0;
		C = 0;
	}

	Cost(int* cost)
	{
		A = cost[0];
		B = cost[1];
		C = cost[2];
	}

	enum Discount
	{
		One = 1,
		Two = 2,
		Three = 3
	};

	int getA() { return A; }
	int getB() { return B; }
	int getC() { return C; }
	int Sum(int PartSum) { return sum += PartSum; }
	const int& getSum() { return sum; }
};

int main(void)
{
	int temp;
	int cost[3];

	cin >> cost[0] >> cost[1] >> cost[2];

	Cost MyCost(cost);

	int intersection_time[101] = { 0, };
	int time[2] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		cin >> time[0] >> time[1];
		for (int start = time[0]; start < time[1]; ++start)
			intersection_time[start]++;
	}
	for (int i = 1; i < 100; ++i)
	{
		if (intersection_time[i] == 0) continue;

		switch (intersection_time[i])
		{
		case MyCost.One:
			MyCost.Sum(MyCost.getA());
			break;
		case MyCost.Two:
			MyCost.Sum(MyCost.getB() * 2);
			break;
		case MyCost.Three:
			MyCost.Sum(MyCost.getC() * 3);
			break;
		}
	}

	cout << MyCost.getSum() << endl;

	return 0;
}
