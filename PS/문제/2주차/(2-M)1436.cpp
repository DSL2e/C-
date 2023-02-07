#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int i = 666;
	
	for(;;i++)
	{
		if(to_string(i).find("666") == string::npos) continue;
		
		n--;
		if(n == 0) break;
	}
	
	cout << i << endl;
	return 0;
}
