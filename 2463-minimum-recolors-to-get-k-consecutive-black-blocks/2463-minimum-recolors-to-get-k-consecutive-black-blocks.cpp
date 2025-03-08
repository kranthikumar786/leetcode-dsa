class Solution {
public:
    int minimumRecolors(string s, int k) {
        int ans=INT_MAX;
        int c=0;
        int start=0;
        int end=0;
        while(end<s.length())
        {
            if(end-start+1<=k)
            {
                if(s[end]=='W')
                {
                    c++;
                }
                if(end-start+1==k)
                {
                    ans=min(ans,c);
                }
                end++;
            }
            else
            {
                if(s[start]=='W')
                {
                    c--;
                }
                start++;
            }
        }
        return ans;
    }
};