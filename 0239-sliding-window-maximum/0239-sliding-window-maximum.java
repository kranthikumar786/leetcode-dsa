class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        int n = nums.length;
        int[] ans = new int[n - k + 1];
        ArrayDeque<Integer> dq = new ArrayDeque<>();

        int k1 = 0;

        for (int i = 0; i < n; i++) {

            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()]) {
                dq.pollLast();
            }

            dq.offerLast(i);

            if (!dq.isEmpty() && dq.peekFirst() <= i - k) {
                dq.pollFirst();
            }

            if (i >= k - 1) {
                ans[k1++] = nums[dq.peekFirst()];
            }
        }

        return ans;
    }
}
// class Solution {
//     public int[] maxSlidingWindow(int[] nums, int k) {     
//      int n = nums.length;
//      int ans[] = new int[n-k+1];
//      ArrayDeque<Integer>dq = new ArrayDeque<>();
//      int k1 = 0 ;
//      for(int i = 0 ; i < n ; i++) {
//             while(!dq.isEmpty() && nums[i] >= nums[dq.back()]) {
//                     dq.pop_back(); 
//             }
//              dq.push(i);
//             if(!dq.isEmpty() && dq.front() <= i-k) {
//                 dq.pop_front();
//             }   
//            if(i >= k-1){
//             ans[k1++] = nums[dq.front()];
//            }
//      }
//      return ans; 
//     }
// }