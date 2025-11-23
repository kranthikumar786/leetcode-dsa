class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = 0;
        int n = nums.length;
        for(int i = 0 ; i < n ;i++){
               int maxO = 0, k1 =k;
               for(int j = i ; j < n ;j++) {
                   if(nums[j]==1){
                      maxO++;
                   }else if(k1>0){
                     maxO++;
                     k1--;
                   }else{
                    break;
                   }
               }
            ans = Math.max(ans,maxO);   
        }
       return ans; 
    }
}