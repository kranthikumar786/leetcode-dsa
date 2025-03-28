class Solution {
public:
bool inRange(int newRow , int newColumn , int totalRows , int totalColumns) {
       return (newRow >=0 && newRow < totalRows && newColumn >= 0 && newColumn < totalColumns );
   }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int totalRows = grid.size(), totalColumns = grid[0].size();
        int queriesSize = queries.size();
        vector<int> ans(queriesSize, 0);
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queriesSize; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end()); 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        int d[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        vector<vector<bool>> visited(totalRows, vector<bool>(totalColumns, false));
        visited[0][0] = true;

        int points = 0;
        for (auto& query : sortedQueries) {
            int queryValue = query.first, queryIndex = query.second;

            while (!pq.empty() && pq.top().first < queryValue) {
                auto [cellValue, position] = pq.top();
                pq.pop();
                int currentRow = position.first, currentColumn = position.second;

                points++;

                for (int i = 0; i < 4; i++) {
                    int newRow = currentRow + d[i][0];
                    int newCol = currentColumn + d[i][1];
                    if (inRange(newRow ,newCol,totalRows,totalColumns) &&
                        !visited[newRow][newCol]) {
                        pq.push({grid[newRow][newCol], {newRow, newCol}});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            ans[queryIndex] = points;
        }
        return ans;
    }
};


// class Solution {
// public:
//   bool inRange(int newRow , int newColumn , int totalRows , int totalColumns) {
//       return (newRow >=0 && newRow < totalRows && newColumn >= 0 && newColumn < totalColumns );
//   }
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//            int  queriesSize  =  queries.size();
//            vector<int>ans(queriesSize,0);
//            int totalRows = grid.size();
//            int totalColumns = grid[0].size();
//            queue<pair<int,int>>Q;
//     for(int query = 0 ; query < queriesSize ; query++) {
//                 int points =  0;
//                  if(grid[0][0] > queries[query]){
//                     ans[query] = 0;
//                     continue;
//                  }
//               vector<vector<int>> visited(totalRows, vector<int>(totalColumns, 0));
//                 Q.push({0,0});
//               while(!Q.empty()) {
//                  pair<int,int>current = Q.front();
//                    int currentRow = current.first;
//                    int currentColumn = current.second;
//                    visited[currentRow][currentColumn] = 1; 
//                    Q.pop();
//                  points++;
//                    int d[4][4] = {{-1,0},{0,1},{0,-1},{1,0}};
//                for(int i = 0 ; i < 4 ; i ++) {
//                      int newRow = currentRow + d[i][0];
//                      int newColumn = currentColumn + d[i][1];
//                     if(inRange(newRow,newColumn,totalRows,totalColumns) &&  grid[newRow][newColumn] < queries[query] &&  !visited[newRow][newColumn]) {
//                         Q.push({newRow,newColumn});
//                         visited[newRow][newColumn] = 1;
//                     }   
//                }             
//               }
//             ans[query] = points; 
//      }
//      return ans; 
//     }
// };


/*
for(int currentRow = 0 ; currentRow < totalRows ; currentRow++ ) {
            for(int currentColumn = 0 ; currentColumn < totalColumns; currentColumn++ ) {
                              

            }
       }
*/