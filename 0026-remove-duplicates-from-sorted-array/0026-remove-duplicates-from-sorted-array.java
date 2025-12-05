class Solution {
    public int removeDuplicates(int[] nums) {
     int k = 0 ;
     for(int i = 1 ; i < nums.length;i++){
        if(nums[i] != nums[k]) {
            nums[++k] = nums[i];
        }
     }
     return k+1;   
    }
}
/**
 [1,1,2] : 
      i
 k = 0 , 
 k = 1 : 

 */