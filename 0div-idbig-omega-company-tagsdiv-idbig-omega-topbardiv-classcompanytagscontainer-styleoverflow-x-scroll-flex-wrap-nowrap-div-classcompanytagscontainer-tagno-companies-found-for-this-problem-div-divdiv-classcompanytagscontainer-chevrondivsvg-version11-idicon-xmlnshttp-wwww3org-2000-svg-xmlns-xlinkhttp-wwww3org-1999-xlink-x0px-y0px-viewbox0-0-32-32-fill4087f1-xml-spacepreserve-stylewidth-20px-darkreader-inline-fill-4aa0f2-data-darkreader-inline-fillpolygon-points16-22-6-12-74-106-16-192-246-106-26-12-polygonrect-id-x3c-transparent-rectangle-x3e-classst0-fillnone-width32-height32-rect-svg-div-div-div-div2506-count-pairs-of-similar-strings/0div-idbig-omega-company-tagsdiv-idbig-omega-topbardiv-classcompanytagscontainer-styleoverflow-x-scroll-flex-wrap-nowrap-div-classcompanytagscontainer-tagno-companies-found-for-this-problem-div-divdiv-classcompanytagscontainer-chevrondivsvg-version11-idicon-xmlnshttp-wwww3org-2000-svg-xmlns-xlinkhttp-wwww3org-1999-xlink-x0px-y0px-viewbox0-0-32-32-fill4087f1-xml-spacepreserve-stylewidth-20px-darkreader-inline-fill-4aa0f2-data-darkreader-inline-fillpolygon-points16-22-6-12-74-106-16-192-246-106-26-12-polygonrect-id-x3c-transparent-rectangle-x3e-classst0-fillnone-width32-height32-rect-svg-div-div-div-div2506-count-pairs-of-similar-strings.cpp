class Solution {
public:
    int similarPairs(vector<string>& W) 
    {
        map<set<char>, int> H; 
        for(auto c: W)
        {
            set<char> S; 
            for(auto k: c)
                S.insert(k); 
            H[S]++; 
        }
        
        int ans = 0; 
        for(auto c: H)
            ans += (c.second * (c.second-1)) / 2;
        
        return ans;
    }
};