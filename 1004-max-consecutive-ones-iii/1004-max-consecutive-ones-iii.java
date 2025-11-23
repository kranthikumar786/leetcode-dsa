class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = 0;
        int n = nums.length;
        int start = 0 , end = 0;
        int zeros = 0;
        while(start < n && end < n){
              if(nums[end] == 0) zeros++;
              while(zeros > k){
                if(nums[start] == 0)
                     zeros--;
               start++;   
              }
           ans = Math.max(ans,end-start+1);   
           end++;
        }
       return ans; 
    }
}
/**
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
 */