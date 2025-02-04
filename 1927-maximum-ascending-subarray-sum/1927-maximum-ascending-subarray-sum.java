class Solution {
    public int maxAscendingSum(int[] nums) {
       int n = nums.length,maxSubArraySum = nums[0],currentSubArraySum = nums[0];
        for(int i = 1 ; i < n ;i++){
           if(nums[i-1] < nums[i]){
              currentSubArraySum += nums[i];
           } else{
           maxSubArraySum = Math.max(maxSubArraySum,currentSubArraySum);
            currentSubArraySum = nums[i];
           }
       }
       maxSubArraySum = Math.max(maxSubArraySum,currentSubArraySum);
     return maxSubArraySum;
    }
}
/**
  for(int i = 0 ; i <  n ;i++){
             int val = nums[i];
            for(int j = i + 1 ; j < n ;j++) {
                  if(nums[j-1] < nums[j]){
                     val += nums[j] ;
                  } else{
                    break;
                  }
            }
     
 */