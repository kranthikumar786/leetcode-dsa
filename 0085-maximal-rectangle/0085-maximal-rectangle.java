class Solution {
    int LargestHist(int[] prefixSum) {
     int maxAns = 0 ;
     int n = prefixSum.length;
     Stack<Integer> st = new Stack<>();
     for(int i = 0 ; i <= n ;i++) {
         int curHeight = i == n ? 0 : prefixSum[i];
          while(!st.isEmpty() && prefixSum[st.peek()] > curHeight) {
                int height = prefixSum[st.pop()];
                int width = st.isEmpty() ? i : i - st.peek()-1;
              maxAns = Math.max(maxAns,height*width);
          }
          st.push(i); 
     }
     return maxAns;
    }
    public int maximalRectangle(char[][] matrix) {
     int n = matrix.length;
     int m = matrix[0].length;
     int[] prefixSum = new int[m];
     int maxV = 0;
    for(int i = 0 ; i < n ; i++) {
         for(int j = 0 ; j < m ; j++) {
             if(matrix[i][j] == '1'){
                prefixSum[j] += 1;
             }else{
                prefixSum[j] = 0;
             }
         }
        // int getMax = 
        maxV = Math.max(maxV, LargestHist(prefixSum));
    }
    return  maxV;
    }
}