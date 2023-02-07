#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int deltaY[4] = {-1, 0, 1, 0};
	int deltaX[4] = {0, 1, 0, -1};
	
	pair<int,int> p;
	p = make_pair(3,4);

	int map[100][100];
	bool visitied[100][100];
	int distance[100][100];
	

	int n,m;
		
	cin >> n >> m;
	
	fill(&distance[0][0], &distance[n-1][m], INT_MAX);
	
    for (int i=0; i<n; ++i){ 

        string row; 
        cin >> row;

        for (int j=0; j<m; ++j)
            map[i][j] = static_cast<int>(row[j]-'0');
    }
	
	
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	visitied[0][0] = true;
	distance[0][0] = 1;
	
	
	
	pair<int,int> now;
	while(!q.empty())
	{
		now = q.front();

		q.pop();
		for(int i=0; i < 4; ++i)
		{
			int nextY = now.first + deltaY[i];
			int nextX = now.second + deltaX[i];
			 		
				
			if(nextY < 0 || nextY >= n) continue;
			if(nextX < 0 || nextX >= m) continue;
			if(map[nextY][nextX] == 0) continue;
			if(visitied[nextY][nextX]) continue;
			
			visitied[nextY][nextX] = true;
			distance[nextY][nextX] = distance[now.first][now.second] + 1;
			
			q.push(make_pair(nextY,nextX));
		}
	}	
	
	cout << distance[n-1][m-1] << endl;
}
