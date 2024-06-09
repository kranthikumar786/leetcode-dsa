class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int n = nums.size();
    
        /*int sum = 0 , cnt = 0;
        for(int i = 0 ; i < n ;i++) {
                sum = 0 ;
             for(int j = i ; j < n ;j++) {
                    sum += nums[j];
                   if(sum == 0 || sum%k == 0) {
                         cnt++;
                   } 
             } 
        }
        return cnt; 
        */
      int noOfSubArraysDivByK = 0 , prefixSum = 0;
        vector<int>Count(k);
        Count[0] = 1;
       for(int a : nums) {
           prefixSum = (prefixSum + a%k + k) %k;
           noOfSubArraysDivByK += Count[prefixSum]++;
       } 
       return noOfSubArraysDivByK;
    }
};
/*
nums = [4,5,0,-2,-3,1], k = 5
    
    
      4 + 5 + 0  -2 -3 +1 = 5 
    
        5 
          
      5 + 0 = 
      5 + 0 + -2 -3 = 0 %K 
*/



/*

  i have to take sum 
  
    sum == 0 || sum == K || sum %K == 0
    
    4 +5 
    
     4 = 1 
     9 = 
     


*/