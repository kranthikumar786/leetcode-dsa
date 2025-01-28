class Solution {
    public boolean inRange(int x, int y , int rows, int columns) {
          return(x >= 0 && x  < rows &&  y >= 0  && y < columns);
    }
    public int findMaxFish(int[][] grid) {
      int rows = grid.length;
      int columns = grid[0].length;
      int ans = 0 ;
      Queue<int[]> Q = new  LinkedList<>();
      boolean visited[][] = new boolean[rows][columns];
    for(int row = 0 ; row < rows ; row++) {
          for(int column = 0 ; column < columns ; column++) {
             if(grid[row][column] > 0  && !visited[row][column]) {
                 Q.add(new int[]{row,column});
                 visited[row][column] = true;
                   int val = 0;
                 while(Q.size() > 0 ) {
                   int cor[] = Q.poll();
                    int x = cor[0];
                    int y = cor[1];
                    val += grid[x][y];
                    int dir[][] = {{0,1},{0,-1},{1,0},{-1,0}};
                   for(int i = 0 ;i < 4; i++) {
                       int newX = x + dir[i][0];
                       int newY = y + dir[i][1];
                       if(inRange(newX,newY,rows,columns) && grid[newX][newY] > 0 && !visited[newX][newY]) {
                          Q.add(new int[]{newX,newY});
                          visited[newX][newY] = true;
                       }  
                   } 
                 }
                ans = Math.max(ans,val); 

             }
             
          }
    }
  return ans;
    }
}