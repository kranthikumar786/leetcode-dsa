class Solution {
public:
    int ans;
    
    vector<vector<int>>adj;
    
    long long dfs(int node,int p,int k,vector<int>& values){
        
        long long sum=values[node];
        
        for(auto it:adj[node]){
            if(it!=p) sum+=dfs(it,node,k,values);
        }
        
        if(sum%k==0){
             ans++;
            return 0;
        }
        else return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        ans=0;
        adj.resize(n+1);
        
        for(auto it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
         
        dfs(0,-1,k,values);
        
        return ans;
    }
};