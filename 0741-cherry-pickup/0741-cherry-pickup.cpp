class Solution {
public:
//     bool inRange(int row, int column, int rows, int columns) {
//           return( row >= 0 && column >= 0 && row < rows && column < columns);
//     }
//    int DFS(int row, int column, int rows, int columns ,vector<vector<int>>& grid) {
        
//       if(row == rows-1 && column == columns-1) {
//            return 1;
//       }
//         if(!inRange(row, column,rows,columns)) {
//             return 0;
//         }
//         if(row == 0 && column  == 0) { 
//         }
//        if(grid[row][column] == -1){
//           return 0;
//        }
//         int first  = grid[row][column] + max(DFS(row,column+1,rows,columns,grid),DFS(row+1,column,rows,columns,grid)); 
//         int second =  grid[row][column] + max(DFS(row,column-1,rows,columns,grid),DFS(row-1,column,rows,columns,grid));
//         return  max(first, second);  
//    }
    int rows, columns;
    vector<vector<vector<int>>> memo;
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;  // relationship between the two traversals
        if (r1 >= rows || c1 >= columns || r2 >= rows || c2 >= columns ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1;

        if (r1 == rows - 1 && c1 == columns - 1) return grid[r1][c1];

        if (memo[r1][c1][r2] != INT_MIN) return memo[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2) cherries += grid[r2][c2];  // Avoid double counting

        int maxCherries = max({
            dfs(grid, r1 + 1, c1, r2 + 1),  // both move down
            dfs(grid, r1 + 1, c1, r2),      // person1 down, person2 right
            dfs(grid, r1, c1 + 1, r2 + 1),  // person1 right, person2 down
            dfs(grid, r1, c1 + 1, r2)       // both move right
        });

        memo[r1][c1][r2] = (maxCherries < 0) ? -1 : cherries + maxCherries;
        return memo[r1][c1][r2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        memo.assign(rows, vector<vector<int>>(columns, vector<int>(rows, INT_MIN)));

        int result = dfs(grid, 0, 0, 0);
        return max(result, 0);

   
   
    // return(grid[0][0]+DFS(0,1,rows,columns,grid)+ DFS(1,0,rows,columns,grid));
     

   /*
     DP : visited or not : if not visted and pick up the value : 

 [[0,1,-1],
  [1,1,-1],
  [1,1,1]]

  [[0,1,1],
   [1,0,-1],
   [1,1,1]]
  
  [[0,0,1,1],
   [1,0,-1,1],
   [1,1,1,1]]
 

  [[0,0,1,1],
   [1,0,-1,1],
   [1,1,1,1]]
   
    Backtrakcing :  visited and make undo  and allow to use for next time  to get max answer: 
      
   if(row == 0 && colummn == 0) {
       DP[0][0] = max(upside,leftSide); 
      return DP[]
   }   
       first = max() : 
       second = max() : 
                  boundayCondtion : and != -1 
                = max(x,y+1)
     A[0][0]  =  max(right, down) +  max(upside, leftside) : 
    one more contains her is 
     4^n  or 2^n ..? 

   either down  or right path can provie 

  if()
   order is matter 
    in recran ceraltion : 
       (x,y) =  right  down : 
          left and up :     
     0+1+1+1+1 = 4 : 
      
   */
    }
};