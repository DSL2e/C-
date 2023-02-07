#include<bits/stdc++.h>
using namespace std;

int a[101][101];
bool v[101][101];	
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n,m;
int cnt;

int dfs(int nowY, int nowX)
{
	int c = 0;
	v[nowY][nowX] = true;
	
	if(a[nowY][nowX] == 1)
	{
		a[nowY][nowX] = 0;
		c++;
		return c;
	}
	
	for(int i=0; i<4; ++i)
	{
		int nextY = nowY + dy[i];
		int nextX = nowX + dx[i];
		
		if(v[nextY][nextX] || nextY  < 0 || 
		   nextY  >= n     || nextX  < 0 || nextX  >= m) continue;
		
		c += dfs(nextY, nextX);
	}
	return c;
}

int main(void)
{
	cin >> n >> m;
	
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			cin >> a[i][j];
			if(a[i][j] == 1) cnt++;
		}
	}
	
	int prev = cnt;
	int time = 0;
	while(true)
	{
		fill(&v[0][0],&v[0][0] + 101*101, 0);
		cnt -= dfs(0,0);
		time++;
		if(cnt == 0) break;
		prev = cnt;
	}
	
	cout << time << endl;
	cout << prev << endl;
	return 0;
}
