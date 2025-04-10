class Solution {
public:
    int dp[20][2][20];  // [pos][tight][count of 1s]

    int dfs(string &num, int pos, bool tight, int count) {
        if (pos == num.size())
            return count;

        if (dp[pos][tight][count] != -1)
            return dp[pos][tight][count];

        int limit = tight ? num[pos] - '0' : 9;
        int res = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool newTight = tight && (digit == limit);
            int newCount = count + (digit == 1 ? 1 : 0);
            res += dfs(num, pos + 1, newTight, newCount);
        }

        return dp[pos][tight][count] = res;
    }

    int countDigitOne(int n) {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(num, 0, true, 0);
    }
};
