class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()) return 0;
        int h[26]={0};
        int h2[26]={0};
        for(char c:s)
          h[c-'a']++;
        for(char c:t)
           h2[c-'a']++;
        for(int i=0;i<26;i++)
            if(h[i]!=h2[i])
              return 0;
        return 1; 
    }
};