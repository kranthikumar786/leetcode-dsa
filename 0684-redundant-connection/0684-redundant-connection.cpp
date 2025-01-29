class Solution {
public:
  bool dfs(int parent, int src,vector<int>& visited,vector<vector<int>>& adjList) {
          visited[src] = 1;
       for(auto neighbour : adjList[src]) {
           if(!visited[neighbour]) {
              if(dfs(src,neighbour,visited,adjList)){
                 return 1;
              }
           } else if(parent != neighbour){
                    return 1;
           }
       }
        return 0; 
  }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int n = edges.size();
      vector<vector<int>>adjList(n+1);
      vector<int>removedEdge;
       for(auto& edge  : edges){
          int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
         vector<int>visited(n+1,0);
          if(dfs(-1,u,visited,adjList)){
             removedEdge = {u,v};
             break;
          } 
       }
    return removedEdge;
    }
};