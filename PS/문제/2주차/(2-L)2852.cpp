#include<bits/stdc++.h>
using namespace std;
#define prev asdf
int n, o, A, B, asum, bsum;
string s, prev;

void print(int t)
{
	string a = "00" + to_string(t / 60);
	string b = "00" + to_string(t % 60);
	
	cout << a.substr(a.size() - 2, a.size()) << ":" 
		 << b.substr(b.size() - 2, b.size());
	cout << endl;
}

int go()
{
	return (stoi(s.substr(0,2))*60 + stoi(s.substr(3,5))) -
			(stoi(prev.substr(0,2))*60 + stoi(prev.substr(3,5)));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	

	while(n--)
	{
		cin >> o >> s;
		
		if(A > B) asum += go();
		else if(A < B) bsum += go();
		o == 1 ? A++ : B++;   
		
		prev = s;
	}
	s = "48:00";
	if(A > B) asum += go();
	else if(A < B) bsum += go();
	
	print(asum);
	print(bsum);
	return 0;
}

	
