class Solution {
    public int search(int[] nums, int target) {
     int leftPtr = 0 , rightPtr = nums.length-1;
      while(leftPtr <= rightPtr ){
           int mid = leftPtr + ((rightPtr -leftPtr)>>1);
           if(nums[mid] == target){
              return mid;
           } else if(nums[leftPtr] <= nums[mid]){
                if(nums[leftPtr] <= target && nums[mid] > target){
                      rightPtr = mid-1;
                }else{
                    leftPtr = mid+1;
                }
           } else if(nums[mid] < nums[rightPtr]){
                 if(nums[mid] < target && target <= nums[rightPtr]){
                      leftPtr = mid+1 ; // move to rightside
                 }else{
                    rightPtr = mid-1;
                 }
           }
      }
    return -1;    
    }
}