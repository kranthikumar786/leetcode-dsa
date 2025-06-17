class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
      int n = nums.length;
      int ans[] = new int[n-k+1];
        int index = 0;
      Deque<Integer>dq = new LinkedList<>();
      for(int i = 0 ; i < n ;i++) {
          while(!dq.isEmpty() && nums[dq.getLast()] <= nums[i]) {
                   dq.removeLast();
          }
          dq.addLast(i);
            if (!dq.isEmpty() && dq.getFirst() <= i - k) {
                dq.removeFirst();
            }
          if(i >= k-1){
            ans[index++] = nums[dq.getFirst()];
          } 
      } 
      return ans;
    }
}