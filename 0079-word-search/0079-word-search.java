class Solution {
     boolean visited[][];
    boolean isValid(int cx, int cy, int x, int y){
         return (cx >= 0 && cx < x && cy >=0 && cy < y);
    }
    boolean found(int cx, int cy, int x, int y, char[][]b, String w, int wPtr){
         if(wPtr == w.length()) return true;
         if(!isValid(cx,cy,x,y) || visited[cx][cy] || b[cx][cy] != w.charAt(wPtr)) return false;
           visited[cx][cy] = true;
         boolean leftSide = found(cx,cy-1,x,y,b,w,wPtr+1);
          if(leftSide) return true;
         boolean rightSide = found(cx,cy+1,x,y,b,w,wPtr+1);
          if(rightSide) return true;
         boolean downSide = found(cx+1,cy,x,y,b,w,wPtr+1);
         if(downSide) return true;
        boolean upSide = found(cx-1,cy,x,y,b,w,wPtr+1);  
          if(upSide) return true;
           visited[cx][cy] = false; 
        return false;     
    }
    public boolean exist(char[][] board, String word) {
      int r = board.length;
      int c = board[0].length;
      int wordSearch[] = new int[128];
      int boardSearch[] = new int[128];
       for(char ch : word.toCharArray()){
           wordSearch[ch]++;
       }
       for(char [] row : board){
            for(char ch : row){
                boardSearch[ch]++;
            }
       } 
       for(int i = 0 ; i < 128; i++) {
            if(boardSearch[i] < wordSearch[i])
                return false;
       }
      visited = new boolean [r][c];
      for(int i = 0 ; i < r; i++){
           for(int j = 0 ; j < c ; j++){
                if(board[i][j] == word.charAt(0)){
                   if(found(i,j,r,c, board,word,0)){
                      return true;
                   }    
                } 
           }
      }
      return false; 
    }
}