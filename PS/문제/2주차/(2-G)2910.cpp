#include<bits/stdc++.h>

using namespace std;
int n,c;
map<int,int> mp;
int a[100004];
vector<pair<int,int>> v;

typedef pair<int,int> ii;

bool cmp(ii x, ii y)
{
	if(x.second == y.second)
	{
		return a[x.first] < a[y.first];
	}
	
	return x.second > y.second;
}

int main(void)
{
	cin >> n >> c;
	
	int num;
	for(int i=0; i<n; i++)
	{
		cin >> num;
		if(num > c)
		{
			i--;
			continue;
		}
		mp[num]++;
		if(a[num] == 0) a[num] = i+1;
		
	}
	
	for(auto& it: mp)
	{
		v.push_back({it.first, it.second});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto &e: v)
	{
		for(int i=0; i< e.second; i++)
			cout << e.first <<" ";
	}
	cout << endl;
	
	return 0;
}

