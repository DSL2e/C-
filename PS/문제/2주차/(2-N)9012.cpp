#include<bits/stdc++.h>

using namespace std;

int n;
string s;
bool check(string s)
{
	stack<char> stk;
	for(atuo &e : s)
	{
		if(e == '(') stk.push(e);
		else
		{
			if(!stk.empty()) stk.pop();
			else return false;
		}
	}
	
	return stk.empty();
}
int main(void)
{
	stack<int> ss;
	
	cin >> n;
	
	while(n--)
	{
		cin >> s;
		for(int i=0; i<s.length(); ++i)
		{
			if(check(s)) cout << "YES\n";
			else cout << "NO\n";
		}

	}
	return 0;
}
