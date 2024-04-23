class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1) return vector<int>{0};
        
        vector<vector<int>>graph(n);
        
        vector<int>degree(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
            
            degree[a]++;
            degree[b]++;
        }
        
        queue<int>Q;
        
        for(int i=0;i<n;i++)
            if(degree[i]==1)Q.push(i);

        vector<int>res;
        
        while(!Q.empty())
        {
            int n = Q.size();
            
            res.clear();
            
            while(n--)
            {
                int node = Q.front();
                Q.pop();
                
                res.push_back(node);
                
                for(int i=0;i<graph[node].size();i++)
                {
                    degree[graph[node][i]]--;
                    
                    if(degree[graph[node][i]]==1)
                    {
                        Q.push(graph[node][i]);
                    }
                }
            }
        }
        return res;
    }
};