#include <bits/stdc++.h>
using namespace std;

/*int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int i = 0;
	int height;
	int a[9];
	while(i < 9)
	{
		cin >> height;
		if(height > 100)
		{
			cout << "re" << endl;
			continue;
		}
		a[i] = height;
		++i;
	}
	
	sort(a,a+9);
	
	int sum;
	while(next_permutation(a,a+9))
	{
		sum = 0;
		for(int i=0;i<7;++i) sum += a[i];
		if(sum == 100) 
		{
			for(int i = 0; i < 7; i++) cout << a[i] << "\n";
			break; 
		}
	}	
	cout << endl;
    return 0;
}*/

/* 재귀함수 
int flag = 0;
void make_permutation(int* arr, int n, int r, int depth)
{
	if(depth == r)
	{	
		int sum = 0;
		for(int i = 0; i < 7; ++i) sum += arr[i];
			
		if(sum == 100 && flag == 0)
		{
			cout << "결과 출력" << endl; 
			for(int i= 0; i < 7; ++i)	
				cout << arr[i] << endl;
			flag = 1;
		}
		return;
	}
	
	for(int j=depth; j < n; ++j)
	{
		swap(arr[depth],arr[j]);
		make_permutation(arr,n,r,depth+1);
		swap(arr[depth],arr[j]);
	}
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int i = 0;
	int height;
	int a[9];
	while(i < 9)
	{
		cin >> height;
		if(height > 100)
		{
			cout << "re" << endl;
			continue;
		}
		a[i] = height;
		++i;
	}
	
	sort(a,a+9);
	make_permutation(a,9,7,0);
	
	return 0;
}
*/

// combination - 9C2
pair<int,int> p;
void Combi(auto a, int all_sum)
{
	int temp = all_sum;
	for(int i = 0; i < 8; ++i)
	{
		
		for(int j=i+1; j< 9; ++j)
		{
			all_sum -= (a[i] + a[j]);
			if(all_sum == 100)
			{
				p.first = i;
				p.second = j;
			}
			all_sum = temp;
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int i = 0;
	int height;
	vector<int> a;
	while(i < 9)
	{
		cin >> height;
		if(height > 100)
		{
			cout << "re" << endl;
			continue;
		}
		a.push_back(height);
		++i;
	}
	
	sort(a.begin(),a.end());
	
	int sum = 0;
	for(auto & e : a)
		sum += e;
		
	Combi(a, sum);
	
	for(i=0; i<9; ++i)
	{
		if(i == p.first || i == p.second ) continue;
		
		cout << a[i] << endl;
	}
	return 0;
}

