#include<bits/stdc++.h>

using namespace std;
int t,n;
vector<int> v;
int main(void)
{
	cin >> t;
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);	
		
	while(t--)
	{
		int ret2 = 0;
		int ret5 = 0;
		
		cin >> n;
		
		for(int i=2; i <= n; i *=2)
			ret2 += n/i;
	
		for(int i=5; i <= n; i *=5)
			ret5 += n/i;
	
		cout << min(ret2, ret5) << endl;				
	}
	
	return 0;
}
