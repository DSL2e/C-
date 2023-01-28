#include<bits/stdc++.h> 

using namespace std;
int main(void)
{
	string word;
	string reversed_word;
	
	cin >> word;
	reversed_word = word;
	reverse(reversed_word.begin(), reversed_word.end());
	
	//flag = 1 is match 
	int flag = 1;
	if(word.size() != reversed_word.size()) flag = 0;
	
	// if(word == reverse_word) cout << 1 << endl;
	// else cout << 0 << endl;
	for(int i=0; i < word.size(); ++i)
	{
		
		if(word[i] == reversed_word[i]) continue;
		
		flag = 0;
		break;
	}
	cout << flag << endl;
	return 0;
}
