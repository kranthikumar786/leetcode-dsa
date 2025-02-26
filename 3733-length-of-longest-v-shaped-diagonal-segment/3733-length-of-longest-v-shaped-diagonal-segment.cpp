class Solution {
public:
    int n, m;

    int solve(int r, int c, int turn, int curr, int dir, vector<vector<int>>& grid) {
        if (r < 0 || r >= n || c < 0 || c >= m) return 0;

        if (curr && grid[r][c] != 2) return 0;
        if (!curr && grid[r][c] != 0) return 0;

        int ans = 0;
        // 1 - top right, 2 - bottom right, 3 - bottom left, 4 - top left
        if (dir == 1) {
            ans = 1 + solve(r - 1, c + 1, turn, !curr, 1, grid);
            if (!turn) ans = max(ans, 1 + solve(r + 1, c + 1, 1, !curr, 2, grid));
        } else if (dir == 2) {
            ans = 1 + solve(r + 1, c + 1, turn, !curr, 2, grid);
            if (!turn) ans = max(ans, 1 + solve(r + 1, c - 1, 1, !curr, 3, grid));
        } else if (dir == 3) {
            ans = 1 + solve(r + 1, c - 1, turn, !curr, 3, grid);
            if (!turn) ans = max(ans, 1 + solve(r - 1, c - 1, 1, !curr, 4, grid));
        } else if (dir == 4) {
            ans = 1 + solve(r - 1, c - 1, turn, !curr, 4, grid);
            if (!turn) ans = max(ans, 1 + solve(r - 1, c + 1, 1, !curr, 1, grid));
        }

        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, 1 + solve(i + 1, j + 1, 0, 1, 2, grid));
                    ans = max(ans, 1 + solve(i - 1, j + 1, 0, 1, 1, grid));
                    ans = max(ans, 1 + solve(i + 1, j - 1, 0, 1, 3, grid));
                    ans = max(ans, 1 + solve(i - 1, j - 1, 0, 1, 4, grid));
                }
            }
        }
        return ans;
    }
};