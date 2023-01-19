#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	string word;
	
	cin >> word;
	
	int a[26] = {0, };
	
	for(auto &e : word)
	{
		a[e-'a']++;
	}
	
	for(auto &e : a)
		cout << e << " ";
		
	cout << endl;
	return 0;
}
