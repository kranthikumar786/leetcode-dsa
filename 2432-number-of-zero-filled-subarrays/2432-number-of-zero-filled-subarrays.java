class Solution {
    public long zeroFilledSubarray(int[] nums) {
        
        int n = nums.length;
        long ans = 0;
        int cnt = 0 ;
        for(int i = 0 ;i < n ; i++) {
          if(nums[i] == 0){
              cnt++;
          }else{
            ans += (long) cnt * (cnt + 1) / 2;
            System.out.println(ans);
            cnt = 0;
          }
        }
      ans += (long) cnt * (cnt + 1) / 2;
      return ans; 
        /**
         0 0 0 
          
          0 
          0 0 
          0 0 0 
            0 
            0 0 

            0 

            n*(n+1)/2 

        
         */
    }
}