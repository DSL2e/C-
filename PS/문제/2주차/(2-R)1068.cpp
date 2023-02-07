#include<bits/stdc++.h>
using namespace std;

vector<int> v[54];
int n,x,delNum,cnt,root;

int dfs(int node)
{
	int child = 0;
	int ret = 0;
	if(v[node].size() == 0) return 1;
	
	for(int i=0; i<v[node].size(); i++)
	{
		if(v[node][i] == delNum) continue;
		ret += dfs(v[node][i]);
		child++;
	}
	if(child == 0) return 1;
	
	return ret;
}

int main(void)
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		if(x == -1) {root = i; continue;} 
		v[x].push_back(i);	
	}
	
	cin >> delNum;
	
	if(delNum == root) cout << "0" << endl;
	else cout << dfs(root) << endl;
	
	return 0;
}
