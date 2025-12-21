class Solution {
   public int Counting(int nums[],int g){
        int l = 0 , r = 0 , sum = 0, cnt = 0, n = nums.length;
         if(g < 0) return 0;
        while(r < n) {
            sum += nums[r];
            while(sum > g){
                sum -= nums[l]; 
               l++;
            }
           cnt += (r-l+1);  
           r++;
        }
        return cnt; 
    }
    public int numSubarraysWithSum(int[] nums, int goal) {
    return Counting(nums,goal) - Counting(nums,goal-1);
    }
}