class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size(),c=0;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
            m[s[i]]++;
        for(auto x:m)
            if(x.second%2!=0) c++;
        if(c>1)
        return n-c+1;
        return n;
    }
};