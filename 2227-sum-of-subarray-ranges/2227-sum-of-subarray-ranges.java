class Solution {
    public long subArrayRanges(int[] nums) {
     int n = nums.length;
     long ans = 0;
    for(int  i = 0 ; i < n ;i++) {
          int smallest = Integer.MAX_VALUE;
          int largest = Integer.MIN_VALUE;
          for(int j = i; j < n ; j++) {
               smallest = Math.min(smallest,nums[j]); // 1
               largest = Math.max(largest,nums[j]); // 3
              ans += (largest -smallest); 
          }
    }
   return ans; 
    }
}