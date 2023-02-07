#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
bool visited[10001];
int dp[10001];
int n,m,x,y;

int dfs(int node)
{
	visited[node] = true;
	int ret = 1;
	
	for(auto &e: v[node])
	{
		if(visited[e]) continue;
		ret += dfs(e);
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i)
	{
		cin >> x >> y;
		v[y].push_back(x);
	}
	
	int mx = 0;
	for(int i=1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		mx = max(mx,dp[i]);
	}
	for(int i=0; i <= n; i++) if(mx == dp[i]) cout << i << " ";
	return 0;
}


