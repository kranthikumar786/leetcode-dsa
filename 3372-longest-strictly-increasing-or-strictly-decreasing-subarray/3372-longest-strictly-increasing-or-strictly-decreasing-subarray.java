class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        if(n == 1) {return 1;}

        int ans = -1;
        for(int i = 0 ; i < n ;i++){
              int incre = 1,decres = 1;
              boolean in = false, de = false; 
             for(int j = i ; j < n -1; j++) {
                  if(nums[j] < nums[j+1] && !de) {
                       in = true;
                       incre++;

                  } else if(nums[j] > nums[j+1] && !in) {
                       de = false;
                       decres++;
                   }
                else if(nums[j] == nums[j+1]){
                      break;
                } else {
                    break;
                }   

             }
           ans = Math.max(incre,Math.max(decres,ans));  
        }
      return ans;     
    }
}
/**

[1,2,3,4]
 */