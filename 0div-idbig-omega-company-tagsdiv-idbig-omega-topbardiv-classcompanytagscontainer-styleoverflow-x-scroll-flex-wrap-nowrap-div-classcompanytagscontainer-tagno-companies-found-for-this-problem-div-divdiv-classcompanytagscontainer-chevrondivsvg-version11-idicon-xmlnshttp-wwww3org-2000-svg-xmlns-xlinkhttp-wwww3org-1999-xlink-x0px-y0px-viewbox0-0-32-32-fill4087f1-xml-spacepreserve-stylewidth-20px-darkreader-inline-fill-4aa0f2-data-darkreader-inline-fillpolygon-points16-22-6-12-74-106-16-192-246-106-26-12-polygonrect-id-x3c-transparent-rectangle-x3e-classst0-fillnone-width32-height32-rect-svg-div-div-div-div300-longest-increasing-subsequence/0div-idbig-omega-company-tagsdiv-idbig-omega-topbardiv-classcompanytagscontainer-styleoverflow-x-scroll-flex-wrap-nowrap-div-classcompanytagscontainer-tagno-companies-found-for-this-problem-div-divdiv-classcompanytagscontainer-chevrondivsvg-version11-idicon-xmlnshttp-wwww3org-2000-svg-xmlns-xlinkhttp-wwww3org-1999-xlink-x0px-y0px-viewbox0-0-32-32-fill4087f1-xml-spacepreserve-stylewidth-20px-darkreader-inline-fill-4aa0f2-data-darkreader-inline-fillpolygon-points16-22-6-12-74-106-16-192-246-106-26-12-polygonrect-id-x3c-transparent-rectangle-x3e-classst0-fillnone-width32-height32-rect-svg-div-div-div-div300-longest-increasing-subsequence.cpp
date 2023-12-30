class Solution {
public:
    
    int Rec(int index ,int prev_index , vector<int>&nums, int n, vector<vector<int>>&dp) {
          if(index == n) {
               return 0;
          }
        
         if(dp[index][prev_index+1] != -1) {
               return dp[index][prev_index+1];
         }
          int len =  0 + Rec(index+1 , prev_index ,nums, n,dp);
        
          if(prev_index == -1 || nums[index] > nums[prev_index]) {
              
             len = max(len , 1 + Rec(index +1 , index , nums, n,dp)); 
              
          }
        return dp[index][prev_index+1] = len;
    }
     int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1 , -1));
         return  Rec(0,-1,  nums , n,dp);
    }
};
