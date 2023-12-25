class Solution {
public:
    
    /*int Solve(const string &s , int left , int right , vector<vector<int>>&dp) {
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
    */
    int longestPalindromeSubseq(string s) {  
         int n = s.length();
        /*vector<vector<int>>dp(n+1 , vector<int>(n+1 ,0));
        for (int i = n -1  ; i >= 0 ; i--) {
             for(int j = 1 ; j <= n ; j++) {
                
                  if(s[i] == s[j-1]) {
                      dp[i][j] = 1 + dp[i+1][j-1]; 
                  }
                  else{
                      dp[i][j] = max(dp[i+1][j] ,dp[i][j-1]);
                  }
             }
        }
       return dp[0][n];    
       */
       // return Solve(s , 0 , s.length()-1 , dp);        
    
     /* vector<int>curRow(n+1 , 0) , prevRow(n+1, 0);
        
        for (int i = n -1  ; i >= 0 ; i--) {
             for(int j = 1 ; j <= n ; j++) {
                
                  if(s[i] == s[j-1]) {
                      curRow[j] = 1 + prevRow[j-1]; 
                  }
                  else{
                      curRow[j] = max(curRow[j-1] ,prevRow[j]);
                  }
             }
            prevRow = curRow;
        }
       return prevRow[n]; 
       */
        
     
         vector<int>dp(n,0);
         for (int i = n - 1 ; i >= 0 ; i-- ) {
                 dp[i] = 1;
                int Y = 0;
                for (int j = i+1 ; j < n ; j++) {
                    int t = dp[j];
                     if(s[i] == s[j]) {
                         dp[j] = Y + 2;
                     } else {
                          dp[j] = max(dp[j-1] , dp[j]);
                     }
                    Y = t;
               } 
         }
        return dp.back();
    }
};

