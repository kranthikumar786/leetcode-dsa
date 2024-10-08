class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vdp = vector<vector<int>>(65, vector<int>(n, 0));
        for (auto x : piles) vsum.push_back(x + vsum.back());
        return dp(1, 0);
    }

    int dp(const int m, const int i) {
        if (i == n) return 0;
        if (vdp[m][i] > 0) return vdp[m][i];
        for (int x = 1; x <= 2 * m && i + x <= n; x++)
            vdp[m][i] = max(vdp[m][i], vsum[n] - vsum[i] - dp(max(m, x), i + x));
        return vdp[m][i];
    }

    int n;
    vector<vector<int>> vdp; 
    vector<int> vsum = { 0 };
};