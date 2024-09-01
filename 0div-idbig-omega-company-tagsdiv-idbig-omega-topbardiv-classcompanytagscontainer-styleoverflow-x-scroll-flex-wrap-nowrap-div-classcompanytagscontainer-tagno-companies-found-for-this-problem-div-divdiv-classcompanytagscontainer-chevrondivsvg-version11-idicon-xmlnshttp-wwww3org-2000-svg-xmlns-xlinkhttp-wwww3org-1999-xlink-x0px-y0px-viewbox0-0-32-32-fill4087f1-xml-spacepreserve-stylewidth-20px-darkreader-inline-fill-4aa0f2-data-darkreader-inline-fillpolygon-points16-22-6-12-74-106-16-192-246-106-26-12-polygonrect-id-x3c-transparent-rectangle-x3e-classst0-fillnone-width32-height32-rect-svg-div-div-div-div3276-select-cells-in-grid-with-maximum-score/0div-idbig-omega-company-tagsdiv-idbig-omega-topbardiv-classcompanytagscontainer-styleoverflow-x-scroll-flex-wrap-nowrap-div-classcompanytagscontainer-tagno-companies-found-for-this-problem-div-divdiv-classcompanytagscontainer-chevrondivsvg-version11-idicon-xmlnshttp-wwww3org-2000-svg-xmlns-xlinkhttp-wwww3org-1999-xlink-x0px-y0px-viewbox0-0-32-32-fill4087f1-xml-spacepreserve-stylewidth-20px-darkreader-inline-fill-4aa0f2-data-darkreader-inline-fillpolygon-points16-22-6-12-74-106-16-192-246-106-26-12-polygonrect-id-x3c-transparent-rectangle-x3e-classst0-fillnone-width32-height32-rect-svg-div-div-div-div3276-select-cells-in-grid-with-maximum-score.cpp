class Solution {
public:
  
    vector<vector<int>>a;
    vector<vector<int>>dp;
    int calc(int n , int mask) {
        if(n ==0 ) return 0;
        if(dp[n][mask] != -1) {return dp[n][mask];}
        int ans = calc(n-1,mask);
        for(auto x : a[n]){
            if(mask & (1<<x)) continue;
            ans =max(ans, n + calc(n-1,mask | 1<<x));
        }
        return dp[n][mask] = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(101,vector<int>(1<<n,-1));
        a.resize(101,vector<int>());
        int maxi = 0;
        for(int i = 0; i < n ; i++) {
              for(int j = 0 ;j < m; j++) {
                  a[grid[i][j]].push_back(i);
                  maxi = max(maxi, grid[i][j]);
              }
        }
        return calc(maxi,0);
    }
};