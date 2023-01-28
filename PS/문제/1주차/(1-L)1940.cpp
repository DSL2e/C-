#include<bits/stdc++.h> 
using namespace std; 
int n, m, a[150001], cnt;
int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i < n; i++) cin >> a[i];
	if(m > 200000) cout << 0 << endl;	
	else
	{
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j < n; j++)
			{
				if(a[i] + a[j] == m)
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
