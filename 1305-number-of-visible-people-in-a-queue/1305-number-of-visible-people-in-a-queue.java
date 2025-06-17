class Solution {
    public int[] canSeePersonsCount(int[] heights) {
      int n = heights.length;
      int[] ans = new int[n];
      Stack<Integer> st = new Stack<>();
     for(int i = n-1 ; i >=0  ;i--) {
       int  cnt = 0;
        while(!st.isEmpty() && st.peek() < heights[i]) {
                st.pop();
                cnt++;
        }
        if(!st.empty()){
            cnt++;
        }
        ans[i] = cnt;
        st.push(heights[i]);
     } 
     return ans;
    }
}
/**

 int cnt = 0;
        int maxValue = 0 ;
        for(int j = i+1 ; j < n ; j++) {
             if(heights[j] > maxValue) {
                  cnt++;
                  maxValue = heights[j];
             }
              if(heights[j] >= heights[i]){
                   break;
              } 
        }
 */