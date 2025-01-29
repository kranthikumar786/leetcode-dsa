class Solution {
public:
   bool inRange(int row, int column, int rows, int columns){
       return (row >= 0 && row < rows && column >= 0 && column < columns);
   }
  int dfs(int row, int column,int rows,int columns,vector<vector<int>>& grid,vector<vector<int>>&DP){
       if(!inRange(row,column,rows,columns)){
          return INT_MAX;
       }
      if(row == rows -1 && column == columns-1) {
          return grid[row][column];
      }
      if(DP[row][column] != -1) {
          return DP[row][column];
      }
      int downSide = dfs(row+1,column,rows,columns,grid,DP);
      int rightSide = dfs(row,column+1,rows,columns,grid,DP);
    return DP[row][column] = min(downSide,rightSide)+grid[row][column];
  }
    int minPathSum(vector<vector<int>>& grid) {   
     int rows = grid.size();
     int columns = grid[0].size();
     vector<vector<int>>DP(rows+1,vector<int>(columns+1,-1)); 
    return dfs(0,0,rows,columns,grid,DP); 
    }
};