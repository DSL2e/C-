#include<bits/stdc++.h>
using namespace std;

string s;
int lcnt, vcnt;

 bool isVowel(int idx)
 {
 	return (s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || 
	        s[idx] == 'o' || s[idx] == 'u');
 }
int main(void)
{
	while(true)
	{
		// flag - 1 (no) , flag - 0 (yes)
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;
		lcnt = 0;
		vcnt = 0;
		
		cin >> s;
		if(s == "end") break;
		
		// 검사
		for(int i=0; i < s.size(); i++)
		{
			if(isVowel(i)) is_include_v = 1, vcnt++, lcnt = 0;
			else vcnt = 0, lcnt++;
			//cout << s[i] << " " <<is_include_v << " " << vcnt << " " << lcnt << endl;
			// 연속 3개 
			if(vcnt >= 3 || lcnt >= 3) 
			{
				flag = 1; break;
			}
			// 연속 같은거 2개(e,o 제외) 
			if(i > 0 && s[prev] == s[i] && (s[i] != 'e' && s[i] != 'o'))
			{ 
				flag = 1; break;
			}
			prev = i;
		} 
		if(is_include_v == 0) flag = 1;
		
		if(flag) cout << "<" << s << ">" << " is not acceptable."<< endl;
		else cout << "<" << s << ">" << " is acceptable."<< endl;
	}
	return 0;
}
