class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }
        return maxPrefixSum - minPrefixSum;
     /*
      currentSum = 0 ;
   for(int i =  0; i < n ;i++) {
      currrentSum += nums[i] ;    // 1 -3 = -2  : -3 +2 = -1 + 3 : 2 -4 : -2     
       if(abs(currrentSum) > ans) //
            ans = currestSum ;  // 1  2
    }
retur ans;

  TC : O (N*N)
  SC : O(1) : 
  Verdict  :TLE can be xecpected 
 [0, 0,0,0,-2,0,-3]
   5 : 
 [0,0]  

 0 


 [-1,-2,-3] : 
 6 :



     kadane algo ...? 
      
      max  : postive  sum in the given array  : 
       
         

     */   
    }
};