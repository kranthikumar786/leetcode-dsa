class Solution {
public:
    bool inRange(int row, int col, int totalRows, int totalCols) {
        return (row >= 0 && row < totalRows && col >= 0 && col < totalCols);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        
        queue<tuple<int, int, int, int>> q; // {row, col, kLeft, steps}
        vector<vector<int>> visited(totalRows, vector<int>(totalCols, -1));
        
        q.push({0, 0, k, 0});
        visited[0][0] = k;
        
        int arr[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        
        while (!q.empty()) {
            auto [i, j, kLeft, steps] = q.front(); q.pop();
            
            // If reached destination
            if (i == totalRows-1 && j == totalCols-1) {
                return steps;
            }
            
            for (int dir = 0; dir < 4; dir++) {
                int newi = i + arr[dir][0];
                int newj = j + arr[dir][1];
                
                if (inRange(newi, newj, totalRows, totalCols)) {
                    int newKLeft = kLeft - grid[newi][newj];
                    
                    if (newKLeft >= 0) {
                        // Only push if we have not visited with better or same kLeft
                        if (visited[newi][newj] == -1 || visited[newi][newj] < newKLeft) {
                            visited[newi][newj] = newKLeft;
                            q.push({newi, newj, newKLeft, steps+1});
                        }
                    }
                }
            }
        }
        
        return -1; // If not reachable
    }
};






















// class Solution {
// public:
//     bool inRange(int row, int column, int totalRows, int totalColumns){
//           return (row >= 0 && row < totalRows && column >= 0 && column < totalColumns);
//     }
//     int shortestPath(vector<vector<int>>& grid, int k) {
//        int ans = 0 ;
//        int totalRows = grid.size();
//        int totalColumns = grid[0].size();
//        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
//         int arr[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//         int time = 0;
//        while(!minHeap.empty()) {  
//          pair<int,pair<int,int>>node = minHeap.top();minHeap.pop();
//               int kValue = node.first;
//               if(kValue < 0){
//                 return -1;
//               }
//               int i = node.second.first;
//               int j = node.second.second;
//               int localKValue = kValue;
//               int takenewi = -1;
//               int takenewj = -1;
//               for(int i = 0 ;i < 4; i++) {
//                  int newi = i + arr[k][0];
//                  int newj = j + arr[k][1];
//                   bool isRange = inRange(newi,newj,totalRows,totalColumns); 
//                 if(grid[newi][newj] == 1) {
//                    takenewi = newi ;
//                    takenewj = newj;
//                   localKValue =  min(localKValue, kValue-1);
//                    grid[newi][newj] == -1;  
//                 }else if(grid[newi][newj] == 0 ){
//                     localKValue = min(localKValue ,kValue);
//                     takenewi = newi;
//                     takenewj = newj;
//                    grid[newi][newj] =-1;
//                 }
//               }

//             minHeap.push({{localKValue},{takenewi,takenewj}});  
//                time++;
//        }  
//      return time;
//     }
// };