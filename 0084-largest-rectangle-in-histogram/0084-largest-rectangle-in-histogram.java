class Solution {
    public int largestRectangleArea(int[] heights) {
       int n = heights.length;
       int ans = 0;
       Stack<Integer>st = new Stack<>();
      for(int i = 0 ; i <=  n ; i++) {
           int curHeight = (i == n) ? 0 : heights[i]; 
          while(!st.isEmpty() && heights[st.peek()] > curHeight) {
                 int height = heights[st.pop()];
                 int width = st.isEmpty() ? i : i - st.peek()-1;
             ans = Math.max(ans, height * width);
          }
        st.push(i);
      }
     return ans;
    }
}

/**

for(int i = 0 ; i < n ;i++) {
        int minValue = 100000;
       for(int j = i ; j < n ; j++) {
             minValue = Math.min(minValue, heights[j]);
            ans = Math.max((minValue*(j-i+1)),ans);
       }
      }
 */