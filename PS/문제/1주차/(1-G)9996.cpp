#include<bits/stdc++.h>
int main(void)
{
	int n;
	int star;
	std::vector<int> PatternCulativeSum;
	std::string pattern;
	std::vector<std::string> files;
	
	// input 
	std::cin >> n;
	std::cin.ignore(1024,'\n');
	std::cin >> pattern;
	
	std::string temp;
	for(int i=0; i < n; ++i)
	{
		std::cin.ignore(1024,'\n');
		std::cin >> temp;
		
		files.push_back(temp);
	}
	
	// pattern (cumulative sum)
	int int_pattern;
	PatternCulativeSum.push_back(pattern[0]);
	
	for(int i=1; i < pattern.size(); ++i)
	{
		int_pattern = static_cast<int>(pattern[i]);
		if(int_pattern == 42)
		{
			star = i;
			pattern[i] = '\0';
			i--;
			continue;
		}
			
		else if( 97 <= int_pattern && int_pattern <= 122)
		{
			PatternCulativeSum.push_back( PatternCulativeSum[PatternCulativeSum.size() -1] + int_pattern);
		}
	}
	int sum;
	int i;
	int count;
	// pattern and files match
	for(auto &e : files)
	{
		sum = 0;
		i = 0;
		count = 0;
		while(i < PatternCulativeSum.size())
		{	
			// *인 경우, 뛰어넘고 패턴만 비교 
			if(count == star) 
				count = e.size() - (pattern.size() -  (star + 1));
			
			// 누적합이 다르다면 break 
			sum += static_cast<int>(e[count]);
			if(sum != PatternCulativeSum[i] ) 
			{
				std::cout << "NE" << std::endl;
				break;
			}
			
			i++;
			count++;
		}
		if(sum == PatternCulativeSum.back()) std::cout << "DA" << std::endl;
	}
	
	return 0;
}
