class Solution {
    private:
      vector<vector<int>>ans;
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      ans.resize(n,vector<int>()); 
      vector<vector<int>>List; 
      List.resize(n,vector<int>()); 

      for(int i=0;i<edges.size();i++)
         List[edges[i][0]].push_back(edges[i][1]);  

      for(int i=0;i<n;i++)  
        dfs(List,i,i); 
      
      return ans;
    }

    void dfs(vector<vector<int>>&List,int node,int parent)
    {
        
         for(auto n:List[node]) 
          if(ans[n].empty()|| ans[n].back()!=parent)
            {ans[n].push_back(parent);
            dfs(List,n,parent);
            }
           
    }
};