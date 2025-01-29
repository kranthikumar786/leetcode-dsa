class Solution {
public:
   bool inRange(int row, int column, int rows, int columns){
      return (row >= 0 && row < rows && column >= 0 && column < columns);
   }
  int gSum = INT_MAX;
    int dfs(int x, int y , vector<vector<int>>& grid ,int rows, int columns,vector<vector<int>>&DP) {
        if(!inRange(x,y,rows,columns)){
            return INT_MAX;
        }
         if(DP[x][y] != -1){
            return DP[x][y];
         }
        if(x == rows-1&& y == columns-1){
              return grid[x][y];
           }
         int downSide = dfs(x+1,y,grid,rows,columns,DP); 
           int rightSide = dfs(x,y+1,grid,rows,columns,DP);
      return DP[x][y] = min(downSide, rightSide) + grid[x][y]; 
    } 
    int minPathSum(vector<vector<int>>& grid) {
      int rows = grid.size();
      int columns = grid[0].size();
    vector<vector<int>> DP(rows+1, vector<int>(columns+1, -1));
      return dfs(0,0,grid,rows,columns,DP);
    // return gSum;
    }
};