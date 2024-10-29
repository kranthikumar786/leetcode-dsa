class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            grid[i][0] = -grid[i][0];
        int res = 0, moves[3][2] = {{0, -1}, {-1, -1}, {1, -1}};
        for (int c = 1; c < n; c++){
            bool found = false;
            for (int r = 0; r < m; r++){
                for (auto& move : moves){
                    int dr = r + move[0], dc = c + move[1];
                    if (dr >= 0 && dr < m && dc >= 0 && dc < n){
                        if (grid[dr][dc] < 0 && grid[r][c] > -grid[dr][dc]){
                            found = true;
                            grid[r][c] = -grid[r][c];
                            break;
                        }
                    }
                }
            }
            if (found) res++;
            else break;
        }
        return res;
    }
};