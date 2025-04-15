class Solution {
public:
   vector<int>parent;
   vector<int>sizeOfNode;
   int findParent(int node) {
         while(node != parent[node]) {
              parent[node] = parent[parent[node]];
               node= parent[node];
         }
        return node; 
   }
    void unionBySize(int src, int dest) {
           int srcParent = findParent(src);
           int destParent = findParent(dest);
            if(srcParent != destParent) {
                if(sizeOfNode[srcParent] < sizeOfNode[destParent]) {
                     swap(srcParent,destParent);
                }
              parent[srcParent] = destParent;
                sizeOfNode[destParent] += sizeOfNode[srcParent]+1;
            } 
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
           int totalRows = isConnected.size();
           int totalColumns =  isConnected[0].size();;
             parent.resize(totalRows+1);
             sizeOfNode.resize(totalRows+1,1);
             for(int i  = 0; i < totalRows ; i++ ) {
                 parent[i] = i; 
             }
            for(int row = 0; row < totalRows ; row++) {
                  for(int column = 0; column < totalColumns ; column++) {
                         if(isConnected[row][column]) {
                            unionBySize(row,column); 
                         }
                  }
            }
          int ans = 0 ;
          for(int i = 0 ;i < totalRows ;i++) {
                 if(parent[i] == i) {
                     ans++;
                 }
          }
  return ans;
    }
};