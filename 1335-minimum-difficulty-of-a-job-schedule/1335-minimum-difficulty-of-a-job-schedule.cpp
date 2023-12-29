class Solution {
public:
    int dp[301][11]; 
    int solve(vector<int>& v, int n, int i, int d) {
        if (d == 1) return *max_element(v.begin() + i, v.end()); 

        if (dp[i][d] != -1) return dp[i][d]; 

        int ans = INT_MAX;
        int currmax = INT_MIN;

        for (int j = i; j <= n - d; j++) {
            currmax = max(currmax, v[j]);
            ans = min(ans, currmax + solve(v, n, j + 1, d - 1)); 
        }

        dp[i][d] = ans; 
        return dp[i][d]; 
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp)); 
        int n = jobDifficulty.size();
        if (n < d) return -1; 
        return solve(jobDifficulty, n, 0, d); 
    }
};