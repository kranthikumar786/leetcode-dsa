class Solution {
    public int Hist(int[] prefixSum) {
        int n = prefixSum.length;
        int ans = 0;
        Stack<Integer>st = new Stack<>();
       for(int i = 0 ; i <= n ; i++) {
          int curH = i == n ? 0 : prefixSum[i];
            while(!st.isEmpty() && prefixSum[st.peek()] > curH ){
                  int Height =  prefixSum[st.pop()];
                  int width = st.isEmpty() ? i : i-st.peek()-1;
                 ans = Math.max(ans,Height*width); 
            }
          st.push(i);  
       }
      return ans; 
    }
    public int maximalRectangle(char[][] matrix) {
      int n = matrix.length;
      int m = matrix[0].length;
      int[] prefixSum = new int[m];
      int ans = 0;
      for(int i = 0; i < n ;i++) {
          for(int j = 0 ; j < m ; j++)  {
             if(matrix[i][j] == '1') {
                prefixSum[j] += 1;
             }else{
                prefixSum[j] = 0;
             }
          }
         ans = Math.max(ans,Hist(prefixSum)); 
      }
      return ans;
    }
}