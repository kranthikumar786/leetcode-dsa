class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Step 2: Add all initial leaves (nodes with degree 1) to queue
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Step 3: BFS trimming leaves level by level
        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear();  // this layer could be potential MHT roots

            for (int i = 0; i < size; ++i) {
                int node = q.front(); q.pop();
                result.push_back(node);

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};




// class Solution {
// public:
// //    int dfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
// //     visited[src] = true;
// //     int count = 1;  // Count this node

// //     for (int node : adj[src]) {
// //         if (!visited[node]) {
// //             count += dfs(node, adj, visited);
// //         }
// //     }

// //     return count;
// // }

// //  int dfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
// //         visited[src] = true;
// //         int maxDepth = 0;
// //         for (int neighbor : adj[src]) {
// //             if (!visited[neighbor]) {
// //                 maxDepth = max(maxDepth, dfs(neighbor, adj, visited));
// //             }
// //         }

// //         return 1 + maxDepth; // include current node height
// //     }

//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//        vector<bool>visited(n,0);
//        vector<vector<int>>adj(n);
//        vector<int>ans;
//        vector<int>outDegree(n,0);
//          for(auto edge : edges){
//              adj[edge[0]].push_back(edge[1]);
//              adj[edge[1]].push_back(edge[0]);
//              outDegree[edge[1]]++;
//              outDegree[edge[0]]++;
//          }
//         queue<int>Q;
//         for(int i = 0 ; i < n ;i++) {
//                if(outDegree[i] == 1){
//                   Q.push(i);
//                }
//         } 
 
//    while(!Q.empty()){
//         int node = Q.front();Q.pop();
//            if(visited[node])
//                break;
//              //  outDegree[node]--;
//            visited[node] = 1;
//           for(int node  : adj[node]) {
//                outDegree[node] = outDegree[node] - 2;
//                visited[node] = 1;
//                if(outDegree[node] <= 0 ){
//                 Q.push(node);
//                }
//           }
//    }

// //    while(!Q.empty()){
// //      ans.push_back(Q.front());
// //      Q.pop();
// //    }

//   for(int i = 0 ; i< n ;i++) {
//         if(outDegree[i] == 2){
//              cout<<outDegree[i]<<" ";
//              ans.push_back(i);
//         }
//   }
//    return ans;
//     //   vector<int>arr(n,0);
//     //   vector<vector<int>>adj(n);
//     //   vector<int>outDegree(n,0);
//     //      for(auto edge : edges){
//     //          adj[edge[0]].push_back(edge[1]);
//     //          adj[edge[1]].push_back(edge[0]);
//     //          outDegree[edge[1]]++;
//     //          outDegree[edge[0]]++;
//     //      }






//     //      int minCnt = INT_MAX;
//     //  //    vector<bool>visited(n,0);
//     //     for(int i = 0 ; i < n ;i++) {
//     //            vector<bool>visited(n,0);
//     //            int cnt = dfs(i,adj,visited);
//     //            arr[i] = cnt;
//     //            cout<<cnt<<" ";
//     //            minCnt = min(minCnt,cnt);
//     //     }
//     //     vector<int>ans;
//     //    for(int i = 0 ;i < n ;i++) {
//     //          if(arr[i] == minCnt){
//     //              ans.push_back(i);
//     //          }
//     //    }

//   //return ans;
//     }
// };