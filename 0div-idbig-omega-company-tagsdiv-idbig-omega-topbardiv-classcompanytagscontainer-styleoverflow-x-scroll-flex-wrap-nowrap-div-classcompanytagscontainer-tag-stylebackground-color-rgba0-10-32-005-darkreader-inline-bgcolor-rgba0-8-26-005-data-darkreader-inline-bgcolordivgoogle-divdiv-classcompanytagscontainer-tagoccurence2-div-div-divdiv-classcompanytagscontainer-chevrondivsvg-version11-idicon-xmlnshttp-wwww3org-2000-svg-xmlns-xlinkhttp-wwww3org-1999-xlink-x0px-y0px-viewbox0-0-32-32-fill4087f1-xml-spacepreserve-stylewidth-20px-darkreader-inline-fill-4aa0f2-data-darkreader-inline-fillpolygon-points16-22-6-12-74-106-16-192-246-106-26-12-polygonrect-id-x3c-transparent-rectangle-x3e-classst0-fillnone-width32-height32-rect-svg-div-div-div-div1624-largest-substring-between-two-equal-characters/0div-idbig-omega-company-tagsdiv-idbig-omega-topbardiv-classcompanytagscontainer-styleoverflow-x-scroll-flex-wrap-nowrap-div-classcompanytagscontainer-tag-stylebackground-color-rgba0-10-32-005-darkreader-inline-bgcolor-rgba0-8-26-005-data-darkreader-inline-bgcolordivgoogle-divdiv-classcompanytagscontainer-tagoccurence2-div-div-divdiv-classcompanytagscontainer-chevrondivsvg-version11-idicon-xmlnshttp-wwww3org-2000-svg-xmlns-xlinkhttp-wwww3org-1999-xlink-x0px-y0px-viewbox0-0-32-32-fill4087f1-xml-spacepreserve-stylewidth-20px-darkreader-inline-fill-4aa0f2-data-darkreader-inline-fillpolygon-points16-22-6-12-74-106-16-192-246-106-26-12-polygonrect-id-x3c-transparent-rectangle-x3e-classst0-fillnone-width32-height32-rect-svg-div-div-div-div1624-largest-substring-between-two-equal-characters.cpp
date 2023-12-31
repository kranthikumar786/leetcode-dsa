class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>firstIndex;
        
        int ans = -1;
        int n= s.size();
        for(int index = 0 ; index < n ; index++ ) {
            
            if(firstIndex.find(s[index]) != firstIndex.end()){
                 ans = max(ans, index-firstIndex[s[index]]-1);
            } else{
                firstIndex[s[index]] = index;
            }
            
        }
        return ans;
    }
};