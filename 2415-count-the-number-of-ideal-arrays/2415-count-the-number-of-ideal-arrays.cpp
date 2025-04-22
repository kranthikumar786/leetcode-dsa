class Solution {
public:
    int idealArrays(int n, int m) {
        constexpr int MOD = 1e9 + 7;
        constexpr int MAX_LEN = 20;
        int dp[10005][MAX_LEN] = {};
        int comb[10005][MAX_LEN] = {};

        for (int i = 1; i <= m; ++i) {
            dp[i][1] = 1;
        }

        for (int len = 2; len < MAX_LEN; ++len) {
            for (int i = 1; i <= m; ++i) {
                if (dp[i][len - 1] == 0) continue;
                for (int j = i + i; j <= m; j += i) {
                    dp[j][len] = (dp[j][len] + dp[i][len - 1]) % MOD;
                }
            }
        }

        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_LEN - 1); ++j) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        long long result = 0;
        for (int val = 1; val <= m; ++val) {
            for (int len = 1; len < MAX_LEN; ++len) {
                if (dp[val][len]) {
                    result = (result + 1LL * dp[val][len] * comb[n - 1][len - 1] % MOD) % MOD;
                }
            }
        }

        return result;
    }
};
