class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), squares = 0;
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if (matrix[i-1][j-1] == 1) {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]});
                }
                squares += dp[i][j];
            }
        }
        
        return squares;
    }
};