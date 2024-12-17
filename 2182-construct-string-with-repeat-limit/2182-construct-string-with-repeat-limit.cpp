class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        
        for(auto it : s) mp[it]++;
        
        string ans;
        
        priority_queue<pair<char,int>> pq;
        
        for(auto it : mp) pq.push({it.first,it.second});
        
        while(!pq.empty()){
            int limit = repeatLimit;
            auto top = pq.top(); pq.pop();
            
            char val = top.first;
            int freq = top.second;
            
            while(limit and freq){
                ans += val;
                limit--; freq--;
                
                if(freq == 0) break;
                if(limit == 0){
                    
                    if(pq.empty()) break;
                    
                    else{
                        auto it = pq.top(); pq.pop();
                        ans += it.first;
                        if(it.second-1 > 0) pq.push({it.first,it.second-1});
                    }
                    
                    limit = repeatLimit;
                    
                }
            }
            
            }
        
        return ans;
    }
};