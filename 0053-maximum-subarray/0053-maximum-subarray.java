class Solution {
    public int maxSubArray(int[] nums) {
       int maxSum = Integer.MIN_VALUE;
       int maxSumSoFar = 0;
       for(int num : nums){
            maxSumSoFar += num;
           maxSum = Math.max(maxSum,maxSumSoFar);
           if(maxSumSoFar < 0){
            maxSumSoFar = 0;
           }  
       }
        return maxSum;  
    }
}