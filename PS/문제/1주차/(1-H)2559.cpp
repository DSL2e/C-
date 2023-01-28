#include<bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int n,k;
	vector<int> sequence;
	vector<int> psum;
	cin >> n >> k;

	psum.reserve(n+1);
	// 입력 및 누적합 
	int temperature;
	psum.push_back(0);
	for(int i=0; i < n; ++i)
	{
		cin >> temperature;
		psum.push_back(psum.back() + temperature);
	}

	// 연속된 최대 누적합
	int ret = INT_MIN; 

	for(int i = k; i <= n; i++){
		ret = max(ret, psum[i] - psum[i - k]);
	}
	cout << ret << endl;

	return 0;
}
