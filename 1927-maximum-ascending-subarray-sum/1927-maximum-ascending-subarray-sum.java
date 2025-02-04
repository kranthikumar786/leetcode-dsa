class Solution {
    public int maxAscendingSum(int[] nums) {
      
       int n = nums.length;
       int ans = 0;
       for(int i = 0 ; i <  n ;i++){
             int val = nums[i];
            for(int j = i + 1 ; j < n ;j++) {
                  if(nums[j-1] < nums[j]){
                     val += nums[j] ;
                  } else{
                    break;
                  }
            }
          ans = Math.max(ans,val);  
       }
     return ans;
    }
}