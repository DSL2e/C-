#include<bits/stdc++.h>

using namespace std;
int n;
char a[101][101];
string s;

string quard(int y, int x, int size)
{
	string ret ="";
	if(size == 1) return string(1, a[y][x]);
	
	for(int i=y; i<y + size; i++)
	{
		for(int j=x; j<x + size; j++)
		{
			if(a[y][x] != a[i][j])
			{
				ret += "(";
				ret += quard(y, x, size/2);
				ret += quard(y, x + size/2, size/2);
				ret += quard(y + size/2, x, size/2);
				ret += quard(y + size/2, x + size/2, size/2);
				ret += ")";
				
				return ret;
			}
		}
	}
	
	return string(1, a[y][x]);
}
int main(void)
{
	cin >> n;
	
	for(int i=0; i<n; ++i)
	{
		cin >> s;
		
		for(int j=0; j<n; j++)
		{
			a[i][j] = s[j]; 
		}
	}
	
	cout << quard(0,0,n) << endl;
	
	return 0;
}
