class Solution {
    public int singleNonDuplicate(int[] nums) {
     int l = 0 , r = nums.length-2;
       while(l <= r){
          int m = l + ((r-l)>>1);
         if(nums[m] == nums[m^1]){
             l = m+1;
         } else{
            r = m-1;
         }
       }
      return nums[l];  
    }
}