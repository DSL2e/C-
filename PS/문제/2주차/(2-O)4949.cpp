#include<bits/stdc++.h>
using namespace std;

string s = "string";
stack<char> Stack;
// yes(flag = 1) / no(flag = 0) 
int flag = 1;
int main(void)
{
	
	while(true)
	{
		flag = 1;
		getline(cin,s);

		if(s.size() == 1)
		{
			if(s[0] == '.') break;
		}
		
		if(s[s.size()-1] != '.') flag = 0;
		for(int i=0; i<s.size(); ++i)
		{
			if(!flag) break;
			
			if(s[i] == ']')
			{
				if(Stack.size() && Stack.top() == '[')
				{
					Stack.pop();
					continue;
				}
				Stack.push(s[i]); break;
			}
			
			if(s[i] == ')')
			{
				if(Stack.size() && Stack.top() == '(')
				{
					Stack.pop();
					continue;
				}
				Stack.push(s[i]); break;
			}
			if(s[i] == '(' || s[i] == '[')	Stack.push(s[i]);
		}
		
		if(flag)
		{
			if(Stack.empty()) cout << "yes\n";
			else cout << "no\n";
		}
		else cout << "no\n";
		
		while(!Stack.empty())
		{
			Stack.pop();
		}
	}
	return 0;
}
