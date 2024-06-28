class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        for(auto it:roads)
        {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({indegree[i],i});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        long long ans=0;
        int j=n;
        for(int i=0;i<n;i++)
        {
            ans+=(long long)vp[i].first*(long long)j;
            j--;
        }
    
        return ans;
        
        
    }
};