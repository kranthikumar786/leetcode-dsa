class Solution {
public:
    // Directions for moving: left, up, right, down
    int directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    // DFS function to find the longest increasing path starting from (row, col)
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
        // If we have already calculated the result for this cell, return it
        if (dp[row][col] != 0) return dp[row][col];

        int longestPath = 1;  // Each cell by itself is a path of length 1

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0];  // Move vertically
            int newCol = col + directions[i][1];  // Move horizontally

            // Check if the new cell is within the matrix and has a larger value
            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() &&
                matrix[newRow][newCol] > matrix[row][col]) {
                
                // Recursively call dfs for the new cell and update the longest path
                int pathLength = 1 + dfs(matrix, dp, newRow, newCol);
                longestPath = max(longestPath, pathLength);  // Keep track of the longest path
            }
        }

        dp[row][col] = longestPath;  // Save the result (memoization)
        return longestPath;          // Return the longest path from this cell
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Handle empty matrix case
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Create a memoization matrix to store results for each cell
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int maxPath = 0;  // To track the global longest increasing path

        // Start DFS from every cell in the matrix
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                maxPath = max(maxPath, dfs(matrix, dp, row, col));  // Update global max path
            }
        }

        return maxPath;  // Return the final longest increasing path


    //            -1,0
    //  0,-1     [0,0] :  0 ,1 
    //            1 , 0 

    
  /*
  
    dfs : 
   
     in worst at first place if we are abel to get the max answer :
       i don't need to run fo r reimaing  mateix can give max aor not : since i ahve alreay  reache dthe max  : so simply break  the rreceuson usinf retunr : 
   retunr final answer: 
  

 BFS: 
 

    let' explore the negithbout by neoghurs : 
      then get the max: 
       in worst it has to trvesal the enitre all cells: 

     i don't think interms of worst case of longest this will helps : 

  */
    /*
    Path may start from any where not only from (o,o),(m-1,n1):
    
     what iam thinking : is 
      take one cell and explore it;s four directions  
        meanwhile if i found the max then the curent cell  move to ward to that path by explotring the 4 paths : 
         meanshile everyitm i do update max length if it meadn the conditons : 
        
   
      length which means the first occurnacr can be returined: 

   
     we can have 4 more then one time : instaed of updating  <= ..? 
     

  max length can be : 8 : 
     max answer can be this :  m*n -1: 3*3 - 1= 9 : 

     max answer can be  = m*n: 

  No chance to fill the visited matrix: so optimzation seems like not possible : 
   
    filling is thier for every statring cell ,then undo again : the path : 

      chance to enter into loop : 
       if(!visited[i][j]) {

       }
    */ 
    }
};