#include<bits/stdc++.h>

using namespace std;
int m,n,k;
int a[101][101];
bool visited[101][101];
vector<int> width;
int dY[4] = {-1, 0, 1, 0};
int dX[4] = {0, 1, 0, -1};

int dfs(int nowY, int nowX)
{
	visited[nowY][nowX] = true;
	int ret = 1;
	
	for(int i=0; i < 4; ++i)
	{
		int nextY = nowY + dY[i];
		int nextX = nowX + dX[i];
		
		if(nextY < 0 || nextY >= m || nextX < 0 || nextX >= n) continue;
		if(visited[nextY][nextX] || a[nextY][nextX] == 1) continue;
		ret += dfs(nextY,nextX);
	}
	
	return ret;
}
int main(void)
{
	cin >> m >> n >> k;
	
	for(int i=0; i<k; i++)
	{	
		int x[2],y[2] = {0,};
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		
		for(int i=y[0]; i < y[1]; ++i)
			for(int j=x[0]; j < x[1]; ++j)
				a[i][j] = 1;
	}
	
	int ConnectedComponent = 0;
	int count = 0;
	for(int i=0; i < m; ++i)
	{
		int count = 0;
		for(int j=0; j < n; ++j)
		{
			if(visited[i][j]) continue;
			if(a[i][j]) continue;
			
			ConnectedComponent++;
			width.push_back(dfs(i,j));
		}
	}
	
	cout << ConnectedComponent << endl;
	sort(width.begin(), width.end());
	for(auto& e: width)
		cout << e << " ";
	cout << endl;
	
	return 0;
}
