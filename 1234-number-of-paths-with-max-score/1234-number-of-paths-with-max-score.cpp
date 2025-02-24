 class Solution {
 public:
const int MOD = 1e9 + 7;
vector<int> pathsWithMaxScore(vector<string>& board) {
    int rows = board.size(), cols = board[0].size();

    vector<vector<int>> dpScore(rows, vector<int>(cols, -1));
    vector<vector<int>> dpWays(rows, vector<int>(cols, 0));

    dpScore[rows - 1][cols - 1] = 0;  
    dpWays[rows - 1][cols - 1] = 1;   

    for (int row = rows - 1; row >= 0; row--) {
        for (int col = cols - 1; col >= 0; col--) {
            if (dpWays[row][col] == 0 || board[row][col] == 'X') continue;

            int currentScore = dpScore[row][col];

            vector<pair<int, int>> moves = {{row - 1, col}, {row, col - 1}, {row - 1, col - 1}};

            for (auto [newRow, newCol] : moves) {
                if (newRow < 0 || newCol < 0 || board[newRow][newCol] == 'X') continue;

                int cellValue = (board[newRow][newCol] == 'E' || board[newRow][newCol] == 'S') ? 0 : board[newRow][newCol] - '0';
                int newScore = currentScore + cellValue;

                if (newScore > dpScore[newRow][newCol]) {
                    dpScore[newRow][newCol] = newScore;
                    dpWays[newRow][newCol] = dpWays[row][col];
                } else if (newScore == dpScore[newRow][newCol]) {
                    dpWays[newRow][newCol] = (dpWays[newRow][newCol] + dpWays[row][col]) % MOD;
                }
            }
        }
    }

    if (dpWays[0][0] == 0) return {0, 0};  // No valid paths
    return {dpScore[0][0], dpWays[0][0]};
}
};





// //    bool inRange(int row, int column, int rows, int columns) {
// //        return (row >= 0 && column >= 0 && row < rows && column < columns);
// //      }

         
// // ["E 1 2",
// //  "1 X 1",
// //  "2 1 S"]


// //    }  
    


// vector<int> pathsWithMaxScore(vector<string>& board) {
//     int rows = board.size();
//     int columns = board[0].size();
//     vector<int> ans;
//     vector<vector<int>> DP(rows + 1, vector<int>(columns + 1, 0));
//     for (int row = rows - 1; row >= 0; row--) {
//         for (int column = columns - 1; column >= 0; column--) {
//             if (board[row][column] != 'X' && board[row][column] != 'S') {
//                 int left = (column > 0) ? DP[row][column - 1] : 0;
//                 int up = (row > 0) ? DP[row - 1][column] : 0;
//                 int diagonal = (row > 0 && column > 0) ? DP[row - 1][column - 1] : 0;

//                 DP[row][column] = (board[row][column] - '0') + max({left, up, diagonal});
//             }
//         }
//     }

//     int occurrence = 0, maxAns = 0;
//     if (DP[1][0] == DP[1][1] && DP[1][1] == DP[0][1]) {
//         occurrence = 1;
//         maxAns = DP[1][1];
//     } else if (DP[1][0] == DP[1][1] || DP[1][1] == DP[0][1]) {
//         maxAns = DP[1][1];
//         occurrence = 2;
//     } else {
//         maxAns = max({DP[1][1], DP[0][1], DP[1][0]});
//         occurrence = 1;
//     }

//     ans.push_back(maxAns);
//     ans.push_back(occurrence);

//     return ans;
// }};
           
//         /*
//             if(x == 0 && y == 0) {
//                 return 0;}
 
//            if(DP[x][y] != 0)
//             return DP[x][y];
//          "E 2 3",
//          "2 2 2",
//          "1 2 S"

//            DFS  :withdirections: 
//              sum = board[x][y] == 'S' ? 0 : board[x][y]-'0'; 
//             for(int i = 0 ;i < 4; i++){ 
//              direction[3][2] = {{-1,0},{0,-1},{-1,-1}};
//              if(inRange(nx,ny) && board[x][y] != x) {
//                 //sum +=  board[nex][ny]-'0';
//                 sum + = (board[nex][ny]-'0')+dfs(nx,ny);
//              }
//              // if (maxSum == sum) 
//                                 fre++;
//                            if(maxSum < sum) {
//                               maxSum = sum ;
//                               fre = 1 ;

//                            }       
//            DP[x][y] = sum ;
//            retrun DP[x][y];
              
//            }
         

//  [   "E 1 2 ",      
//      "1 X 1",
//      "2" 1 S"]


// [  16      "1+15      9+6  3+1 ", 0     
//   2+7    "1+6   5+1  1", 0
//   3+3 "2+1 1+0 0"] 0 
//   0  0  0   0 
//         dp[x][y] = board[x][y] - '0' + max({-1,0} , {0,-1} , {-1,-1}) ;

// 16 - 1: 


//  [  E  2 4 3 ",
//     5 "7 X 1",
//     4 "3" "1" S"]



//       2->2->E: 2 to 2 here digaonal : 
        
//         2+1+2 = 5 : 
//         2+3+2 = 7 : 1 : 

//        unorder_map<int,int>sumwithfrequnecy;
//                    5 - 1 : 
//                    7 - 1:
//         */
  