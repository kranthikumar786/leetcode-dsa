class Solution {
    public boolean dfs(int parent, int src, boolean visited[] , List<List<Integer>> adjList){
        visited[src] = true;
         for(int neightbour : adjList.get(src)) {
              if(!visited[neightbour]){
                 if(dfs(src,neightbour,visited,adjList)){
                     return true;
                 }
              } else if(parent  != neightbour ) {
                  return true;
              }
         }
         return false;  
    }
    public int[] findRedundantConnection(int[][] edges) {
     int n = edges.length;
     List<List<Integer>> adjList = new ArrayList<>();
     for(int i = 0 ;i <= n ;i++) {
        adjList.add(new ArrayList<>());
     }
     int ans[] = new int[2];
     for(int edge[] : edges){
         int u = edge[0];
         int v = edge[1];
         adjList.get(u).add(v);
         adjList.get(v).add(u);
           boolean visited[] = new boolean[n+1];
          if(dfs(-1,u,visited,adjList)){
            ans[0] = u;
            ans[1] = v;
             break;
          }
     }
   return ans;
    }
}