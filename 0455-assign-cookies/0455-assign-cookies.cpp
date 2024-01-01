class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int contentChidren = 0;
        int cookieIndex = 0;
        
        while (cookieIndex < s.size() && contentChidren < g.size()) {
            
               if(s[cookieIndex] >= g[contentChidren]){
                     contentChidren++;
               }
               cookieIndex++;
        }
        return contentChidren;
    }
};