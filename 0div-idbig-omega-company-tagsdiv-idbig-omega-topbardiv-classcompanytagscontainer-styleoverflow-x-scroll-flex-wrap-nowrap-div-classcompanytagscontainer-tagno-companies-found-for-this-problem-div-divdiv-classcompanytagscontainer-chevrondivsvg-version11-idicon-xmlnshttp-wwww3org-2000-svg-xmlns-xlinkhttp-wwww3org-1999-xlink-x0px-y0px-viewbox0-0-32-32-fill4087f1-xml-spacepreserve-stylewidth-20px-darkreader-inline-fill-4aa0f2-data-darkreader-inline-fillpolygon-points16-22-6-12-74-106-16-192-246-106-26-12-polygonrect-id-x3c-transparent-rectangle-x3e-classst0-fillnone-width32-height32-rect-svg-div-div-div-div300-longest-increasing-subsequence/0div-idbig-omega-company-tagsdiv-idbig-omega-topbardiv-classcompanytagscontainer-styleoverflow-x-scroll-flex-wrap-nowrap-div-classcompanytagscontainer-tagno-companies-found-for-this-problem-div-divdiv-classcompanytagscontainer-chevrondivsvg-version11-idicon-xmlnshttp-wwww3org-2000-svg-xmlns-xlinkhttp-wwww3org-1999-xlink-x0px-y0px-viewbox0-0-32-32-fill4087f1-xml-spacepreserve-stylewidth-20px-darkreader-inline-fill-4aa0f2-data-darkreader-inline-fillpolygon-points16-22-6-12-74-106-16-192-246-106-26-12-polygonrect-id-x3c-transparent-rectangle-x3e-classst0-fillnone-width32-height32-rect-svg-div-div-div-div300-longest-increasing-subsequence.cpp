class Solution {
public:
   /* 
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
    */
    
    
     int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        int len = 0;
         for(int i = 0 ; i < n ;i++) {     
             if( i ==0 || temp.back() < nums[i]){
                 temp.push_back(nums[i]);
                   len++;
             }
              else {
                   auto index = lower_bound(temp.begin(),temp.end(),nums[i]);
                   /* lower_bound always return iterator either nums[i] value index 
                       or
                    first index where nums[i] > some index
                  */
                    temp[index-temp.begin()] = nums[i];
              }
         }
       return len;         
         /*
           At final temp may [OR] may n't contains longest incerasing subsequence
            but length remains same.
         */
     }
    
};

