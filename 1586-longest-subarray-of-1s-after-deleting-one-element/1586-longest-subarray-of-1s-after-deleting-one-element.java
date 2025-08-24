class Solution {
    public int longestSubarray(int[] nums) {

      int zeroCnt = 0;
      int longestWindow = 0;
      int start = 0;
      int n = nums.length;
      for(int i = 0 ; i < n; i++) {
         zeroCnt += (nums[i] == 0 ? 1 : 0);
          while(zeroCnt > 1) {
            zeroCnt -= (nums[start] ==0 ? 1: 0);
            start++;
          }
        longestWindow = Math.max(longestWindow , i - start);   
      }   
     return  longestWindow;
    //  int maxLen = 0;
    //  int n = nums.length;
    //   int oneCnt = 0;
    //   int zeroCnt = 0;
    //   boolean  f = false;
    //  for(int i = 0 ; i < n ;i++) {
    //        zeroCnt = 0;
    //        oneCnt = 0;
    //        for(int j = i ; j < n ; j++) {
    //            if(nums[j] == 1){
    //              oneCnt +=1 ;
    //            } else{
    //             zeroCnt +=1;
    //              f = true;
    //              if(zeroCnt > 1){
    //                  break;
    //              }
    //            }
    //        }
    //        maxLen = Math.max(maxLen,oneCnt);
    //  }
    // maxLen = Math.max(maxLen,oneCnt);
    //  return  f == false ? maxLen-1 : maxLen;
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


      /**
      PrefixSum ..? 
nums = [1,1,0,1]
      1 2 2 3 : 

  [0,1,1,1,0,1,1,0,1]
   0 1 2 3 3 4 5 5 6 

   first 3 
    now single duplicate so 
     take previoussum , go further : 

      3 




      


       */
    }
}