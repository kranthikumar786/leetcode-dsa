class Solution {
    
    int countNeighbours(vector<vector<int>>& grid, int i,
                        int j, int m, int n) { 
        int c = 0;
        
        if (i > 0 && grid[i-1][j]) c++;
        if (i < m-1 && grid[i+1][j]) c++;
        if (j > 0 && grid[i][j-1]) c++;
        if (j < n-1 && grid[i][j+1]) c++;
        
        return 4-c;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans += countNeighbours(grid, i, j, m, n);     
                }
            }
        }
        
        return ans;
    }
};