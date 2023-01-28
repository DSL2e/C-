#include<bits/stdc++.h>
int main(void)
{
	std::string word;
	std::string ret;
	char mid;
	
	std::cin >> word;
	int cnt[26] = {0,};
	
	for(auto &e : word)
	{
		cnt[e -'A']++;
	}
	
	int flag = 0;
	for(int i=25; i>=0; --i)
	{
		if(cnt[i] & 1)
		{
			cnt[i]--;
			mid = i+'A';
			flag++;
		}
		if(flag == 2) break;
		
		for(int j=0; j < cnt[i]; j+=2)
		{
			ret = static_cast<char>((i + 'A')) + ret;
			ret += i + 'A';
		}
	}
	
	if(flag == 2) std::cout << "I'm Sorry Hansoo" << std::endl;
	else
	{
		if(mid) 
			ret.insert( ret.begin() + ret.size() / 2 , mid);
			
		std::cout << ret << std::endl;
	}
	
	return 0;
}
