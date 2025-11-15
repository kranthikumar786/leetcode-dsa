class Solution {
    public long subArrayRanges(int[] nums) {
        int n = nums.length;
        long ans = 0;

        Stack<Integer> st = new Stack<>();

        for (int i = 0; i <= n; i++) {
            int cur = (i == n ? Integer.MIN_VALUE : nums[i]);
            while (!st.isEmpty() && nums[st.peek()] > cur) {
                int j = st.pop();
                int k = st.isEmpty() ? -1 : st.peek();
                long left = j - k;
                long right = i - j;
                ans -= (long) nums[j] * left * right;
            }
            st.push(i);
        }

        st.clear();

        for (int i = 0; i <= n; i++) {
            int cur = (i == n ? Integer.MAX_VALUE : nums[i]);
            while (!st.isEmpty() && nums[st.peek()] < cur) {
                int j = st.pop();
                int k = st.isEmpty() ? -1 : st.peek();
                long left = j - k;
                long right = i - j;
                ans += (long) nums[j] * left * right;
            }
            st.push(i);
        }

        return ans;
    }
}




// class Solution {
//     public long subArrayRanges(int[] nums) {
//      int n = nums.length;
//      long ans = 0;
//      Stack<Integer> st = new Stack<>();
//      for(int i = 0 ; i <= n ; i++) {
//             int cur = (i == n ? Integer.MIN_VALUE : nums[i]);
//             while(!st.isEmpty() && nums[st.peek()] > cur) {
//                       int j = st.pop();
//                       int k = st.isEmpty() ? -1 : st.peek();
//                       long left = j-k;
//                       long right = i-j;
//                   ans-=(nums[i] * left * right);    
//             }
//             st.push(i);
//      }
//        st.clear();
//        for(int i  = 0 ; i <= n ;i++) {
//           int cur = (i== n ? Integer.MAX_VALUE : nums[i]);
//           while(!st.isEmpty() && nums[st.peek()] < cur) {
//                    int j = st.pop();
//                    int k = st.isEmpty() ? -1 : st.peek();
//                    long left = j-k ;
//                    long right = i-j;
//                    ans += (long) nums[j]*left*right;
//           }
//           st.push(i);
//        }
      
//    return ans; 
//     }
// }
// /**


// for(int  i = 0 ; i < n ;i++) {
//           int smallest = Integer.MAX_VALUE;
//           int largest = Integer.MIN_VALUE;
//           for(int j = i; j < n ; j++) {
//                smallest = Math.min(smallest,nums[j]); // 1
//                largest = Math.max(largest,nums[j]); // 3
//               ans += (largest -smallest); 
//           }
//     }
//   1 2 3 

//   1: 
//     2: 

//   ans 1: 

//     if cur value > exisng value : 
//      then do 
       

//  */