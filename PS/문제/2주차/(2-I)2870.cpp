#include<bits/stdc++.h>
using namespace std;

string a;
int m;

int NumIndex()
{
	
	for(int i=0; i< a.length(); ++i)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			return i;
		}
	}
	return -1;
}

int AlphabatInedex()
{
	for(int i= 0; i < a.length(); ++i)
	{
		if(a[i] >= 'a' && a[i] <= 'z')
		{
			return i;
		}
	}
	return -1;
}

void go(string& num)
{
	while(true)
	{
		if(num.size() && num.front() == '0') num.erase(num.begin());
		else break;
	}
	
	if(num.size() == 0) num = "0";
}

bool cmp(string first, string second)
{
	if(first.size() == second.size())
	{
			return first < second;
	}

	return first.size() < second.size();
}
int main(void)
{
	vector<string> v;
	cin >> m;
	while(m--)
	{
		cin >> a;	
		while(true)
		{
			int pos = -1;
			int flag = 0;
			if(a[0] >= '0' && a[0] <= '9') flag = 1;
			
			if(flag) pos = AlphabatInedex();
			else 	 
			{
				pos = NumIndex();
				if(pos == -1) break;
				a.erase(0,pos);
				continue;
			}
			if(pos == -1) break;
			v.push_back(a.substr(0,pos));
			a.erase(0,pos);
		}
		if(a[0] >= '0' && a[0] <= '9')  v.push_back(a);
	}
	
	for(auto&e : v)
	{
		go(e);
	}
	
	sort(v.begin(),v.end(), cmp);
	
	for(auto &e: v)
		cout << e << "\n";
	return 0;
}
