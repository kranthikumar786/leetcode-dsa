class Solution {
    public int longestSubarray(int[] nums) {
     int maxLen = 0;
     int n = nums.length;
      int oneCnt = 0;
      int zeroCnt = 0;
      boolean  f = false;
     for(int i = 0 ; i < n ;i++) {
           zeroCnt = 0;
           oneCnt = 0;
           
           for(int j = i ; j < n ; j++) {
               if(nums[j] == 1){
                 oneCnt +=1 ;
               } else{
                zeroCnt +=1;
                 f = true;
                 if(zeroCnt > 1){
                     break;
                 }
               }
           }
           maxLen = Math.max(maxLen,oneCnt);
     }
    maxLen = Math.max(maxLen,oneCnt);
     return  f == false ? maxLen-1 : maxLen;
     /**
   

     TLE can be expected : 

     Naive Approach: 
      Two Loops: 
   for(int i = 0 ; i < n ;i++) {
      int oneCnt = 0;
      int zeroCnt = 0;
       for(int j = i ; j < n ;j++)  {
           
            if(nums[j] == 1) {
                  oneCnt+=1;
            } else{
                zeroCnt +=1;
                 if(zeroCnt > 1){
                     break;
                 } 
            }
       }
       MAXUpdate;
   }
   return maxUpdate;
      */
    }
}