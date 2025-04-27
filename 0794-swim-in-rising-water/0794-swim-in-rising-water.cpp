class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;

        int delRow[] = {-1, 0, 0, 1};
        int delCol[] = {0, 1, -1, 0};
        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == n-1) return time;

            for(int i=0; i<4; i++) {
                int nx = x + delRow[i];
                int ny = y + delCol[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny] != -1) {
                    pq.push({max(time, grid[nx][ny]), {nx, ny}});
                    grid[nx][ny] = -1;
                }
            }
        }

        return -1;
    }
};

// class Solution {
// public:
//     bool isRange(int row, int column, int totalRows, int totalColumns) {
//         return (row >= 0 && row < totalRows && column >= 0 && column < totalColumns);
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         int totalRows = grid.size();
//         int totalColumns = grid[0].size();
//         vector<vector<int>> visited(totalRows, vector<int>(totalColumns, 0));
//         int arr[4][2] = {{1,0}, {0,-1}, {0,1}, {-1,0}};
//         int ans = grid[0][0];
        
//         queue<pair<int,int>> Q;
//         Q.push({0,0});
//         visited[0][0] = 1;

//         while(!Q.empty()) {
//             pair<int,int> node = Q.front(); Q.pop();
//             int i = node.first;
//             int j = node.second;

//             int minValue = INT_MAX;
//             int newi = -1, newj = -1;

//             for(int k = 0; k < 4; k++) {
//                 int newii = arr[k][0] + i;
//                 int newjj = arr[k][1] + j;
//                 bool inrange = isRange(newii, newjj, totalRows, totalColumns);
                
//                 if (inrange && !visited[newii][newjj] && minValue > grid[newii][newjj]) {
//                     minValue = grid[newii][newjj];
//                     newi = newii;
//                     newj = newjj;
//                 }
//             }

//             if (newi == totalRows - 1 && newj == totalColumns - 1) {
//                 ans = max(ans, grid[newi][newj]);
//                 return ans;
//             }

//             if (newi == -1 && newj == -1) {
//                 return ans;
//             }

//             ans = max(ans, minValue);
//             visited[newi][newj] = 1;
//             Q.push({newi, newj});
//         }

//         return ans;
//     }
// };




// // class Solution {
// // public:
// //   bool isRange(int row, int column, int totalRows, int totalColumns) {
// //          return (row >= 0 && row < totalRows && column >= 0 && column <totalColumns );
// //   }
// //     int swimInWater(vector<vector<int>>& grid) {
// //   /*
// //     visted array must: 
// //     use priority_quu to get min : 
// //      meanwhile get max elemtnin the swimmng path : 
// //   */
// //    int totalRows = grid.size();
// //    int totalColumns = grid[0].size();
// //  //  int visited[totalRows][totalColumns] ;
// //    vector<vector<int>> visited(totalRows, vector<int>(totalColumns, 0));
// //   // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
// //    //int arr[3][3] = {{1,0},{0,-1},{0,1},{1,0}};
// //    int arr[4][2] = {{1,0}, {0,-1}, {0,1}, {-1,0}};
// //   int ans = grid[0][0];
// //   visited[0][0] = 1;
// //    queue<pair<int,int>>Q;
// //    Q.push({0,0});
// //              while(!Q.empty()){
// //                  pair<int,int>node = Q.front(); Q.pop();
// //                  int i = node.first;
// //                  int j = node.second;
// //                  int minValue = INT_MAX;
// //                  int newi = -1, newj = -1;
// //                  cout<<i<<" "<<j<<"\n";
// //                          for(int k = 0 ; k < 4; k++) {
// //                                 int newii = arr[k][0] + i;
// //                                 int newjj = arr[k][1] + j;
// //                                 bool inrange  = isRange(newii,newjj,totalRows,totalColumns);
// //                                 if(inrange && minValue > grid[newii][newjj] && !visited[newii][newjj]){
// //                                     minValue = grid[newii][newjj];
// //                                     newi = newii;
// //                                     newj = newjj;
// //                                   //  visited[newii][newjj] = 1;
// //                                 } 
// //                         }
// //                         if(newi == totalRows -1 && newj == totalColumns-1){
// //                             return ans;
// //                         }
// //                     if(newi == -1 && newj == -1){
// //                          return ans;
// //                     }    
// //                 Q.push({newi,newj});
// //                 visited[newi][newj] = 1;
// //             }
// //            return ans;   // no obstactle so no matter what we will always reach the destination so directly retunr ans
// //         }
// // };

// // /* how to treat like [0][0] or onyl single elemnts is prenset ..?


// //  if(newi!= -1 && newj != -1 ) {
// //                         visited[newi][newj] = 1;
// //                         ans = max(ans,minValue);
// //                     }
                   
// //  */