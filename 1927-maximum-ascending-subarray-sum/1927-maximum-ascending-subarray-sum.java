class Solution {
    public int maxAscendingSum(int[] nums) {
       int n = nums.length,ans = 0,val = nums[0];
        for(int i = 1 ; i < n ;i++){
           if(nums[i-1] < nums[i]){
              val += nums[i];
           } else{
           ans = Math.max(ans,val);
            val = nums[i];
           }
       }
       ans = Math.max(ans,val);
     return ans;
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