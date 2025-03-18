class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
  
      int usedBits = 0;
      int leftPtr = 0;
      int maxLength = 0 ;
      int n = nums.size();
      for(int rightPtr = 0 ; rightPtr < n ; rightPtr++){ 
            while((usedBits & nums[rightPtr]) != 0){
                  usedBits ^= nums[leftPtr];
                 leftPtr++; 
            }
           usedBits |= nums[rightPtr];
            maxLength = max(maxLength,rightPtr-leftPtr+1);
      }
     return  maxLength;
     /*
     
    first for loop for itration : 

     second loop for subsaryy staring : 

       1,3,8,48,10 : 

       1 3 8 48 10 : 
         3 8 48 10:
           8 48 10 :
             48 10 : 
                10 : 
    -------------------------
      now every pair : 

        so one more loop : 
           k = j : 
               

     
     */

    }
};