class Solution {
    public int findMin(int[] nums) {
     int ans = Integer.MAX_VALUE;
     int l = 0 , r = nums.length-1;
     while(l <= r){
        int m = l + ((r-l)>>1);
        if(nums[l] <= nums[m]){
            ans = Math.min(ans,nums[l]);
            l= m+1;
        } else{
            ans = Math.min(ans,nums[m]);
            r = m-1; 
        } 
     }
    return ans; 
    }
}