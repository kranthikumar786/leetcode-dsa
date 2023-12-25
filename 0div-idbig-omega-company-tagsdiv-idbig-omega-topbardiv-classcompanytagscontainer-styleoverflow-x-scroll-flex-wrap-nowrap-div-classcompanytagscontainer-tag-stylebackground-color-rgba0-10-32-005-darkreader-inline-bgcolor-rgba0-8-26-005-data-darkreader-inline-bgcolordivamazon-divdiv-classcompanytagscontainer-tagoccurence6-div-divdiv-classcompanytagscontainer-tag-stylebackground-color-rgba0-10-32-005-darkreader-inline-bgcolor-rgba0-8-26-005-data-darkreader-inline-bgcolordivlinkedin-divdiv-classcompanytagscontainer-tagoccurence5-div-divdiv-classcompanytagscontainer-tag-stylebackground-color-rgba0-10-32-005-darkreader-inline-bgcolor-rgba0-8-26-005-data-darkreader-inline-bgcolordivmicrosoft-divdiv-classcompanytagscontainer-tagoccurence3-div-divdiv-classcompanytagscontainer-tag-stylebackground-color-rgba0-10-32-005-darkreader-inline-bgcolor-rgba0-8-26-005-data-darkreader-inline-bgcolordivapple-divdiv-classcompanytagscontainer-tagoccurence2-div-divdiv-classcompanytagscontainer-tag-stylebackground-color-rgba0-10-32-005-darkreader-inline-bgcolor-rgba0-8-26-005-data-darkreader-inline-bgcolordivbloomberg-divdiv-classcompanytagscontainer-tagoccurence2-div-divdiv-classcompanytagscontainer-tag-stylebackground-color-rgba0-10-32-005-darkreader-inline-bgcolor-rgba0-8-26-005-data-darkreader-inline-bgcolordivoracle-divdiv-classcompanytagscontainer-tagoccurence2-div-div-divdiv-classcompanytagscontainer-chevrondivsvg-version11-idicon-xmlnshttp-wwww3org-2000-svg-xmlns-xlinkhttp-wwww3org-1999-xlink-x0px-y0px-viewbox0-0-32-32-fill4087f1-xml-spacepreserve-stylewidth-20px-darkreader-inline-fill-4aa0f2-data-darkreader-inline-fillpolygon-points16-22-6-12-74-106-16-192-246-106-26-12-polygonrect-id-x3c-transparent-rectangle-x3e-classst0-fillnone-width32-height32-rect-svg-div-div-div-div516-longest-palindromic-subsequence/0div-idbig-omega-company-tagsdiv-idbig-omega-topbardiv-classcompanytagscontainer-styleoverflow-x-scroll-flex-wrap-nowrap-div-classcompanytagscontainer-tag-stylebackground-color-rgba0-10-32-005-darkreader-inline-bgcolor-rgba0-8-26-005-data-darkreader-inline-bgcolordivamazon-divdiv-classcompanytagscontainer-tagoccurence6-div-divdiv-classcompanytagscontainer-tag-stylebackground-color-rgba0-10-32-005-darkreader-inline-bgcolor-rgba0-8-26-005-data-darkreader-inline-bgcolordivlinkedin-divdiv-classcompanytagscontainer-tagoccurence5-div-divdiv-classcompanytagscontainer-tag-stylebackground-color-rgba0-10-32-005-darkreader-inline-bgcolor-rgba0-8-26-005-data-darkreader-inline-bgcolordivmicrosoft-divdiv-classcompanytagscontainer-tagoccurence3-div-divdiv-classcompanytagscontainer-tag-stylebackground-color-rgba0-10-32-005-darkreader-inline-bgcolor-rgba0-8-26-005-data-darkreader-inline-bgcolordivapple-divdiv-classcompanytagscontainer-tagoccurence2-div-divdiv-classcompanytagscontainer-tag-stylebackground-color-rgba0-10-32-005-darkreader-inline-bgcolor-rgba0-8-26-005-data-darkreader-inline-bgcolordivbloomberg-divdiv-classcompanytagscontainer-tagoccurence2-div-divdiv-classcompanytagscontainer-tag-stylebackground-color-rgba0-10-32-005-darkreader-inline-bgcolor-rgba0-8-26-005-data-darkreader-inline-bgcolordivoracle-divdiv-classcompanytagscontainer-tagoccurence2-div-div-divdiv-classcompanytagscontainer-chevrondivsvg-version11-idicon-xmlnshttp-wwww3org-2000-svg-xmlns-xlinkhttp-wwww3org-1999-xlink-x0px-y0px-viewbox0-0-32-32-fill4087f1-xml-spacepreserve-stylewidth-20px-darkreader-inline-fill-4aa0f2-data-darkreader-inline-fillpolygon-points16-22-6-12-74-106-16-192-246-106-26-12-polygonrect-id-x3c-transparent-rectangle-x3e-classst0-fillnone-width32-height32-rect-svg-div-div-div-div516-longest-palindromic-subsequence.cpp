class Solution {
public:
    
    int Solve(const string &s , int left , int right , vector<vector<int>>&dp) {
         if( left == right) {
              return 1;
         }
          if(left > right) {
              return 0;
          }
        
         if(dp[left][right] != 0) {return dp[left][right];}
        
         if(s[left] == s[right]) {
              return dp[left][right] =  Solve(s,left +1 , right -1 ,dp ) + 2;
         }
        return   dp[left][right] = max(Solve(s,left + 1 , right ,dp) ,Solve(s, left ,right-1,dp));
    }
    int longestPalindromeSubseq(string s) {  
         int n = s.length();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 ,0));
         for(int i = 0 ; i <= n ;i++) {
             dp[i][i] = 1;
         }

        return Solve(s , 0 , s.length()-1 , dp);        
        
    }
};

/* bbbab
  
  bba
  
  
   bb  =  
  
  ba
  */