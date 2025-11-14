class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
       int matrix[][] = new int[n][n];
       int r1 = queries.length;
       int c1 = queries[0].length;
       for(int i = 0 ; i < r1; i++) {
                 int subQ[] = queries[i];
                 for(int sr = subQ[0]; sr <= subQ[2] ; sr++) {
                         for(int sc = subQ[1] ; sc <= subQ[3] ; sc++) {
                              matrix[sr][sc] +=1;
                        }
                 }  
       }
     return matrix;
    }
}