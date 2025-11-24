class Solution {
    public boolean search(int[] nums, int target) {
      int l = 0 , r = nums.length-1;
       while(l <= r){
          int m = (l + ((r-l)>>1));
          if(nums[m] == target){
            return true;
          }
          if(nums[l] == nums[m] && nums[m] == nums[r]){
            l++;
            r--;
            continue;
          }
          if(nums[l] <= nums[m]){ // left half sorted with duplicates
                if(target >= nums[l] && target < nums[m]){
                    r = m-1;
                } else{
                    l = m+1;
                }
          } else if(nums[m] <= nums[r]){ // right half sorted with duplicates
               if(target > nums[m] && target <= nums[r]){
                    l = m+1;
               }else{
                 r = m-1;
               }
          }
       }
      return false;
    }
}
// 1 0 1 1 1 :  t = 0 : 
// 0 1 2 3 4 : 
