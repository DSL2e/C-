#include<bits/stdc++.h>

using namespace std;
int n,m,l, r, ret;
int j;
int main(void)
{
	cin >> n >> m;
	cin >> j;
	
	int pos;
	l = 1;
	r = l + m -1;
	
	while(j--)
	{
		cin >> pos;
		if(pos >= l && pos <=r) continue;
		
		if(pos < l)
		{
			ret += l - pos;
			l = pos;
			r = l + m -1; 
		}
		
		else
		{
			ret += pos - r;
			r = pos;
			l = r - m + 1;
		}
	}
	
	cout << ret << endl;
	return 0;
}
