#include<bits/stdc++.h>

using namespace std;

int T,M,N,K,X,Y;
int maze[51][51];
bool visited[51][51];
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, 1, 0, -1};
vector<int> CountT;

void DFS(int nowY, int nowX)
{
	visited[nowY][nowX] = true;
	
	for(int i=0; i<4; ++i)
	{
		int nextY = nowY + deltaY[i];
		int nextX = nowX + deltaX[i];
		
		if(nextY < 0 || nextY >= M || nextX < 0 || nextX >= N) continue;
		if(visited[nextY][nextX]) continue;
		if(maze[nextY][nextX]==0) continue;
		
		DFS(nextY,nextX);
	}
}
int main(void)
{
	cin >> T;
	while(T--)
	{
		fill(&maze[0][0], &maze[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    	int countNumber = 0;
    	
		cin >> M >> N >> K; 
		for(int i=0; i< K; ++i)
		{
			cin >> X >> Y;
			maze[X][Y] = 1;
		}		
	
		for(int i=0; i<M; ++i)
		{
			for(int j=0; j<N; ++j)
			{
				if(visited[i][j]) continue;
				if(maze[i][j] == 0) continue;
				
				DFS(i,j);
				countNumber++;
			}
		}
		CountT.push_back(countNumber);
	}
	
	for(auto &e: CountT)
		cout << e << endl;
	return 0;
}
