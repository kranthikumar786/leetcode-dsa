class Solution {
public:
  
  void DFS(int src , int dest,vector<vector<int>>&Paths , vector<int>&path,vector<vector<int>>adj) {
            if(src == dest){
                 Paths.push_back(path);
                 return;
            }
          for(int i = 0 ;i < adj[src].size(); i++) {
                int neigh = adj[src][i];
                 path.push_back(neigh);
                 DFS(neigh,dest,Paths,path,adj);
                 path.pop_back();
          }  
  }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<vector<int>>Paths;
      int n = graph.size();
      vector<vector<int>>adj(n);
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ;j < graph[i].size() ; j++){
               int src = i;
               int dest = graph[i][j];
               adj[src].push_back(dest);
               }
             }
      vector<int>vi(n,0);
       vector<int>path;
       path.push_back(0);
     DFS(0,  n-1, Paths,path,adj);
     return Paths;
    }
};