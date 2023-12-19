
class Solution {
public:
bool isMatchHelper(string text, string pattern) {
	int n = text.length();
	int m = pattern.length();
	int i = 0, j = 0, startIndex = -1, match = 0;

	while (i < n)
	{
		if (j < m && (pattern[j] == '?' || pattern[j] == text[i]))
		{
			
			i++;
			j++;
		}
		else if (j < m && pattern[j] == '*')
		{
				startIndex = j;
			match = i;
			j++;
		}
		else if (startIndex != -1)
		{
			
			j = startIndex + 1;
			match++;
			i = match;
		}
		else
		{
				return false;
		}
	}

	while (j < m && pattern[j] == '*')
	{
		j++;
	}

		return j == m;
}

    bool isMatch(string s, string p) {
   return isMatchHelper(s,p);  
    }    
};

