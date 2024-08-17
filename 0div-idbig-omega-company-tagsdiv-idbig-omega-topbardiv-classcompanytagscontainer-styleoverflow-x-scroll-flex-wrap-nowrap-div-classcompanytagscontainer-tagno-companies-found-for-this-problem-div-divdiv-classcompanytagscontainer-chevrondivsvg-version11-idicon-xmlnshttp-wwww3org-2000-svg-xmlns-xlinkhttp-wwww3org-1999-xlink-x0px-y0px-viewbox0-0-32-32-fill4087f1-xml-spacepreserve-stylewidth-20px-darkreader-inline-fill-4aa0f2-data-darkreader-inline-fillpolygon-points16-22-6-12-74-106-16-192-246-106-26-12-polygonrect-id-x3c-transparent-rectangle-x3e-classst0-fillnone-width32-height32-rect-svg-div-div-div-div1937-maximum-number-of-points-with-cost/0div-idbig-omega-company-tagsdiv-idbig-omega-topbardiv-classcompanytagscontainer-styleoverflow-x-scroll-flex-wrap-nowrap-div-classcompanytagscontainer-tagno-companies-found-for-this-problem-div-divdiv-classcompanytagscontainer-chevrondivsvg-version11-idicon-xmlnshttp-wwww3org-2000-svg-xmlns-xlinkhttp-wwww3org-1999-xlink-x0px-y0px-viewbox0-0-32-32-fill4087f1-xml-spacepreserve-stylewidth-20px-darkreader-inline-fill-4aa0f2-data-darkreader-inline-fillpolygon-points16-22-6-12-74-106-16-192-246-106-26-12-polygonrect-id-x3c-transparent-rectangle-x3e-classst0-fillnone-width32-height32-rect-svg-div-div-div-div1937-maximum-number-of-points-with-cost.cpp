class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size();
        int c = points[0].size();
        vector<long long> prev(c, 0);
        for (int j = 0; j < c; j++) {
            prev[j] = points[r - 1][j];
        }
        for (int i = r - 2; i >= 0; i--) {
            vector<long long> cur(c, 0);
            vector<long long> leftMax(c, 0);
            leftMax[0] = prev[0];
            for (int j = 1; j < c; j++) {
                leftMax[j] = max(leftMax[j - 1] - 1, prev[j]);
            }
            vector<long long> rightMax(c, 0);
            rightMax[c - 1] = prev[c - 1];
            for (int j = c - 2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j + 1] - 1, prev[j]);
            }

            for (int j = 0; j < c; j++) {
                cur[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }

            prev = cur;
        }

        return *max_element(prev.begin(), prev.end());
    }
};