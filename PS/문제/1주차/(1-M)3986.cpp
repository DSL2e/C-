#include<bits/stdc++.h>

using namespace std;
stack<char> a;
int n, cnt;
string word;
int main(void)
{
	cin >> n;
	for(int i=0;i <n; i++)
	{
		cin >> word;
		for(auto& e: word)

			if(a.size() && e == a.top()) a.pop();
			else a.push(e);
		}
		if(a.empty()) cnt++;
				
		while(!a.empty()) a.pop();
	}
	
	cout << cnt << endl;
	return 0;
}
