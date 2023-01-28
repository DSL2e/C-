#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	int n;
	int cnt;
	int value;
	
	while(cin >> n)
	{
		cnt =1;
		value =1;
		while(1)
		{
			if(value % n == 0) 
			{
				cout << cnt << endl;
				break;
			}
			else
			{
				value = (value * 10) + 1;
				value %= n;
				cnt++;
			}
		}	
	}
	return 0;
}
