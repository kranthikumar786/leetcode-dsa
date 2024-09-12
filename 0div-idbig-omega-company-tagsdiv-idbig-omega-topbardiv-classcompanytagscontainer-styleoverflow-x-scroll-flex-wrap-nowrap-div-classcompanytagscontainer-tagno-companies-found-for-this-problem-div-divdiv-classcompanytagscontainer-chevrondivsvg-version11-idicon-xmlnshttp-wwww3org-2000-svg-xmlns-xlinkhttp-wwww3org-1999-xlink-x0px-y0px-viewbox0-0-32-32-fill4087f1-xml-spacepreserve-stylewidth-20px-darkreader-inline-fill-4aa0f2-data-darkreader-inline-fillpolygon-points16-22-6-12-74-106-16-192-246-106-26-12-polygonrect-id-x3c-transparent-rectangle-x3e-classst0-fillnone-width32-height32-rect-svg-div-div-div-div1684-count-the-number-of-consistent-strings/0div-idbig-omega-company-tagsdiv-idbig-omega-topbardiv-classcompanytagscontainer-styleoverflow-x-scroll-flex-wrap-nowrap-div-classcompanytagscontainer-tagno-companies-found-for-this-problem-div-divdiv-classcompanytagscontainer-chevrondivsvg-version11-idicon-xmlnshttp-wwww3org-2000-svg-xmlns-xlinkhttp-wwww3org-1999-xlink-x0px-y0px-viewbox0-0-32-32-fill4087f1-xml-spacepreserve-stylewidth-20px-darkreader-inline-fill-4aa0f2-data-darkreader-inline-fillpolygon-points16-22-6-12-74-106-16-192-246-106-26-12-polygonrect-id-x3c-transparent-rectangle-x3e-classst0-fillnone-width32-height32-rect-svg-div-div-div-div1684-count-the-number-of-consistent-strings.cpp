class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
       bitset<26>char_map(0);
        for(auto &t : allowed)char_map[t-'a']=1;
        int c = 0;        
        for(auto &t : words) {
            auto p = t.begin();
            while(char_map[*p-'a'])p++; 
            
            if(p==t.end())c++;  
        }
        return c;
    }
};