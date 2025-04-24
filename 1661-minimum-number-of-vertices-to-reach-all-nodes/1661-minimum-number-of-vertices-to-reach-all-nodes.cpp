class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       vector<vector<int>>adj(n);
        vector<int>Indegree(n,0);
        for(auto edge : edges){
              adj[edge[0]].push_back(edge[1]);
                Indegree[edge[1]]++;
        }
       queue<int>Q;
       for(int i = 0 ;i < n ;i++){
              if(Indegree[i] == 0){
                Q.push(i);
              } 
       } 
      vector<int>ans;
      vector<int>visited(n,0);
      while(!Q.empty()) {
          int node = Q.front(); Q.pop();
          if(visited[node])
              continue;
           ans.push_back(node); 
         for(int neight : adj[node]) {
                visited[neight] = 1;
                Indegree[neight]--;   
             if(Indegree[neight] <= 0){
                Q.push(neight);
             }  
         }  
      } 
   return ans;
    }
};