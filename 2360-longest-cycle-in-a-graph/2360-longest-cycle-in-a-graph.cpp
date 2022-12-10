 /* 
  class Solution {
public:
    vector<vector<int>>adj;
    int ans = -1;
    bool vis[100001];
    int dfsVis[100001];
    void depth(int node,int par,int val) {
        vis[node]=true;
        dfsVis[node]=val;
        for( auto nextNode : adj[node] ) {
            if( !vis[nextNode] ) {
                depth(nextNode,node,val+1);
            } else if(dfsVis[nextNode]) {
                ans=max(ans,val-dfsVis[nextNode]+1);
            }
        }
        dfsVis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        adj.resize(edges.size());
        int n = edges.size();
        memset(vis,false,sizeof(vis));
        memset(dfsVis,0,sizeof(dfsVis));
        for (int i = 0; i < n ; i++) { 
           if(edges[i] != -1) {
             adj[i].push_back(edges[i]);
            }
        }
        for( int i = 0;i < n ; i++) {
                depth(i,-1,1);
            }
        return ans;     
    }
};
/*
approach1Complexity = {
       SpaceComplexity = O(V+E) + O(V),
       SpaceComplexity = O(V+E)
};
*/

class Solution {
public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size(),res = -1;
    vector<pair<int,int>>distArray(n,{-1,-1});
    for (int i = 0 ; i < n ; i++ ) {
        for (int  j = i , dist = 0 ; j != -1 ; j = edges[j]) {
          auto [dist_i,from_i] = distArray[j];
             if ( dist_i == -1){
                 distArray[j] = {dist++,i};
             } else {
                  if ( from_i == i) {
                        res = max( res, dist - dist_i);
                  }
                  break;
             }   
        } 
    }  
    return res;
  }
  };

/*
approach2Complexity = {
       TimeComplexity = O(V),
       SpaceComplexity = O(V)
};

*/
  /*
  imp points:
1) approach2 you can't apply for normal find cycle in directed or undirected graph until if sure only one child for one parent:
2) This Question conating only one child one parent 
3) some time you don't need to convert given input into adjlist or adjMatrxi be clear with input format 
4)  
  */
