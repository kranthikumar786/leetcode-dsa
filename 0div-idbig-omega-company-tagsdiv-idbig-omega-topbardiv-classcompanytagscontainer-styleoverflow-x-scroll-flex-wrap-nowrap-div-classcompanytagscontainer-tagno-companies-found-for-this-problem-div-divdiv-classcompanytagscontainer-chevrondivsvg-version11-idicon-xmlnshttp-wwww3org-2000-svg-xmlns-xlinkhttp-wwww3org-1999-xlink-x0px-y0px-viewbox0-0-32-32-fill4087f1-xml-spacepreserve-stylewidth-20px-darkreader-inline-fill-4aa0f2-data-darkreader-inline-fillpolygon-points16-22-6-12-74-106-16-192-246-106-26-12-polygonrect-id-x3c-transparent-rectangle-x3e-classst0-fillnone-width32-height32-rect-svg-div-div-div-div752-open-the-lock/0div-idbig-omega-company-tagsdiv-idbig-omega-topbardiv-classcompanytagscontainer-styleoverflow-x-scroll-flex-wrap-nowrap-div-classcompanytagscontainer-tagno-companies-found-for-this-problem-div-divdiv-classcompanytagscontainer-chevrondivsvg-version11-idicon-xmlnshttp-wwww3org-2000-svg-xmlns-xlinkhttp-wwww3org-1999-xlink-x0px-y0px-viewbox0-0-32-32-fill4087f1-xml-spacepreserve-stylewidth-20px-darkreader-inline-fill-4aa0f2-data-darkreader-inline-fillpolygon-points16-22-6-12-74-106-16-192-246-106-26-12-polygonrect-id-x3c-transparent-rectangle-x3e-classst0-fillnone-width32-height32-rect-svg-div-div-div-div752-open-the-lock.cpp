class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    bool dp[10000] = {};
    for (auto &de : deadends)
        dp[stoi(de)] = true;
    if (dp[0])
        return -1;
    int res = 0, t = stoi(target);
    vector<int> q{0};
    while (!q.empty()) {
        vector<int> q1;
        for (auto dd : q) {
            if (dd == t)
                return res;
            for (auto p = 1; p < 10000; p *= 10) {
                auto d = dd / p % 10;
                for (auto dir = -1; dir <= 1; dir += 2) {
                    auto new_dd = dd - d * p + (10 + d + dir) % 10 * p;
                    if (!dp[new_dd]) {
                        dp[new_dd] = true;
                        q1.push_back(new_dd);
                    }
                }
            }
        }
        ++res;
        swap(q, q1);
    }
    return -1;
    }
};