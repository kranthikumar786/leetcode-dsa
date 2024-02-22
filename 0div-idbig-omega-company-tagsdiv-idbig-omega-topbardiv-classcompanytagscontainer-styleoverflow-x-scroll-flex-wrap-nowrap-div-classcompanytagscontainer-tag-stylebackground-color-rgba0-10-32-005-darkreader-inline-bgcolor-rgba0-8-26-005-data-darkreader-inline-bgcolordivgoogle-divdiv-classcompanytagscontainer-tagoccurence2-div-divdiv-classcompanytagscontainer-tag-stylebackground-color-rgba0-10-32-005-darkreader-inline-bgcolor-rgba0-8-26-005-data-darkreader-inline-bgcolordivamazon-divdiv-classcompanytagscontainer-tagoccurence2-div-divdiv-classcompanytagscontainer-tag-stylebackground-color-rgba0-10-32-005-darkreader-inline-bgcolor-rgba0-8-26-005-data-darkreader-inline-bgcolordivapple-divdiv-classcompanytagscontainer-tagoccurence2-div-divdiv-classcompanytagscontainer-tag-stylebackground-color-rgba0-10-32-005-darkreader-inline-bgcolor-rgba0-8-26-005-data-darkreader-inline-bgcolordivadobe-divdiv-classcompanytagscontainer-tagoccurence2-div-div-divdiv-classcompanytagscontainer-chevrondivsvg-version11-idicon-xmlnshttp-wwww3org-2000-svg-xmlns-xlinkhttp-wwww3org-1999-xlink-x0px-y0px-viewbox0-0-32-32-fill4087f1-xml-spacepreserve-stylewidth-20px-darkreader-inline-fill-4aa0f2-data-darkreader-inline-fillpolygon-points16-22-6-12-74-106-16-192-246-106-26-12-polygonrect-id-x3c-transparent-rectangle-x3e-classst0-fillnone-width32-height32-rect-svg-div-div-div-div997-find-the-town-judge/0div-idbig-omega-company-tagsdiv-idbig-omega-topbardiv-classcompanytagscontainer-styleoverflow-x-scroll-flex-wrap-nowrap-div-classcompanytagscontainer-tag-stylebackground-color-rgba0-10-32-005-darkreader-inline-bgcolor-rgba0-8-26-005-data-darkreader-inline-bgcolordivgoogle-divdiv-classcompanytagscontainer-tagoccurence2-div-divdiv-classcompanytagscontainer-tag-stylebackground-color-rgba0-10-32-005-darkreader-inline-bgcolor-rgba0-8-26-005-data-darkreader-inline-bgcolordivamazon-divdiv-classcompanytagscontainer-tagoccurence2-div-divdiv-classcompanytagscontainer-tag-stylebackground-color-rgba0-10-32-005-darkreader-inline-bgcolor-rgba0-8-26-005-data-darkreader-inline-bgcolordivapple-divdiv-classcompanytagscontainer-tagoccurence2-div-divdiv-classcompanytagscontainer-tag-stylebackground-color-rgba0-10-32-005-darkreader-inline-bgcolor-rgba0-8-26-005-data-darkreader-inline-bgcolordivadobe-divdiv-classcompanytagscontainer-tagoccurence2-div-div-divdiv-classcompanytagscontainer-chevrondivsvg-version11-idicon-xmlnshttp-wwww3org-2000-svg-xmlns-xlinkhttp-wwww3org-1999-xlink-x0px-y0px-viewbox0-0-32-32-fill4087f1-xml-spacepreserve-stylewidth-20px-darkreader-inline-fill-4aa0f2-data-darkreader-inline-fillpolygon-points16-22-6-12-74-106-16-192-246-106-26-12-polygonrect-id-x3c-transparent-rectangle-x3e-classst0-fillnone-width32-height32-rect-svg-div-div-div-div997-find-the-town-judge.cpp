class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
       if(N==1)
         return 1;
        unordered_map<int,pair<int,int>>degrees;
        for(auto edge:trust)
        {
            degrees[edge[1]].first++;
            degrees[edge[0]].second++;
        }
        for(auto it:degrees){
            
            if(it.second.first==N-1 && it.second.second==0)
                return it.first;
        }
        
        return -1;
    }
};