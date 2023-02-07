#include<bits/stdc++.h>

using namespace std;

int n, h;
int MaxHeight = -1;
int MaxValue = -1;
int a[100][101];
bool visited[100][101];
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, 1, 0, -1};

void DFS(int nowY, int nowX)
{
	visited[nowY][nowX] = true;
	
	for(int i=0; i<4; ++i)
	{
		int nextY = nowY + deltaY[i];
		int nextX = nowX + deltaX[i];
		
		if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
		if(visited[nextY][nextX]) continue;
		
		DFS(nextY,nextX);
	}
}

int main(void)
{
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			cin >> a[i][j];
			if(a[i][j] > MaxHeight) MaxHeight = a[i][j];
		}
	}
	
	while(MaxHeight--)
	{
		fill(&visited[0][0],&visited[100][101],0);
		
		int count = 0;

		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(a[i][j] <= MaxHeight) visited[i][j] = true;
			}
		}
		
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(visited[i][j]) continue;
				
				DFS(i,j);
				count++;
			}
		}
		MaxValue = max(MaxValue, count);
	}
	
	cout << MaxValue << endl;
	return 0;
}
