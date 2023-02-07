#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[9][9];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool v[9][9];
vector<pair<int,int>> wall;
vector<pair<int,int>> virus;

void dfs(int nowY, int nowX)
{
	v[nowY][nowX] = true;
	
	for(int i=0; i<4; ++i)
	{
		int nextY = nowY + dy[i];	
		int nextX = nowX + dx[i]; 
		
		if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || 
		   v[nextY][nextX] || a[nextY][nextX] == 1) continue;
		
		dfs(nextY, nextX);
	}
}

int solve()
{	
	fill(&v[0][0], &v[0][0] + (9 * 9), false);
	for(int i=0; i<virus.size(); ++i)
	{
		dfs(virus[i].first, virus[i].second);
	}
	
	int num = 0;
	
	for(int i=0; i <n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			if(a[i][j] == 0 && v[i][j] == false) num++;
		}
	}
	
	return num;
}


int main(void)
{
	cin >> n >> m;
	int ret;
	for(int i=0; i <n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			cin >> a[i][j];
			if(a[i][j] == 0) wall.push_back({i,j});
            if(a[i][j] == 2) virus.push_back({i, j});		
		}
	}
	
	for(int i=0; i <wall.size()-2; ++i)
	{
		for(int j= i + 1; j<wall.size()-1; ++j)
		{
			for(int k=j + 1; k<wall.size(); ++k)
			{
				a[wall[i].first][wall[i].second] = 1;
				a[wall[j].first][wall[j].second] = 1;
				a[wall[k].first][wall[k].second] = 1;
				ret = max(ret, solve());
				a[wall[i].first][wall[i].second] = 0;
				a[wall[j].first][wall[j].second] = 0;
				a[wall[k].first][wall[k].second] = 0;			
			}
		}
	}
	
	cout << ret << endl;
	return 0;
}
