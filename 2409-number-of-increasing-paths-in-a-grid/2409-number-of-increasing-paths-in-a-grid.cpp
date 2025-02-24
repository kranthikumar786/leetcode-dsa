class Solution {
public:
  int Mod = 1e9+7;
     int fourDirections[4][2] = {{0,-1},{-1,0}, {0,1}, {1,0}};
     bool inRange(int row, int column, int rows,  int columns) {
          return (row >= 0 && column >= 0 && row < rows && column < columns );
     }
   int DFS(int row, int column, vector<vector<int>>&grid, int rows, int columns,vector<vector<int>>&DP){
        if(DP[row][column] != 0){
            return DP[row][column];
        } 
      // 4 directions  
  // int len = 0;  
     int len = 1;
    for(int i = 0 ; i < 4; i++){
            int newRow = row + fourDirections[i][0];
            int newColumn = column + fourDirections[i][1];       
           bool inBound = inRange(newRow,newColumn,rows, columns) ;
          if(inBound && grid[newRow][newColumn] > grid[row][column]){
                len = (len + DFS(newRow, newColumn, grid, rows, columns, DP)) % Mod;
          }
        // len = max(len , paths);  
     //  len += path;
    }
     return DP[row][column] = len%Mod;
   }
    int countPaths(vector<vector<int>>& grid) {
       int rows = grid.size();
       int columns= grid[0].size();
       int Mod =1e9+7;
       int noOfIncreasingPaths = 0;
       vector<vector<int>> DP(rows + 1, vector<int>(columns + 1));
      for(int row = 0; row < rows ; row++  ) {
          for(int column = 0 ; column < columns ; column++) {
              int paths = DFS(row, column, grid, rows, columns,DP);
             noOfIncreasingPaths = (noOfIncreasingPaths + DFS(row, column, grid, rows, columns, DP)) % Mod;
          }
      }
 return  noOfIncreasingPaths;
       
       /*
       
       any cell 2 any cell : means signle ele  alos ans++;
       [1->3]
       [1->3->4]: 
 
   [1,2,3]
   [7,8,5]

   1->7->8 : 
   1->2->8 : 

     [2,2]
     [2,2] : m*n =  


  tc  :O(4^n) : 
  sc :O(m*n) :  
  [1,2,3] :  [6,5,4] : 
  [6,5,4] :  [1,2,3] :      
       summing alll elemte in this 2DP array will help to get the noOfPaths;
    
tc : (n*m) : 
sc : (n*m) : 

      1,1->2 ,1->2->3 , 1->2-3>4,1->2->3->4->5 ,1->2->3->4->5->6: 
     2, 2->3,2->3->4,2->3->4->5,2->3->4->5->6
     3, 3->4 , 3->4->5,3->4->5->6
 3=  4, 4->5,4->5->6    
    2 = 5, 5->6 : 

    DP : 
     subsprobems : 
     optimal substrcutrs : 
     1


   
    
       */ 

    }
};