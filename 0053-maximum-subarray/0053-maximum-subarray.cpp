class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  
      int curMax = 0, globalMax = INT_MIN;
       int n = nums.size(); 
      for(int i = 0 ; i < n ; i++) {
            curMax += nums[i];
            
          if(curMax > globalMax) {
                 globalMax = curMax;
             }
         if(curMax < 0) {
               curMax = 0;
           }  

      }  
       return globalMax; 
    }
};