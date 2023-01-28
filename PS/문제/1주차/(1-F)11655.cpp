#include<bits/stdc++.h>

int main(void)
{
	std::string str;
	
	std::getline(std::cin, str);
	
	for(int i=0; i < str.size(); ++i)
	{
		int int_str = static_cast<int>(str[i]);
	
		// space skip
		if(int_str == 32) continue;
			
		// uppercase
		if( 65 <= int_str && int_str <= 90)
		{
			if(int_str + 13 > 90)
			{
				int_str = int_str + 13 - 91;
				str[i] = 'A' + int_str;
			}
			else str[i] += 13; 
		}
		
		// Lowercase
		else if('a' <= int_str && int_str <= 'z' )
		{
			if(int_str + 13 > 122)
			{
				int_str = int_str + 13 - 123;
				str[i] = 'a' + int_str;
			}
			else str[i] += 13; 
		}
		
	}
	
	std::cout << str << std::endl;
	
	
	return 0;
}
