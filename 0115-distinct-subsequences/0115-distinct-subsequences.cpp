class Solution {
public:

  int numberOfDistinctSubsequences(int indexi, int indexj, string s, string t, vector<vector<int>>& dp) {
  
    if( indexj == -1 ) {
         return 1;
    }
    if( indexi == -1 ) {
        return 0;
    }

      if(dp[indexi][indexj] != -1) {
          return dp[indexi][indexj];
      }

      
    if(s[indexi] == t[indexj]) {
        return dp[indexi][indexj] =  numberOfDistinctSubsequences(indexi -1 ,indexj -1, s, t, dp) + numberOfDistinctSubsequences(indexi - 1 , indexj ,s, t, dp);
    }
    return  dp[indexi][indexj] = numberOfDistinctSubsequences(indexi - 1 ,indexj ,s, t, dp);

  }

    int numDistinct(string s, string t) {
        int n = s.size()-1;
        int m = t.size()-1;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return numberOfDistinctSubsequences(n, m, s, t, dp);
    }
};

/*

Time Limit Exceeded
50 / 65 testcases passed
*/