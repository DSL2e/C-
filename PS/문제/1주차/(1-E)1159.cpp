#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	vector<int> FirstNameAlphabat;
	FirstNameAlphabat.resize(26);
	vector<string> roster;
	int n;
	
	cin >> n;
	string temp;
	for(int i=0; i < n; ++i)
	{
		cin.ignore(1024, '\n');
		cin	>> temp;
		if(temp.length() > 30)
		{
			i--;
			continue;
		}
		
		roster.push_back(temp);
	}
	
	for(auto &e : roster)
	{
		FirstNameAlphabat[e[0] -'a']++;
	}
	
	// flag = 1 is 5 than 
	int flag = 0;
	for(int i=0; i<FirstNameAlphabat.size();++i)
	{
		if(FirstNameAlphabat[i] >= 5)
		{
			flag = 1;
			cout << static_cast<char>(i+'a');
		}
	}
	
	if(!flag) cout << "PREDAJA" << endl;
	return 0;
}
