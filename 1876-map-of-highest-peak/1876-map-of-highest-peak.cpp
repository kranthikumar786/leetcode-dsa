class Solution {
    bool isValid(int x, int y, int n, int m, vector<vector<bool>>& visited) {
        return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y];
    }
public:
    vector<int> dRow = {-1, 0, 1, 0};
    vector<int> dCol = {0, 1, 0, -1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> Ans(n, vector<int>(m, -1));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> queue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    Ans[i][j] = 0;
                    visited[i][j] = true;
                    queue.push({i, j});
                }
            }
        }
        int currLevel = 1;
        while (!queue.empty()) {
            int layerSize = queue.size();
            for (int i = 0; i < layerSize; i++) {
                auto [row, col] = queue.front();
                queue.pop();
                for (int j = 0; j < 4; j++) {
                    int neighRow = row + dRow[j];
                    int neighCol = col + dCol[j];
                    if (isValid(neighRow, neighCol, n, m, visited)) {
                        Ans[neighRow][neighCol] = currLevel;
                        visited[neighRow][neighCol] = true;
                        queue.push({neighRow, neighCol});
                    }
                }
            }
            currLevel++;
        }
        return Ans;
    }
};