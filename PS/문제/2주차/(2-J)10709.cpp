#include<bits/stdc++.h>
using namespace std;
int h,w;
string cloud;
int a[101][101];

int main(void)
{
	int h,w;
	
	cin >> h >> w;
	
	for(int i=0; i<h; i++)
	{
		cin >> cloud;
		
		for(int j=0; j<w; ++j)
		{
			if(cloud[j] == '.') a[i][j] = -1;
		}
		
		for(int j=0; j<w; ++j)
		{
			if(cloud[j] == 'c')
			{			
				int count=0;
				for(int k=j+1; k<w; ++k)
				{
					count++;
					if(a[i][k] == -1 || a[i][k] > count) 
					{
						a[i][k] = count;
					}
				}
			}
		}
	}
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
			cout << a[i][j] << " ";
		
		cout << endl;
	}
	
	return 0;
}
