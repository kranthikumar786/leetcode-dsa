class Solution {
    int solve(int index, int n, int absCount, int lateCount, vector<vector<vector<int>>>& dp) {
        const int MOD = 1e9 + 7;  
        if (index >= n) {
            return 1;
        }

        if (dp[index][absCount][lateCount] != -1) {
            return dp[index][absCount][lateCount];
        }

        int ans = 0;  
        if (absCount < 1) {
            ans = ((ans % MOD) + solve(index + 1, n, absCount + 1, 0, dp) % MOD) % MOD;
        }

        if (lateCount < 2) {
            ans = ((ans % MOD) + solve(index + 1, n, absCount, lateCount + 1, dp) % MOD) % MOD;
        }

        ans = ((ans % MOD) + solve(index + 1, n, absCount, 0, dp) % MOD) % MOD;

        return dp[index][absCount][lateCount] = ans;
    }
public:
    int checkRecord(int n) {
        int absCount=0;
        int lateCount=0;
        int index=0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(index,n,absCount,lateCount,dp);
        
    }
};