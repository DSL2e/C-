#include<bits/stdc++.h>

using namespace std;

int a[101][101], dist[101][101];
bool v[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> q;

int main(void)
{
	int n,m;
	string s;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		for(int j=0; j<s.size();++j)
		{
			a[i][j] = s[j] - '0';			
		}
	}
	
	q.push({0,0});
	dist[0][0] = 1;
	
	while(!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		v[nowY][nowX] = true;
		for(int i=0; i<4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];
			if(!a[nextY][nextX]) continue;
			if(v[nextY][nextX] || nextY < 0 || nextY >=n || nextX < 0 || nextX >=m) continue;
			
			dist[nextY][nextX] = dist[nowY][nowX] + 1;
			q.push({nextY,nextX});
		}
	}
	
	cout << dist[n-1][m-1] << endl;
}
